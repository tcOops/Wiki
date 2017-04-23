//B题的另外一种解法
//本来以为这边无法DP， 不过DP过程中巧妙解决了前缀0的问题
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int dp[N][3];//dp[i][j]表示[1,i]最多能取多少个数字，保证取到的数字和mod3 = j, 且不包含前导0
char s[N];

void upd(int &a, int b) {
	a = max(a, b);
}

int main() {
	int T, n, k;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &n, &k);
		k = n - k;
		scanf("%s", s+1);

		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;

		bool flag = false;
		for(int i = 1; i <= n; ++i) {
			int cur = s[i] - '0';
			if(cur == 0) flag = true;
			for(int j = 0; j < 3; ++j) {
				if(dp[i-1][j] == -1) continue;	
				upd(dp[i][j], dp[i-1][j]);	
				if(dp[i-1][j] + 1 <= k && (dp[i-1][j] || cur)) { //(dp[i-1][j] || cur保证非0开始)
					upd(dp[i][(j+cur)%3], dp[i-1][j] + 1);
				}
			}
		}
		if(dp[n][0] == k || (k == 1 && flag)) {
			puts("yes");
		}
		else {
			puts("no");
		}
	}
	return 0;
}