#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100 + 5
#define mp make_pair

int n, m, k, Num[N], q[N], Fa[N], Dep[N], Pos[N], Ord[N], T[N], A[N][N], Map[N][N];
bool Flag[N];

bool cmp(int u, int v)
{
	return mp(Pos[q[u]], Dep[q[u]]) < mp(Pos[q[v]], Dep[q[v]]);
}

bool Check(int u, int v, int w)
{
	if (Dep[q[u]] > Dep[q[w]] && Dep[q[u]] - Dep[q[w]] == Map[u][w]) return 0;
	int d_0 = Dep[q[u]] + Dep[q[v]] - Map[u][v] >> 1;
	int d_1 = Dep[q[u]] + Dep[q[w]] - Map[u][w] >> 1;
	return d_0 < d_1;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i ++)
		scanf("%d", Num + i);
	for (int i = 1; i <= m; i ++)
		for (int j = 0; j < Num[i]; j ++)
		{
			scanf("%d", A[i] + j);
			Dep[A[i][j]] = i, Pos[A[i][j]] = j;
		}
	for (int i = 1; i <= k; i ++)
	{
		scanf("%d", q + i);
		Flag[q[i]] = 1, Ord[i] = i;
	}
	for (int i = 1; i <= k; i ++)
		for (int j = 1; j <= k; j ++)
			scanf("%d", Map[i] + j);
	sort(Ord + 1, Ord + k + 1, cmp);
	for (int i = 1; i < k; i ++)
		for (int j = i + 2; j <= k; j ++)
			if (Check(Ord[i], Ord[j - 1], Ord[j]))
				swap(Ord[j - 1], Ord[j]);
	for (int i = 1, Max = 0; i <= k; i ++)
	{
		int d = Dep[q[Ord[i]]], _d;
		if (i == 1)
		{
			Max = max(Max, d);
			for (; d > 1; d --)
				Fa[A[d][T[d]]] = A[d - 1][T[d - 1]];
			continue ;
		}
		for (_d = d; _d > 1; _d --)
		{
			if (Dep[q[Ord[i]]] + Dep[q[Ord[i - 1]]] - 2 * _d >= Map[Ord[i - 1]][Ord[i]]) break ;
			if (_d <= Max) T[_d] ++;
		}
		Max = max(Max, d);
		for (; d > _d; d --)
			Fa[A[d][T[d]]] = A[d - 1][T[d - 1]];
	}
	for (int i = 1; i <= n; i ++)
		printf("%d%c", Fa[i], i == n ? '\n' : ' ');
	return 0;
}

