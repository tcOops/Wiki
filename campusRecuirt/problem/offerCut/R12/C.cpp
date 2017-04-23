#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 110;

int dp[N][N];

int solve(int m, int n) {
	if(m == 0) return 1;
	if(n == 1) return 1;

	if(~dp[m][n]) {
		return dp[m][n];
	}

	int res;
	if(m < n) {
		res = solve(m, m);
	}
	else {
		res = solve(m - n, n) + solve(m, n-1);
	}
	return dp[m][n] = res;
}


int main() {
	int n;
	memset(dp, -1, sizeof(dp));
	while(~scanf("%d", &n)) {
		int ans = solve(n, n);
		printf("%d\n", ans);
	}
	return 0;
}