// 离散化之后暴力处理一下
//AC
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int col[N];
bool vis[N];

struct node {
	int id, c;
	bool operator <(const node &rhs) const {
		return c < rhs.c;
	}
}b[N];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &b[i].c);
			b[i].id = i;
		}
		sort(b, b+n);
		int cnt = 0;
		for(int i = 0; i < n; ++i) {
			if(i == 0 || (b[i].c == b[i-1].c)) {
				col[b[i].id] = cnt;
			}
			else {
				col[b[i].id] = ++cnt;
			}
		}

		memset(vis, false, sizeof(vis));
		int ans = 0;
		for(int i = 0; i < n;) {
			int j = i;
			while(j < n && !vis[col[j]]) {
				vis[col[j]] = true;
				++j;
			}
			for(int k = i; k < j; ++k) {
				vis[col[k]] = false;
			}
			++ans;
			i = j;
		}
		printf("%d\n", ans);
	}
	return 0;
}