#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1010;
const int INF = 0x3f3f3f3f;
int dp[N][N];
string op;

int main() {
	while(cin >> op) {
		int len = op.size();
		memset(dp, INF, sizeof(dp));
		for(int i = 0; i < len; ++i) {
			dp[i][i] = 1;
			dp[i+1][i] = 0;
		}

		for(int k = 2; k <= len; ++k) {
			for(int i = 0; i + k - 1 < len;) {
				int j = i + k - 1;
				int l = i;
				while(l <= j && op[l] == op[i]) {
					++l;
				}
				for(int k = j; k >= l - 1;) {
					if(op[k] != op[i]) {
						--k;
						continue;
					}
					int r = k;
					while(r >= l - 1 && op[r] == op[k]) {
						--r;
					}

					if(l <= r) {
						dp[i][j] = min(dp[i][j], dp[l][r] + 1 + dp[k+1][j]);
					}
					else {
						dp[i][j] = min(dp[i][j], 1 + dp[k+1][j]);
					}
					k = r;
				}
				i = l;
			}
		}
		printf("%d\n", dp[0][len-1]);
	}
	return 0;
}