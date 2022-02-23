#define MAX(a,b) (a > b ? a : b)

double SquareRoot(double num){
	double L = 0.0;
	double R, D, M;
	R = MAX(0, num);
	do{
		M = L+(R-L)/2;
		D = M*M-num;
		if(D < 0.0){
			D = -D;
			L = M;
		}
		else
			R = M;
	}
	while (D > 1e-10);
	return M;
}
