#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e3 + 10;
const int INF = 0x3f3f3f3f;
int dp[N][N];

class LCS {
public:
    int findLCS(string A, int n, string B, int m) {
        // write code here
        for(int i = 1; i <= n; ++i) {
        	for(int j = 1; j <= m; ++j) {
        		if(A[i-1] == B[j-1]) {
        			dp[i][j] = dp[i-1][j-1] + 1;
        		}
        		else {
        			dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        		}
        	}
        }
        return dp[n][m];
    }
};

int main() {

}