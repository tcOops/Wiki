//参考了一发:http://www.cnblogs.com/qscqesze/p/5219813.html
//整体思路， 二分k， 对于每个k，贪心构造0000, 0001, 0010, 0100, 1000, 1100...这样的序列(有点类似于
//huffman编码， 可能由于k过大，并不需要那么多k就能构造出所有序列(>=n))

#include<bits/stdc++.h>
using namespace std;
int n,m;

int check(long long k) {
    if(k<=30&&n>(1<<k))return 0;
    long long t = 1LL*k*m;
    long long N = n;
    long long C = 1;
    long long ans = 0;
    for(int i = 0; N > 0; ++i) {
        long long p = min(C,N);
        N-=p;
        ans+=p*i;
        C = C*(k-i)/(i+1);
        //cout<<i<<" "<<N<<" "<<p<<endl;
    }
    return ans <= t ? 1 : 0;
}

int main() {
    scanf("%d%d", &n, &m);
    int l = 0,r = n;
    int ans = 0;
    while(l <= r) {
        int mid = (l+r)/2;
        if(check(mid)) r = mid-1, ans = mid;
        else l = mid + 1;
    }
    cout << ans << endl;
}