#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int N = 1010;
int f[N];

int solve(string s, int k) {
	int n = s.size();

	int sum = 0, ans = 0;
	memset(f, 0, sizeof(f));
	for(int i = 0; i < n - k + 1; ++i) {
		if(i >= k) {
			sum -= f[i-k];
		}
		if(s[i] == '+') {
			if(sum & 1) {
				f[i] = 1;
				++ans;
			}
		}
		else {
			if(!(sum & 1)) {
				f[i] = 1;
				++ans;
			}
		}
		sum += f[i];
	}

	for(int i = n - k + 1; i < n; ++i) {
		if(i >= k) {
			sum -= f[i-k];
		}
		if(s[i] == '+' && (sum & 1)) {
			return -1;
		}
		if(s[i] == '-' && !(sum & 1)) {
			return -1;
		}
	}
	return ans;
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T, cases = 1, k;
	string ss;
	scanf("%d", &T);
	while(T--) {
		printf("Case #%d: ", cases++);
		cin >> ss;
		scanf("%d", &k);
		int ans = solve(ss, k);
		if(ans == -1) {
			puts("IMPOSSIBLE");
		}
		else {
			printf("%d\n", ans);
		}
	}
	return 0;
}