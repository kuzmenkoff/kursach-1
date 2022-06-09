#include <string>
#include "MyForm.h"
using namespace std;


int support::FindDet(int** M, int size) //Визначення детермінанту
{
    if (size == 1) {
        return M[0][0];
    }
	else if (size == 2) {
		return M[0][0] * M[1][1] - M[0][1] * M[1][0];
	}
	else {
        int det = 0;
        for (int k = 0; k < size; k++) {
            int** m = new int* [size - 1];
            for (int i = 0; i < size - 1; i++) {
                m[i] = new int[size - 1];
            }
            for (int i = 1; i < size; i++) {
                int t = 0;
                for (int j = 0; j < size; j++) {
                    if (j == k) {
                        continue;
                    }
                    m[i - 1][t] = M[i][j];
                    t++;
                }
            }
            det += pow(-1, k + 2) * M[0][k] * FindDet(m, size - 1);
        }
        return det;
	}
}


int** support::TransposeMatrix(int** M, int size)
{
    int** Mt = new int* [size];
    for (int i = 0; i < size; i++) {
        Mt[i] = new int[size];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            Mt[i][j] = M[j][i];
        }
    }
    return Mt;
}

float* support::MultiplyMandV(int** M, float* V, int size)
{
    float* res = new float[size];
    for (int i = 0; i < size; i++) {
        res[i] = 0;
        for (int j = 0; j < size; j++) {
            res[i] += M[i][j] * V[j];
        }
    }
    return res;
}

float support::ScalarProd(float* V1, float* V2, int size)
{
    float res = 0;
    for (int i = 0; i < size; i++) {
        res += V1[i] * V2[i];
    }
    return res;
}




