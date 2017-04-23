#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int a[N];

struct trie {
	int cnt;
	trie* nxt[2];

	trie() {
		cnt = 0;
		memset(nxt, NULL, sizeof(nxt));
	}
};

void insert(trie *root, int val) {
	trie *p = root;
	for(int i = 31; i >= 0; --i) {
		int cur = (val >> i) & 0x01;
		if(p->nxt[cur] == NULL) {
			trie *q = new trie();
			p->nxt[cur] = q;
		}
		p = p->nxt[cur];
		p->cnt++;
	}
}

int Query(trie *root, int val, int m) {
	trie *p = root;
	int ans = 0;

	for(int i = 31; i >= 0; --i) {
		int cur = (m >> i) & 0x01;
		int CC = (val >> i) & 0x01;
		if(cur == 1) {
			p = p->nxt[CC^1];
		}
		else {
			if(p->nxt[CC^1]) {
				ans += p->nxt[CC^1]->cnt;
			}
			p = p->nxt[CC];
		}
		if(p == NULL) break;
	}
	return ans;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	trie *root = new trie();
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		insert(root, a[i]);
	}

	long long ans = 0;
	for(int i = 0; i < n; ++i) {
		ans += (long long)Query(root, a[i], m);
	}
	printf("%lld\n", ans>>1);
	return 0;
}
