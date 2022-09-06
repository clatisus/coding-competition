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

const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, k;
char s[N];
char s1[N];

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d%d%s", &n, &k, s + 1);
    int m = (n + 1) / 2;
    int ans = 0;
    for (int i = m, km = 1; i >= 1; --i) {
      ans = (ans + 1ll * (s[i] - 'a') * km % MOD) % MOD;
      km = 1ll * km * k % MOD;
    }

    for (int i = 1; i <= m; ++i) {
      s1[i] = s[i];
    }
    for (int i = m + 1; i <= n; ++i) {
      s1[i] = s1[n - i + 1];
    }
    s[n + 1] = 0;

    if (strcmp(s + 1, s1 + 1) > 0) {
      ans = (ans + 1) % MOD;
    }

    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
