#ifndef ADVANCED_H_INCLUDED_
#define ADVANCED_H_INCLUDED_

#include "Constants.h"
#include "Image.h"

/* noise filter */
IMAGE *Noise( int percentage, IMAGE *image);

/* posterize filter */
IMAGE *Posterize(IMAGE *image, unsigned int rbits, unsigned int gbits, unsigned int bbits);

/* negative filter */
IMAGE *NegativeFilter(IMAGE *image);

// New DIPs for Assignment 4

IMAGE *Enlarge(IMAGE *image, int enlarge_percentage);

IMAGE *Square(IMAGE *image, int x_offset, int y_offset, int square_size);

IMAGE *BrightnessandContrast(IMAGE *image, int brightness, int contrast);

#endif /* ADVANCED_H_INCLUDED_ */

/* vim: set tabstop=8 softtabstop=8 shiftwidth=8 noexpandtab : */
