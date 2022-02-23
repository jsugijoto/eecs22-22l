/* Image.c File */
/* Name Jonathan Sugijoto */
/* ID: 58535060 */

#include "Image.h"

/* Get the R intensity of pixel (x, y) in image */
unsigned char GetPixelR(const IMAGE *image, unsigned int x,  unsigned int y){
	assert(image);
	return *(image->R+x+y*ImageWidth(image));		
}

/* Get the G intensity of pixel (x, y) in image */
unsigned char GetPixelG(const IMAGE *image, unsigned int x,  unsigned int y){
	assert(image);
	return *(image->G+x+y*ImageWidth(image));
}

/* Get the B intensity of pixel (x, y) in image */
unsigned char GetPixelB(const IMAGE *image, unsigned int x,  unsigned int y){
	assert(image);
	return *(image->B+x+y*ImageWidth(image));
}

/* Set the R intensity of pixel (x, y) in image to r */
void SetPixelR(IMAGE *image, unsigned int x,  unsigned int y, unsigned char r){
	assert(image);
	*(image->R+x+y*ImageWidth(image)) = r;
}

/* Set the G intensity of pixel (x, y) in image to g */
void SetPixelG(IMAGE *image, unsigned int x,  unsigned int y, unsigned char g){
	assert(image);
	*(image->G+(x+y*ImageWidth(image))) = g;	
}

/* Set the B intensity of pixel (x, y) in image to b */
void SetPixelB(IMAGE *image, unsigned int x,  unsigned int y, unsigned char b){
	assert(image);
	*(image->B+(x+y*ImageWidth(image))) = b;	
}

/* Allocate dynamic memory for the image structure and its R/G/B values */
/* Return the pointer to the image, or NULL in case of error */
IMAGE *CreateImage(unsigned int Width, unsigned int Height){
	IMAGE *image;
	image = malloc(sizeof(IMAGE));
	image->W = Width;
	image->H = Height;
	image->R = malloc(sizeof(unsigned char)*ImageWidth(image)*ImageHeight(image));
	image->G = malloc(sizeof(unsigned char)*ImageWidth(image)*ImageHeight(image));
	image->B = malloc(sizeof(unsigned char)*ImageWidth(image)*ImageHeight(image));
	return image;
}

/* Free the memory for the R/G/B values and IMAGE structure */
void DeleteImage(IMAGE *image){
	assert(image);
	free(image->R);
	free(image->G);
	free(image->B);
	free(image);
	image->R = NULL;
	image->G = NULL;
	image->B = NULL;
	image = NULL;
}

/* Return the image's width in pixels */
unsigned int ImageWidth(const IMAGE *image){
	assert(image);
	return image->W;
}

/* Return the image's height in pixels */
unsigned int ImageHeight(const IMAGE *image){
	assert(image);
	return image->H;
}


