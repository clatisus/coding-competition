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
    std::vector<long long> suma(n + 1);
    suma[0] = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      suma[i] = suma[i - 1] + a[i];
    }

    scanf("%d", &m);
    std::vector<int> b(m + 1);
    std::vector<long long> sumb(m + 1);
    sumb[0] = 0;
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &b[i]);
      sumb[i] = sumb[i - 1] + b[i];
    }

    int k;
    scanf("%d", &k);

    long long ans = 0;
    for (int ka = 0; ka <= std::min(n, k); ++ka) {
      int kb = k - ka;
      if (kb > m) {
        continue;
      }
      long long nowa = 0;
      long long nowb = 0;

      for (int i = 0; i <= ka; ++i) {
        int j = ka - i;
        nowa = std::max(nowa, suma[i] + suma[n] - suma[n - j]);
      }

      for (int i = 0; i <= kb; ++i) {
        int j = kb - i;
        nowb = std::max(nowb, sumb[i] + sumb[m] - sumb[m - j]);
      }

      ans = std::max(ans, nowa + nowb);
    }
    printf("Case #%d: %lld\n", t, ans);
  }
  return 0;
}
