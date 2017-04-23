#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <set>
using namespace std;
char a[6] = {'a', 'e', 'i', 'o', 'u', 'y'};

int main() {
	set<char> st;
	for(int i = 0; i < 6; ++i) {
		st.insert(a[i]);
	}

	string ss;
	cin >> ss;
	int n = ss.size();
	bool suc = true;
	for(int i = 1; i < n; ++i) {
		if(ss[i] == ss[i-1]) {
			suc = false;
			break;
		}
		if(st.count(ss[i]) && st.count(ss[i-1])) {
			suc = false;
			break;
		}
	}
	puts(suc ? "Yes" : "No");
	return 0;
}