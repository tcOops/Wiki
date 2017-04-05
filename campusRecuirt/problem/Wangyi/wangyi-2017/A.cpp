#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int N = 51;
int a[N];
bool vis[N];
int n;

bool dfs(int idx, int sum, int tag, int cnt) {
	if(cnt == 2) {
		return true;
	}

	for(int i = idx; i >= 0; --i) {
		if(vis[i]) continue;
		if(sum + a[i] == tag) {
			vis[i] = true;
			if(dfs(n-1, 0, tag, cnt+1)) {
				return true;
			}
			vis[i] = false;
		}
		else if(sum + a[i] < tag) {
			vis[i] = true;
			if(dfs(i-1, sum+a[i], tag, cnt)) {
				return true;
			}
			vis[i] = false;
			while(i + 1 < n && a[i+1] == a[i]) {
				++i;
			}
		}
	}
	return false;
}


int main() {
	scanf("%d", &n);
	int sum = 0;
	for(int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &a[i]);
		sum += a[i];
	}
	sort(a, a+n);

	bool suc = false;
	int upper = min(sum>>1, 500000);
	for(int i = upper; i >= 0; --i) {
	//	printf("%d\n", i);
		memset(vis, false, sizeof(vis));
		if(dfs(n-1, 0, i, 0)) {
			printf("%d\n", i);
			suc = true;
			break;
		}
	}
	if(!suc) {
		printf("-1\n");
	}
	return 0;
}


