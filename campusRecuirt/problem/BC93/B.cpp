//脑洞题， 不过最后贪心的细节没想清楚
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1d5 + 10;
int a[N], t[3];
int p[N], sum1[N], sum2[N];

int main() {
	int T, n, k;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &n, &k);
		int sum = 0, cnt = 0;
		for(int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			t[x%3]++;
			sum += x%3;
			if(x%3 == 0) {
				p[cnt++] = i;
				if(i == 0) {
					sum1[i] = 0;
					sum2[i] = 0;
				}
				else {
					sum1[i] = sum1[i-1];
					sum2[i] = sum2[i-1];
				}
			}
			else {
				if(i == 0) {
					if(x%3 == 1) {
						sum1[i] = 1;
					}
					else {
						sum2[i] = 1;
					}
				}
				else {
					if(x%3 == 1) {
						sum1[i] = sum1[i-1] + 1;
					}
					else {
						sum2[i] = sum2[i-1] + 1;
					}
				}
			}
		}

		sum %= 3;
		bool suc = false;
		for(int i = min(k, t[0]); i >= 0;) {
			if(t[1] + t[2] < k - i) break;
			int z = 3 + sum - (k - i);
			int pos = p[i];
			if(i < cnt && sum1[pos] + sum2[pos] == 0) {
				continue;
			}
			int upper = 2*min(k-i, t[2]-sum2[pos]) + (k - i - min(k-i, t[2]-sum2[pos]));
			int lower = min(k-i, t[1]-sum1[pos]) + (k - i - min(k-i, t[1]-sum1[pos]))*2;
			if(upper - lower >= 3) {
				suc = true;
				break;
			}
			else {
				for(int k = lower; k <= upper; ++k) {
					int mod = k%3;
					int diff = (sum + 3 - mod)%3;
					if(diff == 0) {
						suc = true;
						break;
					}
				}
				if(suc) break;
			}
		}
	}
}