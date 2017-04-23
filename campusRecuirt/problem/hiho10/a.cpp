#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
string record;

int main() {
	int n;
	scanf("%d", &n);
	while(n--) {
		cin >> record;
		int n = record.size();
		bool suc = true;
		int cnt = 0;
		for(int i = 0; i < n; ++i) {
			if(record[i] == 'A') {
				++cnt;
				if(cnt > 1) {
					suc = false;
					break;
				}
			}
			else if(record[i] == 'L') {
				if(i + 2 < n && record[i+1] == 'L' && record[i+2] == 'L') {
					suc = false;
					break;
				}
			}
		}
		if(suc) puts("YES");
		else puts("NO");
	}
	return 0;
}
