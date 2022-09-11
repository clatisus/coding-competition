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

const int MOD = 1e9 + 7;

int n, q;

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d", &n);

    int suma = 0, suma2 = 0;
    int sumb = 0, sumb2 = 0;
    for (int i = 1; i <= n; ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      suma = (suma + a) % MOD;
      suma2 = (suma2 + 1LL * a * a) % MOD;

      sumb = (sumb + b) % MOD;
      sumb2 = (sumb2 + 1LL * b * b) % MOD;
    }

    int ans = 0;

    scanf("%d", &q);
    for (int i = 1; i <= q; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      ans = (ans + 1LL * n * x % MOD * x % MOD) % MOD;
      ans = (ans + suma2) % MOD;
      ans = (ans - 2LL * x * suma % MOD + MOD) % MOD;

      ans = (ans + 1LL * n * y % MOD * y % MOD) % MOD;
      ans = (ans + sumb2) % MOD;
      ans = (ans - 2LL * y * sumb % MOD + MOD) % MOD;
    }

    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
