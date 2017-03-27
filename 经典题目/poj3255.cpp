//优先队列优化的dijkstra求次短路
//诡异的事情, priority_queue使用edge做元素加cmp, 很容易超时
//换成pair<int, int>就不超时, 150ms左右

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 5010;
const int INF = 0x3f3f3f3f;
int dist[N], dist2[N];
struct edge {
  int y, dis;
  edge(int y_, int dis_):y(y_), dis(dis_) {
  }
};
vector<edge> g[N];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
int n, m;

void solve() {
  //memset(dist, INF, sizeof(dist));
  //memset(dist2, INF, sizeof(dist2));
  for(int i = 0; i < n; ++i) {
    dist[i] = INF;
    dist2[i] = INF;
  }
  while(!pq.empty()) {
    pq.pop();
  }
  dist[0] = 0;
  pq.push(make_pair(0, 0));

  while(!pq.empty()) {
    pair<int, int> p = pq.top();
    pq.pop();
    int pv = p.second, d = p.first;

    if(dist2[pv] < d) continue;
    for(int i = 0; i < g[pv].size(); ++i) {
      edge v = g[pv][i];
      int d2 = d + v.dis;
      if(dist[v.y] > d2) {
        swap(dist[v.y], d2);
        pq.push(make_pair(dist[v.y], v.y));
      }
      if(dist2[v.y] > d2 && dist[v.y] < d2) {
        dist2[v.y] = d2;
        pq.push(make_pair(dist2[v.y], v.y));
      }
    }
  }

  printf("%d\n", dist2[n-1]);
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; ++i) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    g[x-1].push_back(edge(y-1, z));
    g[y-1].push_back(edge(x-1, z));
  }
  solve();
  return 0;
}
