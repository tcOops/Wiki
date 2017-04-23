#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int Ans[21];

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T, cases = 1;
	scanf("%d", &T);
	while(T--) {
		printf("Case #%d: ", cases++);
		long long n;
		scanf("%lld", &n);
		int cnt = 0;
		while(n) {
			int cur = n % 10;
			if(cnt == 0) {
				Ans[cnt++] = cur;
			}
			else {
				if(cur > Ans[cnt-1]) {
					for(int i = 0; i < cnt; ++i) {
						Ans[i] = 9;
					}
					Ans[cnt++] = cur - 1;
				}
				else {
					Ans[cnt++] = cur;
				}
			}
			n /= 10;
		}

		int idx = cnt - 1;
		for(; idx >= 0; --idx) {
			if(Ans[idx]) break;
		}
		for(; idx >= 0; --idx) {
			printf("%d", Ans[idx]);
		}
		puts("");
	}
	return 0;
}