#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <vector>

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int n, m;

    scanf("%d", &n);
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }

    scanf("%d", &m);
    std::vector<int> b(m + 1);
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &b[i]);
    }

    std::vector<std::vector<int>> left(m + 1), right(m + 1), dp(n + 1);
    for (int i = 1; i <= m; ++i) {
      left[i].resize(2600);
      right[i].resize(2600);
      for (int j = i; j >= 1; --j) {
        if (left[i][b[j]] == 0) {
          left[i][b[j]] = j;
        }
      }
    }
    for (int i = 1; i <= m; ++i) {
      for (int j = i; j <= m; ++j) {
        if (right[i][b[j]] == 0) {
          right[i][b[j]] = j;
        }
      }
    }

    dp[0].resize(m + 1);
    for (int i = 1; i <= n; ++i) {
      dp[i].resize(m + 1);
      for (int j = 1; j <= m; ++j) {
        dp[i][j] = INT_MAX;
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (dp[i][j] == INT_MAX) {
          continue;
        }
        int l = left[j][a[i + 1]];
        if (l != 0) {
          dp[i + 1][l] = std::min(dp[i + 1][l], dp[i][j] + j - l);
        }
        int r = right[j][a[i + 1]];
        if (r != 0) {
          dp[i + 1][r] = std::min(dp[i + 1][r], dp[i][j] + r - j);
        }
      }
    }

    int ans = INT_MAX;
    for (int i = 1; i <= m; ++i) {
      ans = std::min(ans, dp[n][i]);
    }
    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
