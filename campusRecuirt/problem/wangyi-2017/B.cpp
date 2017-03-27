#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
string s;
string a, b;

int main() {
	cin >> s;
	a = s, b = s;
	int n = s.size();
	int n1 = 0, n2 = 0;
	for(int i = 0; i < n; ++i) {
		if(s[i] == 'G') {
			++n1;
		}
		else {
			++n2;
		}
	}

	//case1
	int cnt = 0, ans;
	for(int i = 0; i < n1; ++i) {
		if(a[i] == 'B') {
			int j = i + 1;
			while(j < n && a[j] != 'G') {
				++j;
			}
		//	printf("%d %d\n", i, j);
			for(int k = j; k > i; --k) {
				char tmp = a[k];
				a[k] = a[k-1];
				a[k-1] = tmp;
				++cnt;
			}
		}
	}

	ans = cnt;
	cnt = 0;
	for(int i = 0; i < n2; ++i) {
		if(b[i] == 'G') {
			int j = i + 1;
			while(j < n && b[j] != 'B') {
				++j;
			}
			for(int k = j; k > i; --k) {
				char tmp = b[k];
				b[k] = b[k-1];
				b[k-1] = tmp;
				++cnt;
			}
		}
	}
	if(ans > cnt) {
		ans = cnt;
	}
	printf("%d\n", ans);
	return 0;
}
