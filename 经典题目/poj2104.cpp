//分块求区间K小
//复杂度O(nlg(n) + m*sqrt(n*lgn)*lgn) 

#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
const int B = 1000; // B -> sqrt(n*lgn)
int a[N], b[N];
vector<int > bucket[N/B + 10];
int n, m;

int solve(int x, int y, int k) {
    int l = 0, r = n - 1;
    while(l < r) {
        int mid = (l + r) >> 1;
        int val = b[mid];
        int ll = x, rr = y + 1, cnt = 0;//这里需要注意，为了处理方便我们将rr+1
        while(ll < rr && ll % B) {
            if(a[ll++] <= val) {
                ++cnt;
            }
        }
        while(ll < rr && rr % B) {
            if(a[--rr] <= val) {
                ++cnt;
            }
        }
        
        while(ll < rr) {
            int bb = ll / B;
            cnt += upper_bound(bucket[bb].begin(), bucket[bb].end(), val) - bucket[bb].begin();
            ll += B;
        }
     //   printf("%d %d %d\n", mid, b[mid], cnt);
        if(cnt >= k) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    return b[l];
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    
    for(int i = 0; i < n; ++i) {
        bucket[i/B].push_back(a[i]);
    }
    sort(b, b+n);
    for(int i = 0; i < n/B; ++i) {
        sort(bucket[i].begin(), bucket[i].end());
    }
    
    for(int i = 1; i <= m; ++i) {
        int x, y, k;
        scanf("%d %d %d", &x, &y, &k);
        printf("%d\n", solve(x - 1, y - 1, k));
    }
    return 0;
}
