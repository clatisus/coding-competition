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

const int N = 310;

int R, C;
int a[N][N];
bool vis[N][N];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d%d", &R, &C);

    std::priority_queue<std::pair<int, std::pair<int, int>>> q;

    for (int i = 1; i <= R; ++i) {
      for (int j = 1; j <= C; ++j) {
        scanf("%d", &a[i][j]);
        q.push({a[i][j], {i, j}});
        vis[i][j] = false;
      }
    }

    long long ans = 0;

    while (!q.empty()) {
      auto [v, p] = q.top();
      auto [x, y] = p;
      q.pop();
      if (vis[x][y])
        continue;
      vis[x][y] = true;
      for (int i = 0; i < 4; ++i) {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (nx >= 1 && nx <= R && ny >= 1 && ny <= C && !vis[nx][ny]) {
          if (a[nx][ny] < a[x][y] - 1) {
            ans += a[x][y] - a[nx][ny] - 1;
            a[nx][ny] = a[x][y] - 1;
            q.push({a[nx][ny], {nx, ny}});
          }
        }
      }
    }

    printf("Case #%d: %lld\n", t, ans);
  }
  return 0;
}
