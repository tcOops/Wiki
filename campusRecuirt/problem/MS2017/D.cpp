#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 2000 + 5
#define K 10000
const int MOD = 1e9 + 7;

int len, Max, ans, Sum_1[N], Sum_2[N], Num_1[N], Num_2[N], q_1[N], q_2[N];
char s[N];

struct Big
{
	int num[N];
	Big () {memset(num, 0, sizeof(num)); num[0] = 1;}
	void set_1()
	{
		num[0] = num[1] = 1;
	}
	void clear()
	{
		while (num[0]) num[num[0] --] = 0;
	}
	void Update()
	{
		for (int i = 1; i < num[0]; i ++)
			if (num[i] >= K)
			{
				num[i + 1] += num[i] / K;
				num[i] %= K;
			}
		for (; num[num[0]] >= K; num[0] ++)
		{
			num[num[0] + 1] += num[num[0]] / K;
			num[num[0]] %= K;
		}
	}
	void Multi(int k)
	{
		for (int i = 1; i <= num[0]; i ++)
			num[i] *= k;
		this -> Update();
	}
	void Add(Big a)
	{
		num[0] = max(num[0], a.num[0]);
		for (int i = 1; i <= num[0]; i ++)
			num[i] += a.num[i];
		this -> Update();
	}
	Big operator * (Big a)
	{
		Big b;
		b.num[0] = num[0] + a.num[0] - 1;
		for (int i = 1; i <= num[0]; i ++)
			for (int j = 1; j <= a.num[0]; j ++)
			{
				b.num[i + j - 1] += num[i] * a.num[j];
				if (b.num[i + j - 1] >= K)
				{
					b.num[i + j] += b.num[i + j - 1] / K;
					b.num[i + j - 1] %= K;
				}
			}
		if (b.num[b.num[0] + 1]) b.num[0] ++;
		b.Update();
		return b;
	}
	void out()
	{
		printf("%d", num[num[0]]);
		for (int i = num[0] - 1; i; i --)
			printf("%04d", num[i]);
		puts("");
	}
}Ans, Dp_1[N], Dp_2[N];

int main()
{
	scanf("%s", s + 1);
	len = strlen(s + 1);
	for (int i = 1; i <= len; i ++)
	{
		Sum_1[i] = Sum_1[i - 1] + (s[i] == ')' ? 1 : -1);
		Num_1[i] = Num_1[i - 1] + (s[i] == ')');
		if (Sum_1[i] > q_1[0])
			q_1[++ q_1[0]] = Num_1[i];
	}
	Dp_1[0].set_1();
	for (int i = 1, t = 0; i <= q_1[q_1[0]]; i ++)
	{
		if (t <= q_1[0] && q_1[t + 1] == i) t ++;
		for (int j = max(t, 1); j <= q_1[0]; j ++)
			Dp_1[j].Add(Dp_1[j - 1]);
		for (int j = 0; j < t; j ++)
			Dp_1[j].clear();
	}
	for (int i = len; i; i --)
	{
		Sum_2[i] = Sum_2[i + 1] + (s[i] == '(' ? 1 : -1);
		Num_2[i] = Num_2[i + 1] + (s[i] == '(');
		if (Sum_2[i] > q_2[0])
			q_2[++ q_2[0]] = Num_2[i];
	}
	Dp_2[0].set_1();
	for (int i = 1, t = 0; i <= q_2[q_2[0]]; i ++)
	{
		if (t <= q_2[0] && q_2[t + 1] == i) t ++;
		for (int j = max(t, 1); j <= q_2[0]; j ++)
			Dp_2[j].Add(Dp_2[j - 1]);
		for (int j = 0; j < t; j ++)
			Dp_2[j].clear();
	}
	Ans = Dp_1[q_1[0]] * Dp_2[q_2[0]];
	printf("%d ", q_1[0] + q_2[0]);
	Ans.out();
	return 0;
}
