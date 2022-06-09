#include "MyForm.h"

SLAR::SLAR(int** Ainput, int* binput, int sizeinput, float epsinput)
{
    size = sizeinput;
    eps = epsinput;
    b = new int[size];
    A = new int* [size];
    for (int i = 0; i < size; i++) {
        b[i] = binput[i];
        A[i] = new int[size];
        for (int j = 0; j < size; j++) {
            A[i][j] = Ainput[i][j];
        }
    }
    X1 = new float[size];
    X2 = new float[size];
    X3 = new float[size];
    X4 = new float[size];
}

int** SLAR::GetA() { return A; }
int* SLAR::Getb() { return b; }
int SLAR::GetSize() { return size; }
float SLAR::GetEps() { return eps; }

bool SLAR::IsDDominant() // Перевірка на домінантність діагоналі
{
    int sum;
    for (int i = 0; i < size; i++) {
        sum = 0;
        for (int j = 0; j < size; j++) {
            if (i == j) {
                continue;
            }
            sum += abs(A[i][j]);
        }
        if (abs(A[i][i]) <= sum) {
            return false;
        }
    }
    return true;
}

bool SLAR::IsOK(float* Xk1, float* Xk)
{
    for (int i = 0; i < size; i++) {
        if (abs(Xk1[i] - Xk[i]) > eps) {
            return false;
        }
    }
    return true;
}

bool SLAR::SilvesterCrit()
{
    int localsize = size, m, n;
    if (funcs.FindDet(A, size) <= 0) {
        return false;
    }
    int** Mb = A;
    while (localsize > 1) {
        int** M = new int* [localsize - 1];
        for (int i = 0; i < localsize - 1; i++) {
            M[i] = new int[localsize - 1];
        }
        m = 0;
        for (int i = 0; i < localsize - 1; i++) {
            n = 0;
            for (int j = 0; j < localsize - 1; j++) {
                M[m][n] = Mb[i][j];
                n++;
            }
            m++;
        }
        if (funcs.FindDet(M, localsize - 1) <= 0) {
            return false;
        }
        localsize--;
        int** Mb = new int* [localsize];
        for (int i = 0; i < localsize; i++) {
            Mb[i] = new int [localsize];
            for (int j = 0; j < localsize; j++) {
                Mb[i][j] = M[i][j];
            }
        }
    }
    if (A[0][0] <= 0) {
        return false;
    }
 
    return true;
}

bool SLAR::IsSimmetrical()
{
    int** At = funcs.TransposeMatrix(A, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (A[i][j] != At[i][j]) {
                return false;
            }
        }
    }
    return true;
}

