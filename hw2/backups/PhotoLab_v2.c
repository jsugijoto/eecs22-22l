/*********************************************************************/
/* PhotoLab.c: Assignment 2 for EECS 22, Winter 2020                 */
/*								     */
/* modifications                                                     */
/* 01/13/21     QV  Adjusted for W21                                 */
/* 01/11/20	WL	adjusted for W20			     */
/* 10/1/18	MC  adjusted for F18				     */
/* 09/27/17	RD	adjusted for lecture usage                   */
/*********************************************************************/
/* Enter your name, last name and UCInet ID below:
 * ***************************************************************** *
 * First Name: Jonathan
 * Last Name: Sugijoto
 * UCInetID: 58535060
 */

/*** header files ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*** global definitions ***/

#define WIDTH  600		/* image width */
#define HEIGHT 400		/* image height */
#define SLEN    64		/* maximum length of file names */

/* added new defines for edge detection filter*/
/* you can use these or not (not necessary, but we used it for convenience) */
#define MAX_PIXEL 255	/* max pixel value */
#define MIN_PIXEL 0		/* min pixel value */

/*** function declarations ***/

/* print a menu */
int PrintMenu(void);

/* read image from a file */
/* written for you; should not been modified */
int LoadImage(const char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* save a processed image */
/* written for you; should not been modified */
int SaveImage(const char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* aging the photo */
/* sample function to get you started */
void Aging(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* detect edges in a picture (black background with white edges) */
void EdgeDetection(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* sharpen the image */
void Sharpen(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* test all functions */
void AutoTest(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

int main(void)
{
    /* Two dimensional arrays to hold the current image data, */
    /* one array for each color component.                    */
    unsigned char   R[WIDTH][HEIGHT];
    unsigned char   G[WIDTH][HEIGHT];
    unsigned char   B[WIDTH][HEIGHT];

    /* Please replace the following code with proper menu  */
    /* with function calls for DIP operations		   */
    
	char fname[SLEN];
	int back2menu = 1;
	while(back2menu == 1){
		int choice = PrintMenu();	
		switch(choice){
			case 1: /* Load PPM image */
				printf("Please input the file name to load: ");
				scanf("%s", fname);	
				LoadImage(fname, R, G, B);
				break;
			case 2:	/* Save Image */
				printf("Please input the file name to save: ");
				scanf("%s", fname);
				SaveImage(fname, R, G, B);
				break;
			case 3: /* Run Aging Filter */
				Aging(R, G, B);	
				break;
			case 4: /* Run Edge Detection Filter */
				EdgeDetection(R, G, B);
				break;
			case 5: /* Run sharpen filter */
				break;
			case 22: /* Test All Functions */
				AutoTest(R, G, B);
				break;
			case 99: /* Exit */
				back2menu = 0;
				break;
		}
	}

    /* End of replacing */
    return 0;
}

/* takes in a file name without extension */
/* writes file into R, G, B arrays */
int LoadImage(const char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
    FILE *File;
    char Type[SLEN];
    int  Width, Height, MaxValue;
    int  x, y;
    char ftype[] = ".ppm";
    char fname_ext[SLEN + sizeof(ftype)];

    strcpy(fname_ext, fname);
    strcat(fname_ext, ftype);

    File = fopen(fname_ext, "r");
    if (!File) {
        printf("\nCannot open file \"%s\" for reading!\n", fname);
        return 1;
    }
    fscanf(File, "%79s", Type);
    if (Type[0] != 'P' || Type[1] != '6' || Type[2] != 0) {
        printf("\nUnsupported file format!\n");
        return 2;
    }
    fscanf(File, "%d", &Width);
    if (Width != WIDTH) {
        printf("\nUnsupported image width %d!\n", Width);
        return 3;
    }
    fscanf(File, "%d", &Height);
    if (Height != HEIGHT) {
        printf("\nUnsupported image height %d!\n", Height);
        return 4;
    }
    fscanf(File, "%d", &MaxValue);
    if (MaxValue != 255) {
        printf("\nUnsupported image maximum value %d!\n", MaxValue);
        return 5;
    }
    if ('\n' != fgetc(File)) {
        printf("\nCarriage return expected!\n");
        return 6;
    }
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            R[x][y] = fgetc(File);
            G[x][y] = fgetc(File);
            B[x][y] = fgetc(File);
        }
    }
    if (ferror(File)) {
        printf("\nFile error while reading from file!\n");
        return 7;
    }
    printf("%s was read successfully!\n", fname_ext);
    fclose(File);
    return 0;
}

/* takes R, G, B arrays and writes it in a file */
/* filename (fname) has no extension */
int SaveImage(const char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
    FILE *File;
    char ftype[] = ".ppm";
    char fname_ext[SLEN + sizeof(ftype)];
    char SysCmd[SLEN * 5];
    int  x, y;

    strcpy(fname_ext, fname);
    strcat(fname_ext, ftype);

    File = fopen(fname_ext, "w");
    if (!File) {
        printf("\nCannot open file \"%s\" for writing!\n", fname);
        return 1;
    }
    fprintf(File, "P6\n");
    fprintf(File, "%d %d\n", WIDTH, HEIGHT);
    fprintf(File, "255\n");

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            fputc(R[x][y], File);
            fputc(G[x][y], File);
            fputc(B[x][y], File);
        }
    }

    if (ferror(File)) {
        printf("\nFile error while writing to file!\n");
        return 2;
    }
    fclose(File);
    printf("%s was saved successfully. \n", fname_ext);

    /*
     * rename file to image.ppm, convert it to ~/public_html/<fname>.jpg
     * and make it world readable
     */
    sprintf(SysCmd, "~eecs22/bin/pnmtojpeg_hw2.tcsh %s", fname_ext);
    if (system(SysCmd) != 0) {
        printf("\nError while converting to JPG:\nCommand \"%s\" failed!\n", SysCmd);
        return 3;
    }
    printf("%s.jpg was stored for viewing. \n", fname);

    return 0;
}


/* Test all functions */
void AutoTest(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{

    LoadImage("lambo", R, G, B);
    Aging(R, G, B);
    SaveImage("aging", R, G, B);
    printf("Aging tested!\n\n");
    LoadImage("lambo", R, G, B);
    EdgeDetection(R, G, B);
    SaveImage("edge", R, G, B);
    printf("Edge tested!\n\n");
    LoadImage("lambo", R, G, B);
    Sharpen(R, G, B);
    SaveImage("sharpen", R, G, B);
    printf("Sharpen testeed!\n\n");

    /* add more tests here ("edge" and "sharpen")*/

}

/**************************************************************/
/* Please complete and add function definitions below...      */
/**************************************************************/

/* age the image to make it look like old picture */
void Aging(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
    int x, y;

    for( y = 0; y < HEIGHT; y++ ) {
        for( x = 0; x < WIDTH; x++ ) {
	    B[x][y] = ( R[x][y]+G[x][y]+B[x][y] )/5;
            R[x][y] = (unsigned char) (B[x][y]*1.6);
            G[x][y] = (unsigned char) (B[x][y]*1.6);
	    }
    }
}

void EdgeDetection(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{   
	int r_sum = 0;
	int g_sum = 0;
	int b_sum = 0;
	unsigned char nR[WIDTH][HEIGHT];
	unsigned char nG[WIDTH][HEIGHT];
	unsigned char nB[WIDTH][HEIGHT];

	/* Copy Array */
		for(int x = 0; x < WIDTH; x++){
			for(int y =0; y < HEIGHT; y++){
				nR[x][y] = R[x][y];
				nG[x][y] = G[x][y];
				nB[x][y] = B[x][y];
			}
		}


	/* Skipping the first column, first row, last column, and last row because they're not surrounded completely */
	for(int y = 1; y < HEIGHT - 1; y++){
		for(int x = 1; x < WIDTH- 1; x++){
			r_sum = 0;
			g_sum = 0;
			b_sum = 0;
			/* Now we have x,y coords, loop around in the circle around */
			for(int i = x-1; i < x+2; i++){
				for(int j = y-1; j < y+2; j++){
					r_sum = R[i][j]	+ r_sum;
					g_sum = G[i][j] + g_sum;
					b_sum = B[i][j] + b_sum;
				}
			}
			r_sum = r_sum - R[x][y];
			g_sum = g_sum - G[x][y];
			b_sum = b_sum - B[x][y];

			if((8*R[x][y] - r_sum) > 255){
				nR[x][y] = 255;
			}
			else if((8*R[x][y] - r_sum) < 0){
				nR[x][y] = 0;
			}
			else{
				nR[x][y] = (unsigned char)  8*R[x][y] - r_sum;
			}
			if((8*G[x][y] - g_sum) > 255){
				nG[x][y] = 255;
			}
			else if((8*G[x][y] - g_sum) < 0){
				nG[x][y] = 0;
			}
			else{
				nG[x][y] = (unsigned char) 8*G[x][y] - g_sum;
			} 
			if((8*B[x][y] - b_sum) > 255){
				nB[x][y] = 255;
			}
			else if((8*B[x][y] - b_sum) < 0){
				nB[x][y] = 0;
			}
			else{
				nB[x][y] = (unsigned char) 8*B[x][y] - b_sum;
			}

		}
	}
	/* Copy back to original RGB */
	for(int x = 0; x < WIDTH; x++){
		for(int y =0; y < HEIGHT; y++){
			R[x][y] = nR[x][y];
			G[x][y] = nG[x][y];
			B[x][y] = nB[x][y];
		}
	}
} 

void Sharpen(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	int r_sum = 0;
	int g_sum = 0;
	int b_sum = 0;
	unsigned char nR[WIDTH][HEIGHT];
	unsigned char nG[WIDTH][HEIGHT];
	unsigned char nB[WIDTH][HEIGHT];

	/* Copy Array */
	for(int x = 0; x < WIDTH; x++){
		for(int y =0; y < HEIGHT; y++){
			nR[x][y] = R[x][y];
			nG[x][y] = G[x][y];
			nB[x][y] = B[x][y];
		}
	}
	/* Skipping the first column, first row, last column, and last row because they're not surrounded completely */
	for(int y = 1; y < HEIGHT-1; y++){
		for(int x = 1; x < WIDTH-1; x++){
			r_sum = 0;
			g_sum = 0;
			b_sum = 0;
			/* Now we have x,y coords, loop around in the circle around */
			for(int i = x-1; i < x+2; i++){
				for(int j = y-1; j < y+2; j++){
					r_sum = R[i][j] + r_sum;
					g_sum = G[i][j] + g_sum;
					b_sum = B[i][j] + b_sum;
				}
			}
			r_sum = r_sum - R[x][y];
			g_sum = g_sum - G[x][y];
			b_sum = b_sum - B[x][y];
			
			if((9*R[x][y] - r_sum) > 255){
				nR[x][y] = 255;
			}
			else if((9*R[x][y] - r_sum) < 0){
				nR[x][y] = 0;
			}
			else{
				nR[x][y] = (unsigned char)  9*R[x][y] - r_sum;
			}
			if((9*G[x][y] - g_sum) > 255){
				nG[x][y] = 255;
			}
			else if((9*G[x][y] - g_sum) < 0){
				nG[x][y] = 0;
			}
			else{
				nG[x][y] = (unsigned char) 9*G[x][y] - g_sum;
			} 
			if((9*B[x][y] - b_sum) > 255){
				nB[x][y] = 255;
			}
			else if((9*B[x][y] - b_sum) < 0){
				nB[x][y] = 0;
			}
			else{
				nB[x][y] = (unsigned char) 9*B[x][y] - b_sum;
			}

		}
	}
	/* Copy back to original RGB */
	for(int x = 0; x < WIDTH; x++){
		for(int y =0; y < HEIGHT; y++){
			R[x][y] = nR[x][y];
			G[x][y] = nG[x][y];
			B[x][y] = nB[x][y];
		}
	}
}

int PrintMenu(void)
{
	int choice;
	printf("Welcome to PhotoLab 2021 - V1!");
	printf("\n-----------------------------");
	printf("\n1: Load PPM Image");
	printf("\n2: Save Image in PPM and JPEG Format");
	printf("\n3: Run Aging Filter");
	printf("\n4: Run Edge Detection Filter");
	printf("\n5: Run Sharpen Filter");
	printf("\n22: Test All Functions");
	printf("\n99: Exit");
	printf("\n-----------------------------");
	printf("\nPlease make your choice: ");
	scanf("%d", &choice);
	
	return choice;
}
/* MORE COMING SOON */

/* EOF */
