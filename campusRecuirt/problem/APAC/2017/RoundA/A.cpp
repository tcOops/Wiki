#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

string a;
int cnt[128];

int main() {
	cin >> a;
	int n = a.size();
	memset(cnt, 0, sizeof(cnt));

	int sum = 0;
	for(int i = 0; i < n; ++i) {
		cnt[a[i]]++;
		sum++;
	}

	double ans 0.0;
	for (int i = 0; i < 128; i++) {
		double p = 1.0 * cnt[i] / sum;
		if (p > 0) {
			ans += -(p * log(p) / log(2));
		} 
    }  
    printf("%.7lf\n", ans);
    return 0;
}
