#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "winbgi2.h"
#include "rk4.h"
#define g 9.8
#define pi 3.14
void rhs_fun(double t, double* X, double* F, double k, double a, double m)
{
	F[0]= X[1];
	F[1] = -a*X[2]/m-k*X[1]*X[1];
	F[2]= X[3];
	F[3]=-X[3]*abs(X[3])*k-g;
}

int main()
{
	
	double ro=1.2,H=0.01,S,C,m,k,a,b,r;
	double X[4];
	double X1[4];
	X[0]=0; 
	X[1]=0; 
	X[2]=0;

	printf("r[m]:"); 
	scanf("%lf",&r);
	printf("\nstaly wspolczynnik oporu powietrza:");
	scanf("%lf",&C);
	printf("\nmasa[kg]:");
	scanf("%lf",&m);
	printf("\nwspolczynnik predkosci wiatru[kg/s^2]\n");
	printf("a:");
	scanf("%lf",&a);
	printf("\npredkosc poczatkowa[m/s]:");
	scanf("%lf",&X[3]); 
	S = pi*pow(r,2);
	k=ro*S*C/2*m;
	
	graphics(1000,1000);
	scale(0,-10,2,10);
	X1[2]=0;
	
	for (double i=0;X1[2]>=0;i=i+H)
	{
		vrk4(0,X,H,4,rhs_fun,X1,k,a,m);
		
		X[0]=X1[0];
		X[1]=X1[1];
		X[2]=X1[2];
		X[3]=X1[3];
	
		//point(i,X1[0]);
		//point(i,X1[1]); 
		//point(i,X1[2]);
		//point(i,X1[3]);
	}
	wait();
}