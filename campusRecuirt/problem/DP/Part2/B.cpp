#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 300;
const int INF = 0x3f3f3f3f;
const int MOD = 10007;
int dp[N][N][2];

class Expression {
public:
    int countWays(string exp, int len, int ret) {
        // write code here
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < len; ++i) {
        	if(exp[i] == '0' || exp[i] == '1') {
        		dp[i][i][exp[i] - '0'] = 1;
        	}
        }

        for(int k = 3; k <= len; k += 2) {
        	for(int i = 0; i + k - 1 < len; i += 2) {
        		int j = i + k - 1;
        		for(int t = i + 1; t < j; t += 2) {
        			if(exp[t] == '&') {
        				dp[i][j][0] += dp[i][t-1][0]*(dp[t+1][j][0] + dp[t+1][j][1])%MOD + dp[i][t-1][1]*dp[t+1][j][0]%MOD;
        				dp[i][j][1] += dp[i][t-1][1]*dp[t+1][j][1]%MOD;
        			}
        			else if(exp[t] == '|') {
        				dp[i][j][1] += dp[i][t-1][1]*(dp[t+1][j][0] + dp[t+1][j][1])%MOD + dp[i][t-1][0]*dp[t+1][j][1]%MOD;
        				dp[i][j][0] += dp[i][t-1][0]*dp[t+1][j][0]%MOD;
        			}
        			else {
        				dp[i][j][0] += dp[i][t-1][0]*dp[t+1][j][0]%MOD + dp[i][t-1][1]*dp[t+1][j][1]%MOD;
        				dp[i][j][1] += dp[i][t-1][1]*dp[t+1][j][0]%MOD + dp[i][t-1][0]*dp[t+1][j][1]%MOD;
        			}
        			dp[i][j][0] %= MOD;
        			dp[i][j][1] %= MOD;
        		}
        		printf("%d %d %d %d\n", i, j, dp[i][j][0], dp[i][j][1]);
        	}
        }

        return dp[0][len-1][ret];
    }
};

int main() {
	printf("%d\n", Expression().countWays("1^0|0|1",7,0));
	return 0;
}