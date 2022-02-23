#include "DIPs.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


/* Example of DIP */
/* age the image to make it look like old picture */
IMAGE *Aging(IMAGE *image)
{
    int x, y;
    int h = ImageHeight(image);
    int w = ImageWidth(image);
    for( y = 0; y < h; y++ ) {
        for( x = 0; x < w; x++ ) {
	    SetPixelB(image, x, y, ((GetPixelR(image, x, y) + GetPixelG(image, x, y) + GetPixelB(image,x,y)) / 5));
	    SetPixelR(image, x, y, ((unsigned char)(GetPixelB(image, x, y)*1.6)));
            SetPixelG(image, x, y, ((unsigned char)(GetPixelB(image, x, y)*1.6)));
	}
    }
    return image;
}

// Sharpen function
IMAGE *Sharpen(IMAGE *image)
{
    int x, y;
    int tmpr = 0, tmpg = 0, tmpb = 0;

    // Creating a temporary image to copy the original image from:
    IMAGE *temp;
    temp = malloc(sizeof(IMAGE));
    temp->W = ImageWidth(image);
    temp->H = ImageHeight(image);
    temp->R = malloc(sizeof(unsigned char)*ImageHeight(image)*ImageWidth(image));
    temp->G = malloc(sizeof(unsigned char)*ImageHeight(image)*ImageWidth(image));
    temp->B = malloc(sizeof(unsigned char)*ImageHeight(image)*ImageWidth(image));

    for (x = 0; x < ImageWidth(image); x++)
    {   for(y = 0; y < ImageHeight(image); y++)
        {   
	    SetPixelR(temp, x, y, (GetPixelR(image, x, y)));
	    SetPixelG(temp, x, y, (GetPixelG(image, x, y)));
	    SetPixelB(temp, x, y, (GetPixelB(image, x, y)));            
            
        }
    }
    for (x = 1; x < ImageWidth(image) - 1; x++)
    {   for (y = 1; y < ImageHeight(image)- 1; y++)
        {   
	    tmpr = (9 * GetPixelR(image,x,y)) - GetPixelR(image, x-1, y-1) - GetPixelR(image, x-1,y) - GetPixelR(image, x-1, y+1) - GetPixelR(image, x, y-1) - GetPixelR(image, x, y+1) - GetPixelR(image, x+1, y-1) - GetPixelR(image, x+1, y) - GetPixelR(image, x+1, y+1);
            tmpg = (9 * GetPixelG(image,x,y)) - GetPixelG(image, x-1, y-1) - GetPixelG(image, x-1,y) - GetPixelG(image, x-1, y+1) - GetPixelG(image, x, y-1) - GetPixelG(image, x, y+1) - GetPixelG(image, x+1, y-1) - GetPixelG(image, x+1, y) - GetPixelG(image, x+1, y+1);
	    tmpb = (9 * GetPixelB(image,x,y)) - GetPixelB(image, x-1, y-1) - GetPixelB(image, x-1,y) - GetPixelB(image, x-1, y+1) - GetPixelB(image, x, y-1) - GetPixelB(image, x, y+1) - GetPixelB(image, x+1, y-1) - GetPixelB(image, x+1, y) - GetPixelB(image, x+1, y+1);

	    SetPixelR(temp, x, y, (tmpr > 255)?255:(tmpr<0)?0:tmpr);
            SetPixelG(temp, x, y, (tmpg > 255)?255:(tmpg<0)?0:tmpg);
            SetPixelB(temp, x, y, (tmpb > 255)?255:(tmpb<0)?0:tmpb);
            tmpr = tmpg = tmpb = 0;
        }
    }
    // Copy back to original image
    for (x = 0; x < WIDTH; x++)
    {   for(y = 0; y < HEIGHT; y++)
        {
            SetPixelR(image, x, y, (GetPixelR(temp, x, y)));
	    SetPixelG(image, x, y, (GetPixelG(temp, x, y)));
	    SetPixelB(image, x, y, (GetPixelB(temp, x, y)));
        }
    }
    DeleteImage(temp);
    return image;
}


// edge detection function
IMAGE *Edge(IMAGE *image)
{   
    int             x, y, m, n, a, b;
    // Creating a temporary image to copy the original image from:
    IMAGE *temp;
    temp = malloc(sizeof(IMAGE));
    temp->W = ImageWidth(image);
    temp->H = ImageHeight(image);
    temp->R = malloc(sizeof(unsigned char)*ImageHeight(image)*ImageWidth(image));
    temp->G = malloc(sizeof(unsigned char)*ImageHeight(image)*ImageWidth(image));
    temp->B = malloc(sizeof(unsigned char)*ImageHeight(image)*ImageWidth(image));

    for (x = 0; x < ImageWidth(image); x++)
    {   for(y = 0; y < ImageHeight(image); y++)
        {   
	    SetPixelR(temp, x, y, (GetPixelR(image, x, y)));
	    SetPixelG(temp, x, y, (GetPixelG(image, x, y)));
	    SetPixelB(temp, x, y, (GetPixelB(image, x, y)));            
            
        }
    }

    int sumR = 0;    /* sum of the intensity differences with neighbors */
    int sumG = 0;
    int sumB = 0;

    for (y = 1; y < ImageHeight(image) - 1; y++){
        for (x = 1; x < ImageWidth(image) - 1; x++){
            for (n = -1; n <= 1; n++){
                for (m = -1; m <= 1; m++) {
                    a = (x + m >= ImageWidth(image)) ? ImageWidth(image) - 1 : (x + m < 0) ? 0 : x + m;
                    b = (y + n >= ImageHeight(image)) ? ImageHeight(image) - 1 : (y + n < 0) ? 0 : y + n;
                    sumR += (GetPixelR(temp, x, y) - GetPixelR(temp, a, b));
                    sumG += (GetPixelG(temp, x, y) - GetPixelG(temp, a, b));
                    sumB += (GetPixelB(temp, x, y) - GetPixelB(temp, a, b));
                }
            }
            SetPixelR(image, x, y, (sumR > MAX_PIXEL) ? MAX_PIXEL: (sumR < MIN_PIXEL) ? MIN_PIXEL: sumR);
            SetPixelG(image, x, y, (sumG > MAX_PIXEL) ? MAX_PIXEL: (sumG < MIN_PIXEL) ? MIN_PIXEL: sumG);
            SetPixelB(image, x, y, (sumB > MAX_PIXEL) ? MAX_PIXEL: (sumB < MIN_PIXEL) ? MIN_PIXEL: sumB);
            sumR = sumG = sumB = 0;
        }
    }

    /* set all four borders to 0 */

    for (y = 0; y < ImageHeight(image); y++) {
        SetPixelR(image, 0, y, 0);
        SetPixelG(image, 0, y, 0);
        SetPixelB(image, 0, y, 0);
        SetPixelR(image, ImageWidth(image)-1, y, 0);
        SetPixelG(image, ImageWidth(image)-1, y, 0);
        SetPixelB(image, ImageWidth(image)-1, y, 0);
    }
    for (x = 0; x < ImageWidth(image); x++) {
	SetPixelR(image, x, 0, 0);
        SetPixelG(image, x, 0, 0);
        SetPixelB(image, x, 0, 0);
        SetPixelR(image, x, ImageHeight(image)-1, 0);
        SetPixelG(image, x, ImageHeight(image)-1, 0);
        SetPixelB(image, x, ImageHeight(image)-1, 0);
    }
    DeleteImage(temp);
    return image;
} 

/* vim: set tabstop=8 softtabstop=8 shiftwidth=8 noexpandtab : */
