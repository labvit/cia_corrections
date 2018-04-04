#include "pot.h"
#define  EIGEN_USE_MKL_ALL
#include "Eigen/Dense"
#include <iostream>
#include <cmath>
#include "stdlib.h"
#include <stdio.h>

using namespace std;
using namespace Eigen;

int J = 0;
const  double K = 8065.54*27.211396;
void set_matrix(MatrixXd & A, int Lmax){
  // MatrixXd A(2*Lmax+1,2*Lmax+1);
  int i,j;
  i=j=0;
  double hat = 1/(2*M_PI);
  double R2 = 6.4966058999999 * 6.4966058999999;
  double mu = 40*44/(40+44)*1836e0;
  double I = 2.192082147*2.192082147*2*16*1836e0;

  int m = 0;
  for(int L = 0; L < Lmax; L++)
    for(int M = -L; M<=L; M++, i++)
      for(int l = 0, j = 0; l < Lmax; l++)
  	{

	  double prefac = 0e0;
	  if(L==l)
	    prefac = (hat * hat  / 2e0) * 
	      (L*(L+1)/I + ( J*(J+1) + L*(L+1)  )/(mu*R2) );

    	
	  for( m = -l; m<=l; m++,j++){
	    if(m==M){
	      printf("%f ", pot_sum(L,l,m));
	      A(i,j) = pot_sum(L,l,m)/K + prefac;
	    }
	  }
	  printf("\n");
  	}
  }
    	

int main(int n, char** args){
	int Lmax = 15;
	if(n>1) J = atoi(args[1]), Lmax = atoi(args[2]);
	int max = Lmax * (2*Lmax + 1) / 2;
	MatrixXd A(max , max);

	set_matrix(A,Lmax);
	SelfAdjointEigenSolver<MatrixXd> eigensolver(A);

	if(eigensolver.info() != Success) abort();

	cout <<eigensolver.eigenvalues()*K << endl;
	//	cout << "Here's a matrix whose columns are eigenvectors of A \n"
	//        << "corresponding to these eigenvalues:\n"
	//<< eigensolver.eigenvectors().col(0).norm() << endl;
        
}
