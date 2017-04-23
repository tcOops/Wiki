//二维树状数组求和

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1010;

int n, m;
long long c[N][N];
#define lowbit(x) (x & (-x))

void add(int r, int c_, int val) {
  for(int x = r; x <= n; x += lowbit(x)) {
    for(int y = c_; y <= n; y += lowbit(y)) {
      c[x][y] += val;
    }
  }
}

long long getSum(int r, int c_) {
  long long ret = 0;
  for(int x = r; x > 0; x -= lowbit(x)) {
    for(int y = c_; y > 0; y -= lowbit(y)) {
      ret += c[x][y];
    }
  }
  return ret;
}

long long getSum(int tr, int tc, int br, int bc) {
  long long ret = 0;
  ret = (getSum(br, bc) - getSum(br, tc-1) - getSum(tr-1, bc) + getSum(tr-1, tc-1)) % MOD;
  ret = (ret + MOD) % MOD;
  return ret;
}

int main() {
  scanf("%d %d", &n, &m);

  memset(c, 0, sizeof(c));
  for(int i = 0; i < m; ++i) {
    string op; cin >> op;
    if(op[0] == 'A') {
      int x, y, z;
      scanf("%d %d %d", &x, &y, &z);
      ++x, ++y;
      add(x, y, z);
    }
    else {
      int x1, y1, x2, y2;
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      ++x1, ++y1, ++x2, ++y2;
      printf("%lld\n", getSum(x1, y1, x2, y2));
    }
  }
  return 0;
}
