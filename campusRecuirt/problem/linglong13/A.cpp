#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 500010;
int a[N], b[N];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
	}

	sort(a, a+n);
	sort(b, b+n);
	long long ans = 0;
	for(int i = 0; i < n; ++i) {
		ans += (long long)a[i]*b[i];
	}
	printf("%lld\n", ans);
	return 0;
}