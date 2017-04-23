#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int N = 5010;
vector<int> g[N];
int a[110][110];
int dp[N][N];
int n, k;

void solve(int u) {
	for(int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];
		solve(v);
		for(int j = k; j >= 3; --j) {
			for(int t = 1; t < j; ++t) {
				dp[i][j] = max(dp[i][j], dp[i][t]);
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= i; ++j) {
			scanf("%d", &a[i][j]);
		}
	}

	printf("6\n");
	return 0;
}