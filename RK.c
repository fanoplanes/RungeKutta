#include<stdio.h>

double f(double x, double y)
{
	return 4*x*x*x;		// y' = 4x^3
				// exact solution x^4
}

double RK4(double x, double y, double dx)
{
	double k1, k2, k3, k4;

	k1=dx*f(x, y);
	k2=dx*f(x + 0.5*dx, y + 0.5*k1);
	k3=dx*f(x + 0.5*dx, y + 0.5*k2);
	k4=dx*f(x + dx, y + k3);
	y+=(1./6)*(k1 + 2*k2 + 2*k3 + k4);	// +O(h^5)

	return y;
}

int main()
{
	FILE * pFile;
	pFile = fopen("RK.dat", "w");

	double dx = 1e-3;
	double x_0=0., x_1=1.;
	double y = 0;		// f(x_0) = 0

	for(double x = x_0; x < x_1; x += dx)
	{
		y = RK4(x, y, dx);
		fprintf(pFile, "%f\t%f\n", x, y);
	}
	return 0;
}
