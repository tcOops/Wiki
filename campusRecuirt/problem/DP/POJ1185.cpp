#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e6 + 10;
int C[N];

class Solution {
public:
    int InversePairs(vector<int> data) {
        memset(C, 0, sizeof(C));
        int n = data.size();
        int Ans = 0;
        for(int i = 0; i < n; ++i) {
            Ans += i - query(data[i] - 1);
            upd(data[i], 1);
        }
        return Ans;
    }
    
    void upd(int pos, int val) {
        while(pos < N) {
            C[pos] += val;
            pos += pos & (-pos);
        }
    }
    
    int query(int pos) {
        int ret = 0;
        while(pos > 0) {
            ret += C[pos];
            pos = pos & (pos - 1);
        }
        return ret;
    }
};

int main() {
	int b[8] = {8,10,2,3,4,5,6,7};

	vector<int> a(b, b+7);
	printf("%d\n", Solution().InversePairs(a));
	return 0;
}