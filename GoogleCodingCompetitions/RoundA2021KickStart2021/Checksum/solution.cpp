#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <vector>

const int N = 510;

int n;
int b[N][N];
std::vector<std::pair<int, int>> edge[N * 2];
bool vis[N * 2];
int dis[N * 2];

void dfs(int u) {
  vis[u] = true;
  for (auto &[v, _] : edge[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d", &n);
    for (int i = 1; i <= n + n; ++i) {
      edge[i].clear();
      vis[i] = false;
      dis[i] = INT_MIN;
    }

    for (int i = 1, x; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        scanf("%d", &x);
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        scanf("%d", &b[i][j]);
        ans += b[i][j];
        if (b[i][j]) {
          edge[i].emplace_back(j + n, b[i][j]);
          edge[j + n].emplace_back(i, b[i][j]);
        }
      }
    }

    for (int i = 1, x; i <= n; ++i) {
      scanf("%d", &x);
    }
    for (int i = 1, x; i <= n; ++i) {
      scanf("%d", &x);
    }

    for (int i = 1; i <= n + n; ++i) {
      if (!vis[i]) {
        dis[i] = 0;
        dfs(i);
      }
    }

    for (int i = 1; i <= n + n; ++i) {
      vis[i] = false;
    }

    for (int _ = 1; _ <= n + n; ++_) {
      int u = -1, max_dis = INT_MIN;
      for (int i = 1; i <= n + n; ++i) {
        if (vis[i]) {
          continue;
        }
        if (dis[i] > max_dis) {
          max_dis = dis[i];
          u = i;
        }
      }
      vis[u] = true;
      ans -= max_dis;
      for (auto &[v, w] : edge[u]) {
        dis[v] = std::max(dis[v], w);
      }
    }

    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
