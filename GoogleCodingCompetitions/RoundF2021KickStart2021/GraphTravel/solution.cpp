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

typedef long long ll;

const int N = 17;

int n, m;
ll k;
ll sum[1 << N];
ll l[N], r[N], a[N];
ll f[1 << N];
bool mat[N][N];

ll get_f(int s) {
  if (f[s] != -1) {
    return f[s];
  }

  if (__builtin_popcount(s) == 1) {
    return f[s] = 1;
  }

  f[s] = 0;

  for (int i = 0; i < n; ++i) {
    if ((s >> i) & 1) {
      int _s = s ^ (1 << i);
      for (int j = 0; j < n; ++j) {
        if (((_s >> j) & 1) && mat[i][j]) {
          if (l[i] <= sum[_s] && sum[_s] <= r[i]) {
            f[s] += get_f(_s);
            break;
          }
        }
      }
    }
  }

  return f[s];
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    memset(mat, 0, sizeof(mat));
    memset(f, -1, sizeof(f));
    scanf("%d%d%lld", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
      scanf("%lld%lld%lld", &l[i], &r[i], &a[i]);
    }
    for (int i = 0; i < m; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      mat[x][y] = mat[y][x] = true;
    }
    for (int s = 1; s < 1 << n; ++s) {
      for (int i = 0; i < n; ++i) {
        if ((s >> i) & 1) {
          sum[s] = sum[s ^ (1 << i)] + a[i];
          break;
        }
      }
    }

    ll ans = 0;
    for (int s = 1; s < 1 << n; ++s) {
      if (sum[s] == k) {
        ans += get_f(s);
      }
    }
    printf("Case #%d: %lld\n", t, ans);
  }
  return 0;
}
