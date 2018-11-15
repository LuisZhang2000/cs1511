// Assignment 1 Mandelbrot: Mandelbrot generation functions
// mandelbrot.c
//
// Completed by
// Luis Zhang (z5205864)
//
// Modified on 2018-09-09
// Andrew Bennett (wed11-strings)
//
// Version 1.0.2: Fix minor typos in comments.
// Version 1.0.1: Fix issues with spacing and indentation.
// Version 1.0.0: Assignment released.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Add your own #includes here

#include "mandelbrot.h"
#include "pixelColor.h"

// Add your own #defines here

#define MAX_STEPS 256
#define TILE_SIZE 512

// Add your own function prototypes here

//pixel colourPixel(void);
//pixel makePixel(color red, color green, color blue);

// Take a pixel grid and and the path from the web browser used to
// request the 'tile'.
//
// The requestPath will be in the form "/mandelbrot/2/{zoom}/{x}/{y}.bmp".
// In the query, 'x' and 'y' are decimals and describe the 'center' of the
// tile and need to be converted into a complex number.
// 'zoom' is an integer representing the zoom level for the tile.
void serveMandelbrot(
    struct pixel pixels[TILE_SIZE][TILE_SIZE],
    char *requestPath
) {
    struct complex center = {0.0, 0.0};
    int z = 7;

    sscanf(
        requestPath,
        "/mandelbrot/2/%d/%lf/%lf.bmp",
        &z, &center.re, &center.im
    );

    // Use drawMandelbrot to draw the image.
    drawMandelbrot(pixels, center, z);
}

// Draw a single Mandelbrot tile, by calculating and colouring each of
// the pixels in the tile.
//
// Your function "returns" this tile by filling in the `pixels` 2D array
// that is passed in to your function.
//
// The `pixels` array is TILE_SIZE high and TILE_SIZE wide.
// The bottom left corner of the image is pixels[0][0].
//
// `center` is a complex number, representing the center of the tile.
// `z` is used to calculate the distance between each pixel in the image.
// Each pixel is 2^(-z) apart from each other.
void drawMandelbrot(
    struct pixel pixels[TILE_SIZE][TILE_SIZE],
    struct complex center,
    int z
) {   
    // setting distance between each pixel to be 2^-z
    double distance = pow(2,-z);  
    double left_bottom_re = center.re - (distance*(TILE_SIZE-1)/2);
    double left_bottom_im = center.im - (distance*(TILE_SIZE-1)/2);
    
    struct complex c1;
    
    int i = 0;
    while (i < TILE_SIZE) {
        c1.im = left_bottom_im + i * distance;
        int j = 0;
        while (j < TILE_SIZE) {
            // start from the bottom row and work towards pixel to the right 
            // and fill with colour from pixelColor.c until end of the row has 
            // been reached, then go up a row and repeat process until 
            // uppermost row has been completed
            c1.re = left_bottom_re + j * distance;
            pixels[i][j] = pixelColor(escapeSteps(c1));
            
            j++;
        }
        i++;
    
    }
}       
   

// Determine the number of steps required to escape the Mandelbrot set,
// for the given complex number `c`.
int escapeSteps(struct complex c) {
    int steps = 0;

    // declare and initialise variables
    
    double wX = 0;
    double wY = 0;
    double tempX;
    
    // while steps is less than 256 and satisfies the formula,
    // keep incrementing steps and return number of steps it took
    // the given complex number to escape the mandelbrot set
    
    while ((steps < MAX_STEPS) && (wX * wX + wY * wY < 4)) {
        tempX = (wX * wX - wY * wY) + c.re;
        wY = (2 * wX * wY) + c.im;
        wX = tempX;
    
        steps++;
    }

    return steps;
}
