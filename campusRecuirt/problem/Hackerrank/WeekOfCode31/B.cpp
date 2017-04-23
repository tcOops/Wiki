#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int a[N], dp[N];

int main() {
	int T, n;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		int cnt = 0;
		for(int i = n - 1; i >= 0; --i) {
			int pos = lower_bound(dp, dp+cnt, a[i]) - dp;
			if(pos == cnt) ++cnt;
			dp[pos] = a[i];
		}
		puts(cnt > 2 ? "No" : "Yes");
	}
	return 0;
}
