#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
const int N = 100010;
vector<string> res, ans;
string ss;
map<string, int> mp;

struct trie {
	int val;
	trie *nxt[128];
	trie() {
		val = 0;
		memset(nxt, NULL, sizeof(nxt));
	}
};

void insert(trie *root, string s) {
	int len = s.size();
	trie *p = root;
	for(int i = 0; i < len; ++i) {
		int val = s[i];
		if(p->nxt[val] == NULL) {
			trie *q = new trie();
			p->nxt[val] = q;
		}
		p = p->nxt[val];
	}
	p->val = 1;
}

bool query(trie *root, string a) {
	int len = a.size();
	trie *p = root;
	for(int i = 0; i < len; ++i) {
		int val = a[i];
		p = p->nxt[val];
	}
	return p->val;
}

bool solve(trie *root, string s) {
	int len = s.size();
	trie *p = root;
	for(int i = 0; i < len; ++i) {
		int val = s[i];
		p = p->nxt[val];
		if(p->val == 1) {
			if(query(root, s.substr(i+1))) {
				return true;
			}
		}
	}
	return false;
}

int main() {
    int n;
    scanf("%d", &n);
    trie *root = new trie;

    for(int i = 0; i < n; ++i) {
        cin >> ss;
        insert(root, ss);
        res.push_back(ss);
    }

 	for(int i = 0; i < n; ++i) {
 		if(solve(root, res[i])) {
 			ans.push_back(res[i]);
 		}
 	}
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}

