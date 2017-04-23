#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
map<string, int> mp;

string s;

int main() {
	while(getline(cin, s)) {
		int len = s.size();
		for(int i = 0; i < len;) {
			if(s[i] > 'z' || s[i] < 'A' || (s[i] > 'Z' && s[i] < 'a'))  {
				++i;
				continue;
			}
			int j = i;
			string res = "";
			while(j < len && ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z'))) {
				res += s[j++];
			}
			mp[res]++;
			i = j;
		}
	}
	map<string, int>::iterator it;
	for(it = mp.begin(); it != mp.end(); ++it) {
		cout << it->first << " " << it->second << endl;
	}
}