#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int N = 51;
int a[N][N], dp[N][N];

int main() {
	int m, n;
	while(~scanf("%d %d", &m, &n)) {
		for(int i = 1; i <= m; ++i) {
			for(int j = 1; j <= n; ++j) {
				scanf("%d", &a[i][j]);
			}
		}

		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= m; ++i) {
			for(int j = 1; j <= n; ++j) {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + a[i][j];
			}
		}

		printf("%d\n", dp[m][n]);
	}
	return 0;
}