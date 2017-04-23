#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int N = 3e6 + 10;
set<int> st;

struct node {
	int id, val;
	bool operator< (const node &rhs) const {
		return val < rhs.val;
	}
}a[N], b[N];

struct ans {
	int id, val;
	ans(int id_, int val_) {
		id = id_;
		val = val_;
	}
	bool operator< (const ans &rhs) const {
		return id < rhs.id;
	}
};
vector<ans> Ans;

int main() {
	/*
	int n, m;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i].val);
		a[i].id = i;
	}

	scanf("%d", &m);
	for(int i = 0; i < m; ++i) {
		scanf("%d", &b[i].val);
		b[i].id = i;
	}

	sort(a, a+n);
	sort(b, b+m);

	int idx = 0;
	for(int i = 0; i < m && idx < n;) {
		if(a[idx].val == b[i].val) {
			Ans.push_back(ans(b[i].id, b[i].val));
			++idx, ++i;
		}
		else if(a[idx].val > b[i].val) {
			++i;
		}
		else {
			++idx;
		}
	}

	sort(Ans.begin(), Ans.end());
	for(int i = 0; i < Ans.size(); ++i) {
		printf("%d ", Ans[i].val);
	}
	*/

    int m, n, x;

    scanf("%d", &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d", &x);
        st.insert(x);
    }

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        if(st.find(x) != st.end()) {
            printf("%d ", x);
        }
    }


	return 0;
}