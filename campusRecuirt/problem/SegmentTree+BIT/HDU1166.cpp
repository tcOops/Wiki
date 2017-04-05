//线段树恢复第一弹, 单点更新

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int N = 50010;
int a[N], sum[N<<2];

void pushUp(int idx) {
	sum[idx] = sum[idx<<1] + sum[idx<<1|1];
}

void build(int idx, int l, int r) {
	if(l == r) {
		sum[idx] = a[l];
		return ;
	}

	int mid = (l + r) >> 1;
	build(idx<<1, l, mid);
	build(idx<<1|1, mid+1, r);
	pushUp(idx);
}

void upd(int idx, int l, int r, int pos, int val) {
	if(l == r) {
		sum[idx] += val;
		return ;
	}

	int mid = (l + r) >> 1;
	if(pos <= mid) {
		upd(idx<<1, l, mid, pos, val);
	}
	else {
		upd(idx<<1|1, mid+1, r, pos, val);
	}
	pushUp(idx);
}

int query(int idx, int l, int r, int L, int R) {
	if(l >= L && r <= R) {
		return sum[idx];
	}

	int mid = (l + r) >> 1;
	int res = 0;
	if(mid >= L) {
		res += query(idx<<1, l, mid, L, R);
	}
	if(mid + 1 <= R) {
		res += query(idx<<1|1, mid+1, r, L, R);
	}
	return res;
}

int main() {
	int T, n, cases = 1;
	string type;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		build(1, 1, n);

		int x, y;
		printf("Case %d:\n", cases++);
		while(cin >> type) {
			if(type == "Query") {
				scanf("%d %d", &x, &y);
				int ans = query(1, 1, n, x, y);
				printf("%d\n", ans);
			}
			else if(type == "Add") {
				scanf("%d %d", &x, &y);
				upd(1, 1, n, x, y);
			}
			else if(type == "Sub") {
				scanf("%d %d", &x, &y);
				upd(1, 1, n, x, -y);
			}
			else {
				break;
			}
		}
	}
	return 0;
}