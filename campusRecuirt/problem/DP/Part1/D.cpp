#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e3 + 10;
int dp[N][N];

class MinCost {
public:
    int findMinCost(string A, int n, string B, int m, int c0, int c1, int c2) {
        // write code here
        dp[0][0] = 0;
        for(int i = 1; i <= max(n, m); ++i) {
        	dp[i][0] = c1*i;
        	dp[0][i] = c0*i;
        }
        for(int i = 1; i <= n; ++i) {
        	for(int j = 1; j <= m; ++j) {
        		if(A[i-1] == B[j-1]) {
        			dp[i][j] = dp[i-1][j-1];
        		}
        		else {
        			dp[i][j] = min(dp[i][j-1] + c0, dp[i-1][j] + c1, dp[i-1][j-1] + c2);
        		}
        		printf("%d %d %d\n", i, j, dp[i][j]);
        	}
        }
        return dp[n][m];
    }

    int min(int a, int b, int c) {
    	int ret = a < b ? a : b;
    	if(ret > c) {
    		ret = c;
    	}
    	return ret;
    }
};

int main() {
	printf("%d\n", MinCost().findMinCost("abc", 3, "adc", 3, 5, 3, 100));
	return 0;
}