/*********************************************************************/
/* PhotoLab.c: Assignment 2 for EECS 22, Winter 2021                 */
/* 								                                     */
/* This is an "A" level representation of PhotoLab v1.               */
/* There are improvements that can be made, but this is considered   */
/* very good.                                                        */
/*                                                                   */
/* This solution is for your reference for this course and           */
/* copyright belongs to the authors below. Reproduction or sharing   */
/* of this code outside of this class is prohibited except with the  */
/* express written consent of the authors.                           */
/*                                                                   */
/* modifications:
 * 02/11/21     JS  Finished advanced filters                        */
/* 01/13/21     QV  Adjusted for W21                                 */
/* 01/11/20 	WL	adjusted for W20			                     */
/* 10/1/18  	MC  adjusted for F18			                     */
/* 09/27/17 	RD	adjusted for lecture usage		                 */
/*********************************************************************/
/* Enter your name, last name and UCInet ID below:
 * ***************************************************************** *
 * First Name: Jonathan	
 * Last Name: Sugijoto
 * UCInetID: 58535060
 */

/*** header files ***/

#include <stdio.h>

#include "FileIO.h"
#include "DIPs.h"
#include "Advanced.h"

/* print a menu */
void PrintMenu(void);

int main(void)
{
    /* Two dimensional arrays to hold the current image data, */
    /* one array for each color component.                    */
    unsigned char   R[WIDTH][HEIGHT];
    unsigned char   G[WIDTH][HEIGHT];
    unsigned char   B[WIDTH][HEIGHT];

    /* Please replace the following code with proper menu  */
    /* with function calls for DIP operations	           */
    
    int option;         // user input option
    char fname[SLEN];   // input file name

    #ifdef DEBUG 
    AutoTest(R, G, B);
    return 0;
    #endif /* DEBUG */

    // print welcome message only once
    printf("Welcome to Photo Lab 2021 - v2!");
    PrintMenu();
    scanf("%d", &option);
    
    int rc = -1;        // return code of LoadImage()
    int n;
    int rbits, gbits, bbits;

    while (option != 99)
    {  
	// menu item 2-4 requires image is loaded first
        if (option == 1)
        {   printf("Please input the file name to load: ");
            scanf("%s", fname);
            rc = LoadImage(fname, R, G, B);
        }
        else if (option >= 2 && option <= 8)
        {   if (rc != 0)
            {   printf("No image was read.\n");
            }
            else
            {   switch(option)
                {   case 2:
                        printf("Please input the file name to save: ");
                        scanf("%s", fname);
                        SaveImage(fname, R, G, B);
                        break;
                    case 3:
                        Aging(R, G, B);
                        printf("\"Aging\" operation is done!\n");
                        break;
                    case 4:
                        EdgeDetection(R, G, B);
                        printf("\"Edge Detection\" operation is done!\n");
                        break;
                    case 5:
                        Sharpen(R, G, B);
                        printf("\"Sharpen\" operation is done!\n");
                        break;
                    case 6: 
			printf("Please input noise percentage: ");
			scanf("%d", &n);
			Noise(n, R, G, B);
			printf("\"Noise\" operation is done!\n");
			break; 
		    case 7: 
			printf("\nEnter the number of posterization bits for R channel (1 to 8): ");
			scanf("%d", &rbits);
			printf("\nEnter the number of posterization bits for G channel (1 to 8): ");
			scanf("%d", &gbits);
			printf("\nEnter the number of posterization bits for B channel (1 to 8): ");
			scanf("%d", &bbits);
			Posterize(R, G, B, rbits, gbits, bbits);
			printf("\"Posterize\" operation is done!\n");
			break;
		    case 8: 
			NegativeFilter(R, G, B);
			printf("\"Negative\" operation is done!\n");
                    default:
                        break;
                }   
            }
        }
        else if (option == 22)
        {  
            AutoTest(R, G, B);
        }
        else
        {   
	    printf("Invalid selection!\n");
        }
        // Process finished, waiting for anothre input
        PrintMenu();
       
        scanf("%d", &option);   
    }

    
    printf("Exiting program.\n");

    return 0;
}

/* Test all functions */
void AutoTest(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
    LoadImage("pigeon", R, G, B);
    Aging(R, G, B);
    SaveImage("aging", R, G, B);
    #ifdef DEBUG
    printf("Aging tested!\n\n");
    #endif
    
    /* add more tests here ("edge" and "sharpen")*/
    LoadImage("pigeon", R, G, B);
    EdgeDetection(R, G, B);
    SaveImage("edge", R, G, B);
    #ifdef DEBUG
    printf("Edge Detection tested!\n\n");
    #endif
    
    LoadImage("pigeon", R, G, B);
    Sharpen(R, G, B);
    SaveImage("sharpen", R, G, B);
    #ifdef DEBUG
    printf("Sharpen tested!\n\n");
    #endif
   
    LoadImage("pigeon", R, G, B);
    Noise(30, R, G, B);
    SaveImage("noise", R, G, B);
    #ifdef DEBUG
    printf("Noise tested!\n\n");
    #endif

    LoadImage("pigeon", R, G, B);
    Posterize(R, G, B, 7, 7, 7);
    SaveImage("posterize", R, G, B);
    #ifdef DEBUG
    printf("Posterize tested!\n\n");
    #endif
 
    LoadImage("pigeon", R, G, B);
    NegativeFilter(R, G, B);
    SaveImage("negative", R, G, B);
    #ifdef DEBUG
    printf("Negative tested!\n\n");
    #endif

}

/**************************************************************/
/* Please add your function definitions here...               */
/**************************************************************/

// print menu only
void PrintMenu()
{   printf("\n-------------------------\n");
    printf(" 1: Load a PPM image\n");
    printf(" 2: Save the image in PPM and JPEG format\n");
    printf(" 3: Run aging filter\n");
    printf(" 4: Run edge detection filter\n");
    printf(" 5: Run sharpen filter\n");
    printf(" 6: Run noise filter\n");
    printf(" 7: Run posterize filter\n");
    printf(" 8: Run negative filter\n");
    printf("22: Test all functions\n");
    printf("99: Exit\n");
    printf("--------------------------\n");
    printf("Please make your choice: ");
}


/* MORE COMING SOON */

/* EOF */
