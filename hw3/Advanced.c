/*
 *  Advanced.c File
 *  Finished 02/11/21: Adding Noise, Posterization, and Negative filters
 *   
*/

/* 
 * Name: Jonathan Sugijoto
 * ID: 58535060 
*/

#include "Advanced.h"

/* Noise filter */
void Noise(int n, unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]){
	int noise = (n * WIDTH * HEIGHT) / 100;
	int x, y;
	srand(time(NULL)); /* Random with seeding by time*/
	for(int i = 1; i < noise; i++){
		x = rand() % WIDTH;
		y = rand() % HEIGHT;
		R[x][y] = 255;
		G[x][y] = 255;
		B[x][y] = 255;
	}	
}

/* Posterize the image */
void Posterize(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], unsigned int rbits, unsigned gbits, unsigned bbits){

	for(int i = 0; i < WIDTH; i++){
		for(int j = 0; j < HEIGHT; j++){
			unsigned char rtemp[8];
			unsigned char gtemp[8];
			unsigned char btemp[8];

			/* Convert the unsigned chars to binary */
			for(int k = 0; k < 8; k++){
				rtemp[7-k] = (R[i][j] >> k) & 1;
				gtemp[7-k] = (G[i][j] >> k) & 1;
				btemp[7-k] = (B[i][j] >> k) & 1;
			}

			/* Posterize the arrays */
			for(int index = 8 - rbits; index < 8; index++){
				if(index == 8 - rbits)
					rtemp[index] = 0;	
				else
					rtemp[index] = 1;
			}
			for(int index = 8 - gbits; index < 8; index++){
				if(index == 8 - gbits)
					gtemp[index] = 0;
				else
					gtemp[index] = 1;
			}
			for(int index = 8 - bbits; index < 8; index++){
				if(index == 8 - gbits)
					btemp[index] = 0;
				else
					btemp[index] = 1;
			}
			
			/* Convert the posterized array back to unsigned char and copy to RGB */
			unsigned char r_out = 0;
			unsigned char g_out = 0;
			unsigned char b_out = 0;
			for(int k = 0; k < 8; k++){
				if(rtemp[k] == 1)
					r_out += pow(2,7-k);
				if(gtemp[k] == 1)
					g_out += pow(2,7-k);
				if(btemp[k] == 1)
					b_out += pow(2,7-k);
			}
			
			R[i][j] = r_out;
			G[i][j] = g_out;
			B[i][j] = b_out;
		}
	}	
}

/* Negative Filter */
void NegativeFilter(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]){
	unsigned char nR[WIDTH][HEIGHT];
	unsigned char nG[WIDTH][HEIGHT];
	unsigned char nB[WIDTH][HEIGHT];

	/* Copy original image to temp array */
	for(int i = 0; i < WIDTH; i++){
		for(int j = 0; j < HEIGHT; j++){
			nR[i][j] = R[i][j];
			nG[i][j] = G[i][j];
			nB[i][j] = B[i][j];
		}
	}	


	/* Apply Negative Filter */
	for(int i = 0; i < WIDTH; i++){
		for(int j = 0; j < HEIGHT; j++){
			nR[i][j] = 255 - R[i][j];
			nG[i][j] = 255 - G[i][j];
			nB[i][j] = 255 - B[i][j];
		}
	}
	
	/* Copy back to original array */
	for(int i = 0; i < WIDTH; i++){
		for(int j = 0; j < HEIGHT; j++){
			R[i][j] = nR[i][j];
			G[i][j] = nG[i][j];
			B[i][j] = nB[i][j];
		}
	}
}


