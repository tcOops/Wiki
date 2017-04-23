#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
string ss;

int main() {
	while(getline(cin, ss)) {
		int n = ss.size();
		string ans = "";
		for(int i = 0; i < n;) {
			if(ss[i] == ' ') {
				++i;
				continue;
			}
			int j = i;
			string res = "";
			while(j < n && ss[j] != ' ') {
				res += ss[j++];
			}
			reverse(res.begin(), res.end());
			if(ans != "") {
				ans += ' ';
			}
			ans += res;
			i = j;
		}
		cout << ans << endl;
	}
	return 0;
}