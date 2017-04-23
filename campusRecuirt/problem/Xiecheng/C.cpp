#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 10;
double A[N][N],x[N];

void gauss(int n) {  
    int i, j, k, r;  
    for(i = 0; i < n; i++) {  
        r = i;  
        for(int j = i + 1; j < n; j++) {  
            if(fabs(A[j][i]) > fabs(A[r][i])) r = j;  
        }  
        if(r != i) for(j = 0; j <= n; j++) swap(A[r][j], A[i][j]);  
  
        for(k = i + 1; k < n; k++) {  
            double f = A[k][i] / A[i][i];  
            for(j = i; j <= n; j++) A[k][j] -= f * A[i][j];  
        }  
    }  
  
    for(i = n - 1; i >= 0; i--) {  
        for(j = i + 1; j < n; j++) {  
            A[i][n] -= A[j][n] * A[i][j];  
        }  
        A[i][n] /= A[i][i];  
    }  
}  

int main() {
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			int x;
			scanf("%d", &x);
			A[i][j] = 1.0*x;
		}
	}


	for(int i = 0; i < 3; ++i) {
		scanf("%lf", &A[i][3]);
	}

	gauss(3);
	for(int i = 0; i < 3; ++i) {
		printf("%.2lf ", A[i][3]);
	}
	puts("");
	return 0;
}