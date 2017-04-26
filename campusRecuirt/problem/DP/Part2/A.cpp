//提交地址:https://www.nowcoder.com/question/next?pid=123743&qid=25142&tid=7710352

const int N = 1e3 + 10;
bool dp[N][N];

class Mixture {
public:
    bool chkMixture(string A, int n, string B, int m, string C, int v) {
        // write code here
    	if(n + m != v) return false;

    	memset(dp, false, sizeof(dp));
    	dp[0][0] = true;
    	for(int i = 1; i <= v; ++i) {
    		for(int j = 0; j <= i - 1 && j <= n; ++j) {
    			int k = i - 1 - j;
    			if(!dp[j][k]) continue;
    			if(j < n && C[i-1] == A[j]) {
    				dp[j+1][k] = true;
    			}
    			if(k < m && C[i-1] == B[k]) {
    				dp[j][k+1] = true;
    			}
    		}
    	}

    	return dp[n][m];
    }
};