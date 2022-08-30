#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <vector>

const int MAXN = 3e3 + 10;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

char s[MAXN][MAXN];
int degree[MAXN][MAXN];

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<std::pair<int, int>> init;
    for (int i = 0; i < n; ++i) {
      scanf("%s", s[i]);
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == '^') {
          init.emplace_back(i, j);
        } else if (s[i][j] == '.') {
          s[i][j] = '^';
        }
      }
    }
    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s[i][j] != '^') {
          continue;
        }
        degree[i][j] = 0;
        for (int k = 0; k < 4; ++k) {
          int x = i + dir[k][0];
          int y = j + dir[k][1];
          if (x < 0 || x >= n || y < 0 || y >= m) {
            continue;
          }
          degree[i][j] += s[x][y] == '^';
        }
        if (degree[i][j] < 2) {
          q.emplace(i, j);
        }
      }
    }
    while (!q.empty()) {
      int i = q.front().first;
      int j = q.front().second;
      q.pop();
      if (s[i][j] == '.')
        continue;
      s[i][j] = '.';
      for (int k = 0; k < 4; ++k) {
        int x = i + dir[k][0];
        int y = j + dir[k][1];
        if (x < 0 || x >= n || y < 0 || y >= m || s[x][y] != '^') {
          continue;
        }
        if (--degree[x][y] < 2) {
          q.emplace(x, y);
        }
      }
    }
    bool ok = true;
    for (auto p : init) {
      if (s[p.first][p.second] == '.') {
        ok = false;
        break;
      }
    }
    printf("Case #%d: %s\n", t, ok ? "Possible" : "Impossible");
    if (ok) {
      for (int i = 0; i < n; ++i) {
        printf("%s\n", s[i]);
      }
    }
  }
  return 0;
}
