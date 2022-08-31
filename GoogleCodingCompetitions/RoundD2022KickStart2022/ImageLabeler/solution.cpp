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
    scanf("%d%d", &n, &m);
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    --m;
    std::sort(a.begin(), a.end());
    double ans = 0;
    for (int i = 1; i <= m; ++i) {
      ans += a[n - i];
    }
    if ((n - m - 1) % 2 == 0) {
      ans += a[(n - m - 1) / 2];
    } else {
      ans += (a[(n - m - 1) / 2] + a[(n - m - 1) / 2 + 1]) / 2.0;
    }
    printf("Case #%d: %.1f\n", t, ans);
  }
  return 0;
}
