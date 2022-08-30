#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <vector>

long long dp[25][11][11][1100];

int n, p, m, ar, ac;
int dir[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
char op[4][2];
int K[4];
std::pair<int, int> map[20][20];

long long divide(long long a, long long b) {
  return a / b - ((a ^ b) < 0 && a % b);
}

long long toll(long long now, int k) {
  switch (op[k][0]) {
  case '+':
    return now + K[k];
  case '-':
    return now - K[k];
  case '*':
    return now * K[k];
  case '/':
    return divide(now, K[k]);
  }
  return -1;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d%d%d%d%d", &n, &p, &m, &ar, &ac);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        map[i][j] = {-1, -1};
      }
    }
    for (int i = 0; i < 4; ++i) {
      scanf("%s%d", op[i], K + i);
    }
    for (int i = 0; i < p; ++i) {
      int x, y, c;
      scanf("%d%d%d", &x, &y, &c);
      map[x][y] = {i, c};
    }
    for (int i = 0; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        for (int k = 1; k <= n; ++k) {
          for (int s = 0; s < (1 << p); ++s) {
            dp[i][j][k][s] = LONG_MIN;
          }
        }
      }
    }
    dp[0][ar][ac][0] = 0;
    for (int i = 0; i < m; ++i) {
      for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= n; ++y) {
          for (int s = 0; s < (1 << p); ++s) {
            if (dp[i][x][y][s] == LONG_MIN) {
              continue;
            }
            long long now = dp[i][x][y][s];
            for (int k = 0; k < 4; ++k) {
              int _x = x + dir[k][0];
              int _y = y + dir[k][1];
              if (_x < 1 || _x > n || _y < 1 || _y > n) {
                continue;
              }
              long long tmp = toll(now, k);
              dp[i + 1][_x][_y][s] = std::max(dp[i + 1][_x][_y][s], tmp);

              if (map[_x][_y].first != -1 &&
                  ((s >> map[_x][_y].first) & 1) == 0) {
                tmp += map[_x][_y].second;
                int _s = s | (1 << map[_x][_y].first);
                dp[i + 1][_x][_y][_s] = std::max(dp[i + 1][_x][_y][_s], tmp);
              }
            }
            dp[i + 1][x][y][s] = std::max(dp[i + 1][x][y][s], now);
          }
        }
      }
    }
    long long ans = LONG_MIN;
    for (int x = 1; x <= n; ++x) {
      for (int y = 1; y <= n; ++y) {
        ans = std::max(ans, dp[m][x][y][(1 << p) - 1]);
      }
    }
    if (ans == LONG_MIN) {
      printf("Case #%d: IMPOSSIBLE\n", t);
    } else {
      printf("Case #%d: %lld\n", t, ans);
    }
  }
  return 0;
}
