#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

const int N = 1e3 + 10;

int n, m;
char s[N][N];
std::vector<std::pair<int, int>> edge[N][N];
int up[N][N], down[N][N], left[N][N], right[N][N];
bool vis[N][N];

int dfs(int u, int v, char t) {
  int ret = 0;
  if (s[u][v] == '.') {
    s[u][v] = t;
    ++ret;
  }
  vis[u][v] = true;
  for (auto [_u, _v] : edge[u][v]) {
    if (vis[_u][_v])
      continue;
    ret += dfs(_u, _v, t);
  }
  return ret;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%s", s[i] + 1);
      for (int j = 1; j <= m; ++j) {
        edge[i][j].clear();
        vis[i][j] = false;
      }
    }

    for (int i = 0; i <= n + 1; ++i) {
      for (int j = 0; j <= m + 1; ++j) {
        up[i][j] = down[i][j] = left[i][j] = right[i][j] = 0;
      }
    }

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (s[i][j] == '#') {
          continue;
        }
        up[i][j] = up[i - 1][j] + 1;
        left[i][j] = left[i][j - 1] + 1;
      }
    }

    for (int i = n; i; --i) {
      for (int j = m; j; --j) {
        if (s[i][j] == '#') {
          continue;
        }
        down[i][j] = down[i + 1][j] + 1;
        right[i][j] = right[i][j + 1] + 1;
      }
    }

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (s[i][j] == '#') {
          continue;
        }
        int left_most = j - left[i][j] + 1;
        int right_most = j + right[i][j] - 1;
        int _j = left_most + right_most - j;
        if (_j != j) {
          edge[i][j].push_back({i, _j});
          edge[i][_j].push_back({i, j});
        }

        int up_most = i - up[i][j] + 1;
        int down_most = i + down[i][j] - 1;
        int _i = up_most + down_most - i;
        if (_i != i) {
          edge[i][j].push_back({_i, j});
          edge[_i][j].push_back({i, j});
        }
      }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (std::isupper(s[i][j])) {
          ans += dfs(i, j, s[i][j]);
        }
      }
    }

    printf("Case #%d: %d\n", t, ans);
    for (int i = 1; i <= n; ++i) {
      printf("%s\n", s[i] + 1);
    }
  }
  return 0;
}
