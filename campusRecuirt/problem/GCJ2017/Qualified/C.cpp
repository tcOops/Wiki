#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

struct node {
	int val;
	node(int val_):val(val_) {}

	bool operator< (const node &rhs) const {
		return val < rhs.val;
	}
};

priority_queue<node> pq;

int main() {
	freopen("C-small2.in", "r", stdin);
	freopen("C-small2.out", "w", stdout);
	int T, cases = 1, n, k;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &n, &k);
		printf("Case #%d: ", cases++);
		while(!pq.empty()) pq.pop();
		pq.push(node(n));

		for(int i = 0; i < k - 1; ++i) {
			node pp = pq.top();
			pq.pop();

			int kk = (pp.val - 1) >> 1;
			if(kk != 0) pq.push(node(kk));
			if(kk != pp.val - 1) pq.push(node(pp.val - 1 - kk));
		}

		if(pq.empty()) {
			printf("0 0\n");
		}
		else {
			node pp = pq.top();
			int kk = (pp.val - 1) >> 1;
			printf("%d %d\n", (pp.val - 1 - kk), kk);
		}
	}
	return 0;
}