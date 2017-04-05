#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int prime[N];
bool isPrime[N];
int cnt = 0;

void pre() {
	memset(isPrime, true, sizeof(isPrime));
	for(int i = 2; i * i < N; ++i) {
		if(isPrime[i]) {
			for(int j = i*i; j < N; j += i) {
				isPrime[j] = false;
			}
		}
	}

	for(int i = 2; i < N; ++i) {
		if(isPrime[i]) {
			prime[cnt++] = i;
		}
	}
}

int main() {
	pre();
	int n;
	scanf("%d", &n);

	for(int i = 0; prime[i] <= n/2; ++i) {
		int j = n - prime[i];
		int pos = lower_bound(prime, prime+cnt, j) - prime;
		if(pos < cnt) {
			if(prime[pos] == j) {
				printf("%d %d\n", prime[i], j);
				break;
			}
		}
	}
	return 0;
}