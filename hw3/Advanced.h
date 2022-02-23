/* Advanced.h File */

#ifndef ADVANCED_H
#define ADVANCED_H
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Constants.h"

void Noise(int n, unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

void Posterize(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], unsigned int rbits, unsigned gbits, unsigned bbits);

void NegativeFilter(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

#endif /* ADVANCED_H */

