//n(1e6)个数，m(1e6)个查询，每个查询求[l,r]出现偶数次的数xor
//一种思维模式: 离线查询, 对所有的query排序之后进行离线
//转换问题：偶数次数的xor = sum(xor) ^ 出现过的数的xor, 借助树状数组快速统计
//统计区间出现过的数字时，注意a[i]位置的更新，因为之前这个数字已经出现过， 所以要将之前的位置抹去(xor一遍) 

#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
#define lowbit(x) (x & (-x))
const int N = 1e6 + 10;
int a[N], sum[N], C[N], ans[N];
map<int, int> mp;
int n, m;

struct Q {
	int id;
	int l, r;
	bool operator < (const Q &rhs) const {
		if(r == rhs.r) return l < rhs.l;
		return r < rhs.r;
	}
}Query[N];

void upd(int pos, int val) {
	while(pos <= n) {
		C[pos] ^= val;
		pos += lowbit(pos);
	}
}

int query(int pos) {
	int ret = 0;
	while(pos) {
		ret ^= C[pos];
		pos -= lowbit(pos);
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	sum[0] = 0;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		sum[i] = sum[i-1] ^ a[i];
	}

	scanf("%d", &m);
	for(int i = 0; i < m; ++i) {
		scanf("%d %d", &Query[i].l , &Query[i].r);
		Query[i].id = i;
	}

	sort(Query, Query + m);
	memset(C, 0, sizeof(C));
	mp.clear();

	int idx = 0;
	for(int i = 1; i <= n; ++i) {
		if(mp[a[i]]) {//更新a[i]的位置
			upd(mp[a[i]], a[i]);
		}
		mp[a[i]] = i;
		upd(i, a[i]);

		if(Query[idx].r == i) {
			while(idx < m && Query[idx].r == i) {
				int XOR = sum[i] ^ query(i);
				int l = Query[idx].l;
				XOR ^= (sum[l-1] ^ query(l-1));
				ans[Query[idx].id] = XOR, ++idx;
			}
			if(idx == m) break;
		} 
	}

	for(int i = 0; i < m; ++i) {
		printf("%d ", ans[i]);
	}
	return 0;
}

