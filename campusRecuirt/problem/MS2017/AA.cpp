//TLE, 暴力dfs
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 110;
int p, q, n;
double ans;

void solve(int cur, double sum, int cnt, int dep) {
	if(cnt == n) {
		ans += sum*dep;
		return;
	}

	int nxtP = p / (1<<(cnt+1));
	if(cur) {
		solve(nxtP, sum*cur/100.0, cnt+1, dep+1);
	}
	if(cur < 100) {
		nxtP = min(100, cur+q);
		solve(nxtP, sum*(100-cur)/100.0, cnt, dep+1);
	}
}

int main() {
	scanf("%d %d %d", &p, &q, &n);
	ans = 0.0;
	solve(p, 1.0, 0, 0);
	printf("%.2lf\n", ans);
	return 0;
}