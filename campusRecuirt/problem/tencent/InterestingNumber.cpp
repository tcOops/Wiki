#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
const int INF = INT_MAX;
int a[N], b[N], c[N];

int main() {
	int n;
	while(~scanf("%d", &n)) {
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		if(n == 1) {
			printf("0 0\n");
			return 0;
		}
		sort(a, a+n);
		int cnt = 0;
		int ans1 = 0, ans2 = 0;
		for(int i = 0; i < n;) {
			int j = i;
			while(j < n && a[j] == a[i]) {
				++j;
			}
			b[cnt] = a[i];
			c[cnt++] = j - i;
			ans1 += (j-i)*(j-i-1)/2;
			i = j;
		}

		int MIN = INF;
		if(!ans1) {
			for(int i = 1; i < cnt; ++i) {
				if(b[i] - b[i-1] < MIN) {
					ans1 = c[i] * c[i-1];
					MIN = b[i] - b[i-1];
				}
				else if(b[i] - b[i-1] == MIN) {
					ans1 += c[i] * c[i-1];
				}
			}
		}

		if(cnt == 1) {
			ans2 = c[0]*(c[0]-1)/2;
		}
		else {
			ans2 = c[cnt-1]*c[0];
		}

		printf("%d %d\n", ans1, ans2);
	}
}