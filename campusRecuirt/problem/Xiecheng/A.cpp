#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

string a;
int cnt[256];

int main() {
	cin >> a;
	int n = a.size();
	memset(cnt, 0, sizeof(cnt));

	int sum = 0;
	for(int i = 0; i < n; ++i) {
		cnt[a[i]]++;
		sum++;
	}

	double ans = 0.0;
	for (int i = 0; i < 256; i++) {
		double p = 1.0 * cnt[i] / sum;
		if (cnt[i]) {
			ans += -(p * log(p) / log(2));
		} 
    }  
    if((ans - (int)ans) < 1e-5) {
    	printf("%d\n", (int)ans);
    }
    else {
    	printf("%.7lf\n", ans);
    }
    return 0;
}
