#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 110;
int fa[N];

int find(int x) {
	if(fa[x] != x) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		fa[i] = i;
	}

	for(int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		int fx = find(x);
		int fy = find(y);
		if(fx != fy) {
			fa[fx] = fy;
		}
	}

	int cnt = 0;
	for(int i = 1; i <= n; ++i) {
		if(fa[i] == i) {
			++cnt;
		}
	}
	printf("%d\n", cnt - 1);
	return 0;
}