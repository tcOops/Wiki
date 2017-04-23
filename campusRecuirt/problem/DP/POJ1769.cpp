//线段树优化dp
//先抽象出 状态转移方程, 发现需要找出MAX(dp[i] - dp[j])
//借助线段树, O(n*lg(n)) 维护和查询最大值， 使得复杂度从$O(n^2)$降到$O(n&lg(n))$

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 50010;
const int INF = 0x3f3f3f3f;
vector<pair<int, int> > sorter;
int dp[N<<2];

void pushUp(int idx) {
	dp[idx] = min(dp[idx<<1], dp[idx<<1|1]);
}

void build(int idx, int l, int r) {
	if(l == r) {
		dp[idx] = (l == 1 ? 0 : INF);
		return ;
	}

	int mid = (l + r) >> 1;
	build(idx<<1, l, mid);
	build(idx<<1|1, mid+1, r);
	pushUp(idx);
}

void upd(int idx, int l, int r, int pos, int val) {
	if(l == r) {
		dp[idx] = min(dp[idx], val);
		return ;
	}

	int mid = (l + r) >> 1;
	if(mid >= pos) {
		upd(idx<<1, l, mid, pos, val);
	}
	else {
		upd(idx<<1|1, mid+1, r, pos, val);
	}
	pushUp(idx);
}

int query(int idx, int l, int r, int L, int R) {
	if(L <= l && R >= r) {
		return dp[idx];
	}

	int mid = (l + r) >> 1;
	int ret = INF;
	if(L <= mid) {
		ret = query(idx<<1, l, mid, L, R);
	}
	if(mid+1 <= R) {
		ret = min(ret, query(idx<<1|1, mid+1, r, L, R));
	}
	return ret;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		sorter.push_back(make_pair(x, y));
	}

	build(1, 1, n);
	for(int i = 0; i < m; ++i) {
		int MIN = query(1, 1, n, sorter[i].first, sorter[i].second) + 1;
		MIN = min(MIN, query(1, 1, n, sorter[i].second, sorter[i].second));
		upd(1, 1, n, sorter[i].second, MIN);
	}

	int ans = query(1, 1, n, n, n);
	printf("%d\n", ans);
	return 0;
}
