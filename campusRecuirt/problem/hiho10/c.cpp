#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int N = 200010;
map<int, int> mp;
int cnt;
int a[N], num[N];
int n, k;

bool check(long long x) {
	int l = 0;
	long long sum = 0, ans = 0;
	for(int i = 0; i < cnt; ++i) {
		num[i] = 0;
	}

	for(int i = 0; i < n; ++i) {
		sum += num[a[i]]++;
		while(sum > x) {
			sum -= --num[a[l++]];
		}
		ans += (i - l + 1);
	}
	return ans >= k;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		cnt = 0;
		mp.clear();
		scanf("%d %d", &n, &k);
		for(int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &a[i]);
			if(mp.find(a[i]) == mp.end()) {
				mp[a[i]] = cnt++;
			}
			a[i] = mp[a[i]];
		}

		long long l = 0, r = (long long)n*(n+1)/2;
		while(l < r) {
			long long mid = (l + r) >> 1;
			if(check(mid)) {
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
		printf("%lld\n", l);
	}
	return 0;
}