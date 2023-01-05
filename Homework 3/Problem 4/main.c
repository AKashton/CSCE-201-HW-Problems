/////////////////////////////////////////////////////////////////// 
// CSCE A201
// Ashton Curry
// Date: 4/8/2022
// Problem 4: ACII Rendering
// Purpose: Create a ASCII image
///////////////////////////////////////////////////////////////////
#include "stdio.h"
#include "bmp.h"
#include "math.h"
#define _CRT_SECURE_NO_WARNINGS
// Demo main program that dims the image

int main()
{
    byte* pixels = NULL;
    int32 width;
    int32 height;
    int32 bytesPerPixel;
    char* brightness = " _.,-=+:;cba!?0123456789$W#@N"; //brightness array
    readImage("dog.bmp", &pixels, &width, &height, &bytesPerPixel);
    for (int i = 0; i < height; i += 8) // iterates through sections of 8 rows 
    {
        for (int j = 0; j < width ; j += 5) //iterates through sections of 5 columns
        {
            double avgColor = 0; // gets the average color for each average pixel and sums them together.
            for (int y = i; y < i + 8 && y < height; y++) //iterate through each pixel on the row from y to y + 8
            {
                for (int x = j; x < j + 5 && x < width; x++) //iterates through each pixel on the column from x to x + 5
                {
                     
                    {
                        byte r, g, b;
                        getPixel(x, y, pixels, width, height, bytesPerPixel, &r, &g, &b);
                        avgColor += ((r + b + g) / 3); //average of each pixel grayscale
                    }
                }
                
            }
            double avgGrayScale = avgColor / 40.0; //takes average of 40 pixels grayscale 
            int charASCII = round(avgGrayScale / 9.107); //averages the pixels out across the 29 characters in the brightness array
            printf("%c", brightness[charASCII]); //assigns the integer calculated to the array and prints it out. 
        }
        printf("\n");
    }
    free(pixels);
    return(0);
}