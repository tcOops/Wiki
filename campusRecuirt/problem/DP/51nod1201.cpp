//经典dp
// http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1201 
//普通背包无法解决 $O(n^2)$
//dp转换

#include <cstdio>
#include <cstring>
using namespace std;
const int N = 50010;
const int MOD = 1e9 + 7;
int dp[N][350];

int main() {
	int n;
	scanf("%d", &n);

	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for(int i = 1; i < 350; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(i <= j) {
				dp[j][i] = dp[j-i][i]; //不包含1
				dp[j][i] = (dp[j][i] + dp[j-i][i-1])%MOD;//包含1
			}
		}
	}

	int ans = 0;
	for(int i = 1; i < 350; ++i) {
		ans = (ans + dp[n][i])%MOD;
	}
	printf("%d\n", ans);
	return 0;
}