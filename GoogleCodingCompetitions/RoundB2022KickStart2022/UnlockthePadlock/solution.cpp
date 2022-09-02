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

int n, D;
// dp[i][j][0/1] means the cost to let [i..j] be the same as 0(left)/1(right)
// element
long long dp[500][500][2];
int a[500];

int dis(int x, int y) {
  int ans = std::abs(x - y);
  return std::min(ans, D - ans);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d%d", &n, &D);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    a[0] = a[n + 1] = 0;

    memset(dp, 0, sizeof(dp));

    for (int d = 1; d <= n; ++d) {
      for (int i = 1, _i, _j; i + d - 1 <= n; ++i) {
        int j = i + d - 1;
        for (_i = i; _i <= j && a[_i] == a[i]; ++_i)
          ;
        for (_j = j; _j >= i && a[_j] == a[j]; --_j)
          ;
        if (_i > j) {
          // a[i..j] are the same
          dp[i][j][0] = dis(a[i], a[i - 1]);
          dp[i][j][1] = dis(a[j], a[j + 1]);
        } else if (a[i] == a[j]) {
          dp[i][j][0] = dp[_i][_j][0] + dis(a[i], a[i - 1]);
          dp[i][j][1] = dp[_i][_j][1] + dis(a[j], a[j + 1]);
        } else {
          dp[i][j][0] = std::min(dp[_i][j][0] + dis(a[i], a[i - 1]),
                                 dp[i][_j][1] + dis(a[j], a[i - 1]));
          dp[i][j][1] = std::min(dp[_i][j][0] + dis(a[i], a[j + 1]),
                                 dp[i][_j][1] + dis(a[j], a[j + 1]));
        }
      }
    }

    printf("Case #%d: %lld\n", t, dp[1][n][0]);
  }
  return 0;
}
