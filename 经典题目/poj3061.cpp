//尺取法

#include <cstdio>
#include <cstring>
using namespace std;
const int N = 100010;
int a[N];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, s, ans = 1e9;
        scanf("%d %d", &n, &s);
        int p = 0, sum = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            sum += a[i];
            if(sum >= s) {
                while(sum >= s) {
                    if(i - p + 1 < ans) {
                        ans = i - p + 1;
                    }
                    sum -= a[p++];
                }
            }
        }
        if(ans == 1e9) {
            ans = 0;
        }
        printf("%d\n", ans);
    }
    return 0;
}
