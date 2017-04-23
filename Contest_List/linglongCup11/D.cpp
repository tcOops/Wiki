#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
const int N = 1e3 + 10;
const int MOD = 1e9 + 7;
long long dp[N][N][2];
int mz[N][N];

int main() {
  int m, n, k;
  scanf("%d %d %d", &m, &n, &k);
  memset(mz, 0, sizeof(mz));
  for(int i = 1; i <= k; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    mz[x][y] = 1;
  }

  for(int i = 0; i <= n; ++i) {
    dp[0][i][0] = dp[0][i][1] = 0;
  }
  for(int i = 0; i <= m; ++i) {
    dp[i][0][0] = dp[i][0][1] = 0;
  }

  long long ans = 0;
  for(int i = 1; i <= m; ++i) {
    for(int j = 1; j <= n; ++j) {
      if(mz[i][j] == 1) {
        dp[i][j][0] = 0;
        dp[i][j][1] = 0;
      }
      else {
          dp[i][j][1] = dp[i-1][j][1] + 1;
          dp[i][j][0] = dp[i][j-1][0] + 1;
          ans += dp[i][j][0]*dp[i][j][1];
      }
    }
  }
  cout << ans << endl;
  return 0;
}
