#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 100010;
int bit[32];
int zero = 0;

struct trie {
	int cnt;
	trie* nxt[2];
	trie() {
		memset(nxt, NULL, sizeof(nxt));
		cnt = 0;
	}
};
trie mask[N];

void insert(trie *root, string ip, int type) {
	int len = ip.size();
	bool flag = false;
	int i = 0, n = len;
	for(i = 0; i < len; ++i) {
		if(ip[i] == '/') {
			flag = true;
			n = i;
			break;
		}
	}
	int ss = 0;
	++i;
	for(; i < len; ++i) {
		ss = ss*10 + ip[i] - '0';
	}
	if(ss == 0) zero = type;

	int cnt = 0;
	for(int i = 0; i < n;) {
		int s = 0, j = i;
		while(j < n && ip[j] != '.') {
			s = s*10 + ip[j] - '0';
			++j;
		}
		for(int k = 7; k >= 0; --k) {
			bit[cnt++] = (s>>k) & 0x01;
		}
		i = j + 1;
	}

	trie *p = root;
	for(int i = 0; i < 32; ++i) {
		if(p->nxt[bit[i]] == NULL) {
			trie *q = new trie;
			p->nxt[bit[i]] = q;
		}
		p = p->nxt[bit[i]];
		if(i == ss - 1) {
			p->cnt = type;
		}
	}
	if(!flag) p->cnt = type;
}

bool query(trie *root, string ip) {
	int len = ip.size(), cnt = 0;
	for(int i = 0; i < len;) {
		int j = i, s = 0;
		while(j < len && ip[j] != '.') {
			s = s*10 + ip[j] - '0';
			++j;
		}

		for(int k = 7; k >= 0; --k) {
			bit[cnt++] = (s>>k) & 0x01;
		}
		i = j + 1;
	}

	trie *p = root;
	for(int i = 0; i < 32; ++i) {
		p = p->nxt[bit[i]];
		if(p == NULL) {
			if(zero == 2) return false;
			return true;
		}
		if(p->cnt == 1) {
			return true;
		}
		else if(p->cnt == 2) {
			return false;
		}
	}
	if(zero == 2) return false;
	return true;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	string op, ip;
	trie *root = new trie;
	for(int i = 0; i < n; ++i) {
		cin >> op >> ip;
		if(op == "allow") {
			insert(root, ip, 1);
		}
		else {
			insert(root, ip, 2);
		}
	}

	cout << zero << endl;
	for(int i = 0; i < m; ++i) {
		cin >> ip;
		if(query(root, ip)) {
			puts("YES");
		}
		else {
			puts("NO");
		}
	}
	return 0;
}
