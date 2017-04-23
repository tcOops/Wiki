#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1010;
int a[N];
int n, p, w, h;

bool check(int v) {
	int cnt = 0;
	int pp = w/v;
	for(int i = 0; i < n; ++i) {
		cnt += a[i]/pp;
		if(a[i]%pp) ++cnt;
	}

	pp = h/v;
	int pages = cnt / pp;
	if(cnt%pp) ++pages;
	return pages <= p;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d %d", &n, &p, &w, &h);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}

		int l = 1, r = min(w, h);
		while(l < r) {
		//	printf("%d %d\n", l, r);
			int mid = (l + r + 1) >> 1;
			if(check(mid)) {
				l = mid;
			}
			else {
				r = mid - 1;
			}
		}
		printf("%d\n", l);
	}
	return 0;
}