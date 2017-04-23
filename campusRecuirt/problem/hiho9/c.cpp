#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 100010;
int son[N], tag[N], val[N];
vector<int> g[N];
long long avg;
long long ans = 0;
long long cnt = 0;
int root;

void dfs(int u) {
	son[u] = val[u];
	tag[u] = 0;
	for(auto v : g[u]) {
		dfs(v);
		son[u] += son[v];
		ans += (long long)1*tag[v]*tag[u]; //这里很重要， 表示以点v为区分，将树分成两部分， 保证选取的点在两颗不同的树上！ 以值来区分的话， 可能出现重复计算， 因为权值有可能<=0...
		tag[u] += tag[v];
	}
	if(son[u] == avg*2 && u != root) {
		ans += tag[u];
	}
	if(son[u] == avg) {
		++cnt;
		tag[u]++;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			g[i].clear();
		}

		long long sum = 0;
		for(int i = 1; i <= n; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			sum += x;
			val[i] = x;
			if(y) {
				g[y].push_back(i);
			}
			else {
				root = i;
			}
		}
		if(sum%3) {
			printf("0\n");
			continue;
		}
		avg = sum/3;
		ans = 0, cnt = 0;
		dfs(root);
	//	ans += cnt*(cnt-1)/2;
		printf("%lld\n", ans);
	}
	return 0;
}