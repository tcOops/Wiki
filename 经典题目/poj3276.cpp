//开关问题
//简单枚举之后，用前缀和优化
//O(n^2)

#include <cstdio>
#include <cstring>
using namespace std;

const int N = 5010;
int p[N], sum;
char dd[N];
int n;

int solve(int k) {
    memset(p, 0, sizeof(p));
    int sum = 0, ans = 0;
    for(int i = 0; i <= n - k; ++i) {
        if((sum & 1) ^ (dd[i] == 'B')) {
            p[i] = 1;
            ans++;
        }
        sum += p[i];
        if(i >= k - 1) {
            sum -= p[i-k+1];
        }
    }

    for(int i = n-k+1; i < n; ++i) {
        if((sum & 1) ^ (dd[i] == 'B')) {
            return -1;
        }
        if(i >= k - 1) {
            sum -= p[i-k+1];
        }
    }
    return ans;
}

int main() {
    char s[2];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%s", s);
        dd[i] = s[0];
    }
    int ans = n, minK = 1;
    for(int i = 1; i <= n; ++i) {
        int res = solve(i);
//	printf("%d %d\n", i, res);
        if(~res && res < ans) {
            ans = res;
            minK = i;
        }
    }
    printf("%d %d\n", minK, ans);
    return 0;
}
