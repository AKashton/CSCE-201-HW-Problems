#pragma once
// This code based on this article by Alejandro Rodriguez
// See https://elcharolin.wordpress.com/2018/11/28/read-and-write-bmp-files-in-c-c/
// If compiling manually in linux, you must link with the -lm option for math,
// e.g  gcc *.c -lm
//
// This opens BMP v5 files b.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DATA_OFFSET_OFFSET 0x000A
#define WIDTH_OFFSET 0x0012
#define HEIGHT_OFFSET 0x0016
#define BITS_PER_PIXEL_OFFSET 0x001C
#define HEADER_SIZE 14
#define INFO_HEADER_SIZE 40
#define NO_COMPRESION 0
#define MAX_NUMBER_OF_COLORS 0
#define ALL_COLORS_REQUIRED 0

typedef unsigned int int32;
typedef short int16;
typedef unsigned char byte;

// Reads a bitmap from disk
void readImage(const char* fileName, byte** pixels, int32* width, int32* height, int32* bytesPerPixel);

// Writes a bitmap to disk
void writeImage(const char* fileName, byte* pixels, int32 width, int32 height, int32 bytesPerPixel);

// Retrieve the RGB values from a pixel in the image
void getPixel(int x, int y, byte* pixels, int32 width, int32 height, int32 bytesPerPixel,
    byte* r, byte* g, byte* b);

// Change the RGB values of a pixel in the image
void setPixel(int x, int y, byte* pixels, int32 width, int32 height, int32 bytesPerPixel,
    byte r, byte g, byte b);