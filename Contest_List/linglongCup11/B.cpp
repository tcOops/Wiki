#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int N = 510;
bool vis[N][N];
int rl, rr, cl, cr;
int fx[4] = {0, 0, 1, -1};
int fy[4] = {1, -1, 0, 0};
int m, n;
char mz[N][N];

void dfs(int x, int y) {
  vis[x][y] = true;
  if(x < rl) {
    rl = x;
  }
  if(x > rr) {
    rr = x;
  }
  if(y < cl) {
    cl = y;
  }
  if(y > cr) {
    cr = y;
  }

  for(int i = 0; i < 4; ++i) {
    int newx = x + fx[i];
    int newy = y + fy[i];
    if(newx < 0 || newx >= m || newy < 0 || newy >= n) continue;
    if(vis[newx][newy] || mz[newx][newy] == '0') continue;
    dfs(newx, newy);
  }
}

int main() {
  scanf("%d %d", &m, &n);
  for(int i = 0; i < m; ++i) {
    scanf("%s", &mz[i]);
  }

  memset(vis, false, sizeof(vis));

  for(int j = 0; j < n; ++j) {
    for(int i = 0; i < n; ++i) {
      if(mz[i][j] == '1' && !vis[i][j]) {
        rl = 0x3f3f3f3f;
        rr = -1;
        cl = 0x3f3f3f3f;
        cr = -1;
        dfs(i, j);
        printf("%d %d\n", rr-rl+1, cr-cl+1);
        for(int x = rl; x <= rr; ++x) {
          for(int y = cl; y <= cr; ++y) {
            printf("%c", mz[x][y]);
          }
          puts("");
        }
      }
    }
  }
  return 0;
}
