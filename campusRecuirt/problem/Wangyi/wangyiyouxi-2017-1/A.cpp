#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 10010;
int cnt[N];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i < m; ++i) {
		int l, r;
		scanf("%d %d", &l, &r);
		for(int j = l - 1; j < r; ++j) {
			cnt[j] ^= 1;
		}
	}
	for(int i = 0; i < n; ++i) {
		printf("%d", cnt[i]);
	}
	return 0;
}