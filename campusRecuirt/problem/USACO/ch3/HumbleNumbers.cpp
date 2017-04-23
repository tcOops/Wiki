/*
ID: geek7
PROG: humble
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 110;
int a[N], p[N];
long long num[N*10010];
const long long INF = 0x3f3f3f3f3f3f3f3f;

int main() {
	freopen("humble.in", "r", stdin);
	freopen("humble.out", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		p[i] = 0;
	}

	num[0] = 1;
	int cur = 0;
	for(int i = 1; i <= k; ++i) {
		long long minV = INF;
		for(int j = 0; j < n; ++j) {
			if(num[p[j]] * a[j] < minV) {
				minV = num[p[j]]*a[j];
			}
		}
		num[++cur] = minV;
		for(int j = 0; j < n; ++j) {
			while(num[p[j]] * a[j] <= num[cur]) {
				++p[j];
			}
		}
	}
	printf("%lld\n", num[k]);
	return 0;
}