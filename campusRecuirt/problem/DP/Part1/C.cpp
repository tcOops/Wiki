#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e3 + 10;
int dp[N][N];

class LongestSubstring {
public:
    int findLongest(string A, int n, string B, int m) {
        // write code here
        dp[0][0] = 0;
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
        	for(int j = 1; j <= m; ++j) {
        		if(A[i-1] == B[j-1]) {
        			dp[i][j] = dp[i-1][j-1] + 1;
        		}
        		else {
        			dp[i][j] = 0;
        		}
        		if(dp[i][j] > ans) {
        			ans = dp[i][j];
        		}
        	}
        }
        return ans;
    }
};

int main() {

}