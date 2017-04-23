//提交地址：https://www.nowcoder.com/profile/8928651/test/7708335/25104

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
const int INF = 0x3f3f3f3f;
int dp[N];

class AscentSequence {
public:
    int findLongest(vector<int> A, int n) {
    	int cnt = 0;
        for(int i = 0; i < n; ++i) {
        	int pos = lower_bound(dp, dp+cnt, A[i]) - dp;
        	if(pos == cnt) {
        		++cnt;
        	}
        	dp[pos] = A[i];
        }
        return cnt;
    }
};

int main() {
	int a[7] = {2, 1, 4, 3, 2, 5, 6};
	vector<int> b(a, a+7);
	printf("%d\n", AscentSequence().findLongest(b, 7));
	return 0;
}