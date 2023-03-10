#define _CRT_SECURE_NO_WARNINGS
// This code based on this article by Alejandro Rodriguez
// See https://elcharolin.wordpress.com/2018/11/28/read-and-write-bmp-files-in-c-c/
// If compiling manually in linux, you must link with the -lm option for math,
// e.g  gcc *.c -lm
//
// This opens BMP v5 files without compression.

#include "bmp.h"

//***Inputs*****
//fileName: The name of the file to open 
//***Outputs****
//pixels: A pointer to a byte array. This will contain the pixel data
//width: An int pointer to store the width of the image in pixels
//height: An int pointer to store the height of the image in pixels
//bytesPerPixel: An int pointer to store the number of bytes per pixel that are used in the image
void readImage(const char* fileName, byte** pixels, int32* width, int32* height, int32* bytesPerPixel)
{
    //Open the file for reading in binary mode
    FILE* imageFile = fopen(fileName, "rb");
    //Read data offset
    int32 dataOffset;
    fseek(imageFile, DATA_OFFSET_OFFSET, SEEK_SET);
    fread(&dataOffset, 4, 1, imageFile);
    //Read width
    fseek(imageFile, WIDTH_OFFSET, SEEK_SET);
    fread(width, 4, 1, imageFile);
    //Read height
    fseek(imageFile, HEIGHT_OFFSET, SEEK_SET);
    fread(height, 4, 1, imageFile);
    // If negative, a format error, so exit
    if ((width < 0) || (height < 0))
    {
        printf("Error: image format not recognized.\n");
        return;
    }
    //Read bits per pixel
    int16 bitsPerPixel;
    fseek(imageFile, BITS_PER_PIXEL_OFFSET, SEEK_SET);
    fread(&bitsPerPixel, 2, 1, imageFile);
    //Allocate a pixel array
    *bytesPerPixel = ((int32)bitsPerPixel) / 8;

    //Rows are stored bottom-up
    //Each row is padded to be a multiple of 4 bytes. 
    //We calculate the padded row size in bytes
    int paddedRowSize = (int)(4 * ceil((float)(*width) / 4.0f)) * (*bytesPerPixel);
    //We are not interested in the padded bytes, so we allocate memory just for
    //the pixel data
    int unpaddedRowSize = (*width) * (*bytesPerPixel);
    //Total size of the pixel data in bytes
    int totalSize = unpaddedRowSize * (*height);
    *pixels = (byte*)malloc(totalSize);
    //Read the pixel data Row by Row.
    //Data is padded and stored bottom-up
    int i = 0;
    //point to the last row of our pixel array (unpadded)
    byte* currentRowPointer = *pixels + ((*height - 1) * unpaddedRowSize);
    for (i = 0; i < *height; i++)
    {
        //put file cursor in the next row from top to bottom
        fseek(imageFile, dataOffset + (i * paddedRowSize), SEEK_SET);
        //read only unpaddedRowSize bytes (we can ignore the padding bytes)
        fread(currentRowPointer, 1, unpaddedRowSize, imageFile);
        //point to the next row (from bottom to top)
        currentRowPointer -= unpaddedRowSize;
    }

    fclose(imageFile);
}

//***Inputs*****
//fileName: The name of the file to save 
//pixels: Pointer to the pixel data array
//width: The width of the image in pixels
//height: The height of the image in pixels
//bytesPerPixel: The number of bytes per pixel that are used in the image
void writeImage(const char* fileName, byte* pixels, int32 width, int32 height, int32 bytesPerPixel)
{
    //Open file in binary mode
    FILE* outputFile = fopen(fileName, "wb");
    //*****HEADER************//
    //write signature
    const char* BM = "BM";
    fwrite(&BM[0], 1, 1, outputFile);
    fwrite(&BM[1], 1, 1, outputFile);
    //Write file size considering padded bytes
    int paddedRowSize = (int)(4 * ceil((float)width / 4.0f)) * bytesPerPixel;
    int32 fileSize = paddedRowSize * height + HEADER_SIZE + INFO_HEADER_SIZE;
    fwrite(&fileSize, 4, 1, outputFile);
    //Write reserved
    int32 reserved = 0x0000;
    fwrite(&reserved, 4, 1, outputFile);
    //Write data offset
    int32 dataOffset = HEADER_SIZE + INFO_HEADER_SIZE;
    fwrite(&dataOffset, 4, 1, outputFile);

    //*******INFO*HEADER******//
    //Write size
    int32 infoHeaderSize = INFO_HEADER_SIZE;
    fwrite(&infoHeaderSize, 4, 1, outputFile);
    //Write width and height
    fwrite(&width, 4, 1, outputFile);
    fwrite(&height, 4, 1, outputFile);
    //Write planes
    int16 planes = 1; //always 1
    fwrite(&planes, 2, 1, outputFile);
    //write bits per pixel
    int16 bitsPerPixel = bytesPerPixel * 8;
    fwrite(&bitsPerPixel, 2, 1, outputFile);
    //write compression
    int32 compression = NO_COMPRESION;
    fwrite(&compression, 4, 1, outputFile);
    //write image size (in bytes)
    int32 imageSize = width * height * bytesPerPixel;
    fwrite(&imageSize, 4, 1, outputFile);
    //write resolution (in pixels per meter)
    int32 resolutionX = 11811; //300 dpi
    int32 resolutionY = 11811; //300 dpi
    fwrite(&resolutionX, 4, 1, outputFile);
    fwrite(&resolutionY, 4, 1, outputFile);
    //write colors used 
    int32 colorsUsed = MAX_NUMBER_OF_COLORS;
    fwrite(&colorsUsed, 4, 1, outputFile);
    //Write important colors
    int32 importantColors = ALL_COLORS_REQUIRED;
    fwrite(&importantColors, 4, 1, outputFile);
    //write data
    int i = 0;
    int unpaddedRowSize = width * bytesPerPixel;
    for (i = 0; i < height; i++)
    {
        //start writing from the beginning of last row in the pixel array
        int pixelOffset = ((height - i) - 1) * unpaddedRowSize;
        fwrite(&pixels[pixelOffset], 1, paddedRowSize, outputFile);
    }
    fclose(outputFile);
}

//***Inputs*****
//x: An int that is the x coordinate of the pixel we want to retrieve
//y: An int that is the y coordinate of the pixel we want to retrieve
//pixels: A pointer to a byte array containing the pixel data
//width: An int that is the width of the image in pixels
//height: An int that is the height of the image in pixels
//bytesPerPixel: An int that is the number of bytes per pixel that are used in the image
//***Outputs****
//r: A pointer to a byte that will store the red component of the pixel at coord (x,y)
//g: A pointer to a byte that will store the green component of the pixel at coord (x,y)
//b: A pointer to a byte that will store the blue component of the pixel at coord (x,y)
void getPixel(int x, int y, byte* pixels, int32 width, int32 height, int32 bytesPerPixel,
    byte* r, byte* g, byte* b)
{
    // Check if coordinates would exceed bounds of pixel array
    if ((x < 0) || (y < 0) || ((y * width + x) > width * height))
    {
        printf("Error: requested pixel index out of bounds\n");
        // Return black pixel by default if requested pixel not possible to return
        *b = 0;
        *g = 0;
        *r = 0;
        return;
    }
    // Pixels are in reverse bgr order at subsequent offsets
    *b = pixels[bytesPerPixel * ((y * width) + x)];
    *g = pixels[bytesPerPixel * ((y * width) + x) + 1];
    *r = pixels[bytesPerPixel * ((y * width) + x) + 2];
}


//***Inputs*****
//x: An int that is the x coordinate of the pixel we want to set
//y: An int that is the y coordinate of the pixel we want to set
//pixels: A pointer to a byte array containing the pixel data
//width: An int that is the width of the image in pixels
//height: An int that is the height of the image in pixels
//bytesPerPixel: An int that is the number of bytes per pixel that are used in the image
//r: A byte that will store the red component of the pixel at coord (x,y)
//g: A byte that will store the green component of the pixel at coord (x,y)
//b: A byte that will store the blue component of the pixel at coord (x,y)
//***Outputs****
//pixels: The pixel corresponding to coordinate (x,y) is changed to the input rgb
void setPixel(int x, int y, byte* pixels, int32 width, int32 height, int32 bytesPerPixel,
    byte r, byte g, byte b)
{
    // Check if coordinates would exceed bounds of pixel array
    if ((x < 0) || (y < 0) || ((y * width + x) > width * height))
    {
        printf("Error: requested pixel index out of bounds\n");
        return;
    }
    // Pixels are in reverse bgr order at subsequent offsets
    pixels[bytesPerPixel * ((y * width) + x)] = b;
    pixels[bytesPerPixel * ((y * width) + x) + 1] = g;
    pixels[bytesPerPixel * ((y * width) + x) + 2] = r;
}