#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
vector<string> a, b;
map<string, int> mp, has;

int main() {
	int n, m;
	while(~scanf("%d %d", &n, &m)) {
		a.clear();
		b.clear();
		mp.clear();
		has.clear();
		string tmp;
		for(int i = 0; i < n; ++i) {
			cin >> tmp;
			a.push_back(tmp);
		}
		for(int i = 0; i < m; ++i) {
			cin >> tmp;
			b.push_back(tmp);
			mp[tmp] = 1;
		}

		long long ans = 0;
		for(int i = 0; i < n; ++i) {
			if(has.find(a[i]) != has.end()) {
				continue;
			}
			if(mp.find(a[i]) != mp.end()) {
				int len = a[i].size();
				ans += (long long)len*(long long)len;
			}
			has[a[i]] = 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
