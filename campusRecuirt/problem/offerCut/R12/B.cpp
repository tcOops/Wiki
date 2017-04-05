#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
map<int, int> mp;

int main() {
	int n, m;
	scanf("%d", &n);
	int MAX = 0;
	bool suc = false;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &m);
		int sum = 0;
		for(int i = 0; i < m; ++i) {
			int x;
			scanf("%d", &x);
			sum += x;
			if(i != m - 1) {
				suc = true;
				mp[sum]++;
				if(mp[sum] > MAX) {
					MAX = mp[sum];
				}
			}
		}
	}

	int ans = n;
	if(suc) {
		ans -= MAX;
	}
	printf("%d\n", ans);
	return 0;
}