#include "leg_arr.h"
#include "wignerSymbols.h"

using WignerSymbols::wigner3j;

double * prefac(int N,int P, int M, int L)
{
	double * leg = (double*)malloc((N+1)*sizeof(double));
	int sign=-1;
	if(M % 2 == 0) sign = 1;
	for (int i =0; i < N; ++i)
	{
		leg[i] = sign * sqrt((2*P+1)*(2*L+1)) * wigner3j(L,i,P,0,0,0) * wigner3j(L,i,P,M,0,-M);
	}
	return leg;

}
