//期望的线性可加, 转化为sigma(Exp(i)) (1<= i <= n)

//非递归
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int p, q, n;

int main() {
	scanf("%d %d %d", &p, &q, &n);
	double ans = 0.0;
	for(int i = 1; i <= n; ++i) {
		int cur = p;
		double res = 0.0, tp = 1.0;
		int cnt = 0;
		while(1) {
			++cnt;
			res += tp*cur*cnt/100.0;
			if(cur < 100) {
				tp = tp*(100-cur)/100.0;
				cur = min(cur + q, 100);
			}
			else {
				break;
			}
		}

		ans += res;
		p >>= 1;
	}
	printf("%.2lf\n", ans);
	return 0;
}



//递归
/*
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int p, q, n;
double ans, dp[110];
bool vis[110];

double solve(int cur) {
	if(cur == 100) return 1.0;
	if(vis[cur]) {
		return dp[cur];
	}

	vis[cur] = true;
	double res = p/100.0;
	res += (100 - cur)/100.0 * (solve(min(cur+q, 100)) + 1);
	return (dp[cur] = res);
}

int main() {
	scanf("%d %d %d", &p, &q, &n);
	ans = 0.0;
	memset(vis, false, sizeof(vis));
	for(int i = 1; i <= n; ++i) {
		ans += solve(p);
		p >>= 1;
	}
	printf("%.2lf\n", ans);
	return 0;
}
*/
