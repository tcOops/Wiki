//尺取法

#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int p[N];
set<int > all;
map<int, int > mp;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
        all.insert(p[i]);
    }
    int cnt = all.size();
    int idx = 0, sum = 0, ans = n, beg = 0;
    for(int idx = 0; idx < n; ++idx) {
        if(mp[p[idx]]++ == 0) {
            sum++;
        }
        if(sum >= cnt) {
            while(sum >= cnt) {
                ans = min(idx - beg, ans);
                if(--mp[p[beg++]] == 0) {
                    --sum;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
