#include <cstdio>
#include <algorithm>
using namespace std;
typedef long double LD;
const int N = 1e2 + 10;

int p, q, n;
LD ans, Ans[N];
bool Flag[N];

LD Get(int cur)
{
	if (Flag[cur]) return Ans[cur];
	if (cur == 100) return 1;
	Flag[cur] = 1;
	LD res = (LD) cur / 100;
	res += (LD) (100 - cur) / 100 * (Get(min(cur + q, 100)) + 1);
	return Ans[cur] = res;
}

int main()
{
	scanf("%d%d%d", &p, &q, &n);
	for (int i = 1; i <= n; i ++, p >>= 1)
		ans += Get(p);
	printf("%.2f\n", (double) ans);
	return 0;
}
