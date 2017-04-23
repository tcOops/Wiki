#include <cstdio>
#include <cstring>
using namespace std;
const int N = 3e5 + 10;
int a[N], v[N];
int b[N], r[N];

int main() {
	int Q;
	long long M;
	scanf("%d %lld", &Q, &M);
	for(int i = 0; i < Q; ++i) {
		scanf("%d", &a[i]);
	}

	for(int i = 0; i < Q; ++i) {
		scanf("%d", &v[i]);
	}

	long long sum = 0;
	int cnt = 0, c = 0;
	for(int i = 0; i < Q; ++i) {
		int j;
		for(j = cnt-1; j >= 0; --j) {
			if(b[j] > a[i]) {
				b[j+1] = b[j];
				r[j+1] = r[j] + 1;
				sum += (long long)b[j+1]*v[r[j+1]] - (long long)b[j+1]*v[r[j]];
			}
			else {
				break;
			}
		}
		b[j+1] = a[i];
		if(j + 1 == 0) {
			r[j+1] = 0;
		}
		else {
			if(b[j+1] == b[j]) {
				r[j+1] = r[j];
			}
			else {
				r[j+1] = r[j] + 1;
			}
		}
		++cnt;
		sum += (long long)a[i]*r[j+1];
		if(sum > M) {
			cnt = 0;
			++c;
		}
		if(i != 0) {
			printf(" ");
		}
		printf("%d", c);
	}
	puts("");
	return 0;
}