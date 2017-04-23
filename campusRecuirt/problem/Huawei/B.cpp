#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct node {
	pair<string, int> file;
	int cnt, first;

	node(pair<string, int> a, int cnt_, int first_) {
		file = a, cnt = cnt_, first = first_;
	}

	bool operator<(const node &rhs) const {
		if(cnt == rhs.cnt) return first < rhs.first;
		return cnt > rhs.cnt;
	}
};

map<pair<string, int>, pair<int, int> > mp;
vector<node> files;

int min(int a, int b) {
	return a < b ? a : b;
}

int max(int a, int b) {
	return a + b - min(a, b);
}

int main() {
	string ff;
	int number, cur = 0;
	while(cin >> ff >> number) {
		++cur;
		int n = ff.size();
		string fn = "";
		for(int i = n - 1; ff[i] != '\\'; --i) {
			fn += ff[i];
		}
		reverse(fn.begin(), fn.end());
		if(mp.find(make_pair(fn, number)) == mp.end()) {
			mp[make_pair(fn, number)] = make_pair(1, cur);
		}
		else {
			pair<int, int> res = mp[make_pair(fn, number)];
			mp[make_pair(fn, number)] = make_pair(res.first + 1, res.second);
		}
	}

	map<pair<string, int>, pair<int, int> >::iterator it;
	for(it = mp.begin(); it != mp.end(); ++it) {
		files.push_back(node(it->first, (it->second).first, (it->second).second));
	}
	sort(files.begin(), files.end());
	for(int i = 0; i < min(files.size(), 8); ++i) {
		string fn = files[i].file.first;
		for(int j = max(fn.size() - 16, 0); j < fn.size(); ++j) {
			printf("%c", fn[j]);
		}
		printf(" %d ", files[i].file.second);
		printf("%d\n", files[i].cnt);
	}
	return 0;
}