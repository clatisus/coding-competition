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

const int MAXN = 410;
const int MOD = 1e9 + 7;

int n;
char s[MAXN];
// dp[i][j][len] means within interval [i, j], there's #dp of palindroms of
// length len
int dp[MAXN][MAXN][MAXN];

int f(int l, int r, int len) {
  if (len == 0)
    return 1;
  if (len < 0 || l > r)
    return 0;
  return dp[l][r][len];
}

int fac[MAXN];
int invf[MAXN];
int inv[MAXN];

void init() {
  fac[0] = invf[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    fac[i] = 1ll * fac[i - 1] * i % MOD;
    inv[i] = i == 1 ? 1 : (MOD - 1ll * (MOD / i) * inv[MOD % i] % MOD) % MOD;
    invf[i] = 1ll * invf[i - 1] * inv[i] % MOD;
  }
}

int main() {
  init();

  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    memset(dp, 0, sizeof(dp));
    scanf("%d%s", &n, s);

    for (int len = 1; len < n; ++len) {
      for (int d = len; d <= n; ++d) {
        for (int l = 0; l + d - 1 < n; ++l) {
          int r = l + d - 1;
          if (s[l] == s[r]) {
            dp[l][r][len] =
                (dp[l][r][len] + f(l + 1, r - 1, l == r ? len - 1 : len - 2)) %
                MOD;
          }
          dp[l][r][len] = (dp[l][r][len] + f(l + 1, r, len)) % MOD;
          dp[l][r][len] = (dp[l][r][len] + f(l, r - 1, len)) % MOD;
          dp[l][r][len] = (dp[l][r][len] - f(l + 1, r - 1, len) + MOD) % MOD;
        }
      }
    }

    int ans = 1ll * fac[0] * fac[n] % MOD;
    for (int len = 1; len < n; ++len) {
      ans = (ans +
             1ll * dp[0][n - 1][len] * fac[len] % MOD * fac[n - len] % MOD) %
            MOD;
    }
    ans = 1ll * ans * invf[n] % MOD;

    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
