#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int N = 3e5 + 10;
int a[N];

int main() {
	int n, m;
	while(~scanf("%d %d", &n, &m)) {
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}	
		for(int i = 0; i < m; ++i) {
			string op;
			int x, y;
			cin >> op;
			scanf("%d %d", &x, &y);
			if(op[0] == 'U') {
				a[x-1] = y;
			}
			else {
				int Ans = 0;
				if(x > y) swap(x, y);
				for(int j = x-1; j < y; ++j) {
					if(a[j] > Ans) {
						Ans = a[j];
					}
				}
				printf("%d\n", Ans);
			}
		}
	}
	return 0;
}