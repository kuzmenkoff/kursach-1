#include "MyForm.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;
int iters;
float* SLAR::YakobiMethod()
{
	iters = 0;
	float* X = new float[size];
	for (int i = 0; i < size; i++) {
		X1[i] = 0;
	}
	do {
		for (int i = 0; i < size; i++) {
			X[i] = X1[i];
		}
		for (int i = 0; i < size; i++) {
			double sum = 0;
			for (int j = 0; j < size; j++) {
				if (i == j) {
					continue;
				}
				sum += A[i][j] * X[j];
			}
			X1[i] = (b[i] - sum) / A[i][i];
		}
		iters++;
	} while (IsOK(X1, X) == false);
	return X1;
}

float* SLAR::GausMethod()
{
	iters = 0;
	float* X = new float[size];
	for (int i = 0; i < size; i++) {
		X2[i] = 0;
	}
	float sum;
	do {
		for (int i = 0; i < size; i++) {
			X[i] = X2[i];
		}
		for (int i = 0; i < size; i++) {
			sum = 0;
			for (int j = 0; j < size; j++) {
				if (j > i) {
					sum += A[i][j] * X[j];
				}
				else if (j < i) {
					sum += A[i][j] * X2[j];
				}
				else {
					continue;
				}
			}
			X2[i] = (b[i] - sum) / A[i][i];
		}
		iters++;
	} while (IsOK(X2, X) == false);

	return X2;
}

float* SLAR::GradientMethod()

{
	iters = 0;
	float beta, alpha;
	float* X = new float [size];
	float* rPrev = new float[size];
	float* rNext = new float[size];
	float* zPrev = new float[size];
	float* zNext = new float[size];
	float* y = new float[size];
	float* Az = new float[size];
	for (int i = 0; i < size; i++) {
		X[i] = 0;
	}
	y = funcs.MultiplyMandV(A, X, size);
	for (int i = 0; i < size; i++) {
		rPrev[i] = b[i] - y[i];
		zPrev[i] = rPrev[i];
	}
	do{
		for (int i = 0; i < size; i++) {
			if (iters == 0) {
				break;
			}
			X[i] = X3[i];
			rPrev[i] = rNext[i];
			zPrev[i] = zNext[i];
		}
		Az = funcs.MultiplyMandV(A, zPrev, size);
		alpha = funcs.ScalarProd(rPrev, rPrev, size) / funcs.ScalarProd(zPrev, Az, size);
		for (int i = 0; i < size; i++) {
			X3[i] = alpha * zPrev[i] + X[i];
			rNext[i] = rPrev[i] - alpha * Az[i];
		}
		beta = funcs.ScalarProd(rNext, rNext, size) / funcs.ScalarProd(rPrev, rPrev, size);
		for (int i = 0; i < size; i++) {
			zNext[i] = beta * zPrev[i] + rNext[i];
			
		}
		iters++;
	} while (IsOK(X3, X) == false);
	return X3;
}