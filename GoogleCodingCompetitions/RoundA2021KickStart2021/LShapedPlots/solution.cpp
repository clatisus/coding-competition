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

const int MAXN = 1e3 + 10;

int R, C;
int a[MAXN][MAXN];
int up[MAXN][MAXN], down[MAXN][MAXN], left[MAXN][MAXN], right[MAXN][MAXN];

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d%d", &R, &C);
    for (int i = 1; i <= R; ++i) {
      for (int j = 1; j <= C; ++j) {
        scanf("%d", &a[i][j]);
      }
    }

    for (int i = 0; i <= R + 1; ++i) {
      for (int j = 0; j <= C + 1; ++j) {
        up[i][j] = down[i][j] = left[i][j] = right[i][j] = 0;
      }
    }

    for (int i = 1; i <= R; ++i) {
      for (int j = 1; j <= C; ++j) {
        up[i][j] = a[i][j] ? up[i - 1][j] + 1 : 0;
        left[i][j] = a[i][j] ? left[i][j - 1] + 1 : 0;
      }
    }

    for (int i = R; i >= 1; --i) {
      for (int j = C; j >= 1; --j) {
        down[i][j] = a[i][j] ? down[i + 1][j] + 1 : 0;
        right[i][j] = a[i][j] ? right[i][j + 1] + 1 : 0;
      }
    }

    int ans = 0;
    for (int i = 1; i <= R; ++i) {
      for (int j = 1; j <= C; ++j) {
        ans += std::max(0, std::min(up[i][j], right[i][j] / 2) - 1);
        ans += std::max(0, std::min(up[i][j] / 2, right[i][j]) - 1);

        ans += std::max(0, std::min(right[i][j], down[i][j] / 2) - 1);
        ans += std::max(0, std::min(right[i][j] / 2, down[i][j]) - 1);

        ans += std::max(0, std::min(down[i][j], left[i][j] / 2) - 1);
        ans += std::max(0, std::min(down[i][j] / 2, left[i][j]) - 1);

        ans += std::max(0, std::min(left[i][j], up[i][j] / 2) - 1);
        ans += std::max(0, std::min(left[i][j] / 2, up[i][j]) - 1);
      }
    }

    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
