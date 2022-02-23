#include "Advanced.h"


#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/* Add noise to an image */
IMAGE *Noise(int n, IMAGE *image)
{
	int x, y, i;
	int num; /* number of noise added */
	num = ( n*ImageHeight(image)*ImageWidth(image) )/100;
	srand(time(NULL));

	for ( i = 0; i < num; i++ ) {
		x = ( (double)rand()/RAND_MAX )*(ImageWidth(image)-1);
		y = ( (double)rand()/RAND_MAX )*(ImageHeight(image)-1);
		SetPixelR(image, x, y, 255);
		SetPixelG(image, x, y, 255);
		SetPixelB(image, x, y, 255);
	}
	return image;
}

/* make the image posterized */
IMAGE *Posterize(IMAGE *image, unsigned int rbits, unsigned int gbits, unsigned int bbits)
{
	int x, y;
	for(x=0; x<ImageWidth(image); x++) {
		for(y=0; y<ImageHeight(image); y++) {
			unsigned char one = 1;
			int i;
			for(i=0; i<rbits-1; i++) {
				SetPixelR(image, x, y, (GetPixelR(image, x, y) | one));
				one <<= 1;
			}
			one = ~one;
			SetPixelR(image, x, y, (GetPixelR(image, x, y) & one));

			one = 1;
			for(i=0; i<gbits-1; i++) {
				SetPixelG(image, x, y, (GetPixelG(image, x, y) | one));
				one <<= 1;
			}
			one = ~one;
			SetPixelG(image, x, y, (GetPixelG(image, x, y) & one));

			one = 1;
			for(i=0; i<bbits-1; i++) {
				SetPixelB(image, x, y, (GetPixelB(image, x, y) | one));
				one <<= 1;
			}
			one = ~one;
			SetPixelB(image, x, y, (GetPixelB(image, x, y) & one));
		}
	}
	return image;
}

// Negative Filter
IMAGE *NegativeFilter(IMAGE *image)
{
	for (int x = 0; x < ImageWidth(image); x++)
	{
		for (int y = 0; y < ImageHeight(image); y++)
		{
			SetPixelR(image, x, y, 255-GetPixelR(image, x, y));
			SetPixelG(image, x, y, 255-GetPixelG(image, x, y));
			SetPixelB(image, x, y, 255-GetPixelB(image, x, y));		
		}
	}
	return image;
}

IMAGE *Enlarge(IMAGE *image, int enlarge_percentage){
	// Allocating and creating a pointer to a temp image
	IMAGE *temp;
	temp = malloc(sizeof(IMAGE));
	temp->W = ImageWidth(image)*(enlarge_percentage/100.00);
	temp->H = ImageHeight(image)*(enlarge_percentage/100.00);
	temp->R = malloc(sizeof(unsigned char)*ImageWidth(temp)*ImageHeight(temp));
	temp->G = malloc(sizeof(unsigned char)*ImageWidth(temp)*ImageHeight(temp));
	temp->B = malloc(sizeof(unsigned char)*ImageWidth(temp)*ImageHeight(temp));
	// Copy pixels and enlarge it
	for(int x = 0; x < ImageWidth(temp); x++){
		for(int y = 0; y < ImageHeight(temp); y++){
			SetPixelR(temp, x, y, GetPixelR(image, x/(enlarge_percentage/100.00), y/(enlarge_percentage/100.00)));
			SetPixelG(temp, x, y, GetPixelG(image, x/(enlarge_percentage/100.00), y/(enlarge_percentage/100.00)));
			SetPixelB(temp, x, y, GetPixelB(image, x/(enlarge_percentage/100.00), y/(enlarge_percentage/100.00))); 
		}
	}
	DeleteImage(image);
	return temp;
}

IMAGE *Square(IMAGE *image, int x_offset, int y_offset, int square_size){
	// Create and allocate temp image
	IMAGE *temp;
	temp = malloc(sizeof(IMAGE));
	temp->W = square_size;
	temp->H = square_size;
	temp->R = malloc(sizeof(unsigned char)*ImageWidth(temp)*ImageHeight(temp));
	temp->G = malloc(sizeof(unsigned char)*ImageWidth(temp)*ImageHeight(temp));
	temp->B = malloc(sizeof(unsigned char)*ImageWidth(temp)*ImageHeight(temp));
	for(int x = 0; x < ImageWidth(temp); x++){
		for(int y = 0; y < ImageHeight(temp); y++){
			SetPixelR(temp, x, y, GetPixelR(image, x+x_offset, y+y_offset));
			SetPixelG(temp, x, y, GetPixelG(image, x+x_offset, y+y_offset));
			SetPixelB(temp, x, y, GetPixelB(image, x+x_offset, y+y_offset));
		}
	}
	DeleteImage(image);
	return temp;

}

IMAGE *BrightnessandContrast(IMAGE *image, int brightness, int contrast){
	double factor;
	int tmpr = 0, tmpg = 0, tmpb = 0;
	for(int x = 0; x < ImageWidth(image); x++){
		for(int y = 0; y < ImageHeight(image); y++){
			tmpr = GetPixelR(image, x, y)+brightness;
			tmpg = GetPixelG(image, x, y)+brightness;
			tmpb = GetPixelB(image, x, y)+brightness;
			tmpr = (unsigned char)((tmpr>255)?255:(tmpr<0)?0:tmpr);
			tmpg = (unsigned char)((tmpg>255)?255:(tmpg<0)?0:tmpg);
			tmpb = (unsigned char)((tmpb>255)?255:(tmpb<0)?0:tmpb);
			SetPixelR(image, x, y, tmpr);
			SetPixelG(image, x, y, tmpg);
			SetPixelB(image, x, y, tmpb);
			// Resetting temp bits
			tmpr = tmpg = tmpb = 0;		
		}
	}
	// Calculating factor 
	factor = (double)(259*(contrast+255)) / (double)(255*(259-contrast));
	
	for(int x = 0; x < ImageWidth(image); x++){
		for(int y = 0; y < ImageHeight(image); y++){
			tmpr = (int)(factor*(GetPixelR(image, x, y)-128)+128);
			tmpg = (int)(factor*(GetPixelG(image, x, y)-128)+128);
			tmpb = (int)(factor*(GetPixelB(image, x, y)-128)+128);
			SetPixelR(image, x, y, (tmpr>255)?255:(tmpr<0)?0:tmpr);
			SetPixelG(image, x, y, (tmpg>255)?255:(tmpg<0)?0:tmpg);
			SetPixelB(image, x, y, (tmpb>255)?255:(tmpb<0)?0:tmpb);
			// Resetting tmp bits
			tmpr = tmpg = tmpb = 0;
		}
	}
	return image;
}

/* vim: set tabstop=8 softtabstop=8 shiftwidth=8 noexpandtab : */
