#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int N = 51;
int x[N], y[N];
int dp[N];
int n;

int solve(int u) {
	if(~dp[u]) return dp[u];

	int MAX = 0;
	for(int i = 0; i < n; ++i) {
		if(x[u] > x[i] && y[u] > y[i]) {
			MAX = max(MAX, solve(i));
		}
	}

	return (dp[u] = MAX + 1);
}

int main() {
	while(~scanf("%d", &n)) {
		for(int i = 0; i < n; ++i) {
			scanf("%d %d", &x[i], &y[i]);
		}
		memset(dp, -1, sizeof(dp));
		int Ans = 0;
		for(int i = 0; i < n; ++i) {
			Ans = max(Ans, solve(i));
		}
		printf("%d\n", Ans);
	}
	return 0;
}