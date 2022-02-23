#include "sqrt.h"
#include "sqrt.c"

double main(void){
	double num;
	printf("Enter a positive value: ");
	scanf("%lf", &num);
	double out = SquareRoot(num);
	printf("%lf", out);
	return out;
}
