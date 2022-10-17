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

struct pt {
  ll x, y;
  pt(ll x, ll y) : x(x), y(y) {}
  pt() {}
  ll norm2() { return *this * *this; }
  double norm() { return sqrt(norm2()); }
  pt operator-(pt p) const { return pt(x - p.x, y - p.y); }
  ll operator*(pt p) { return x * p.x + y * p.y; }
  ll operator%(pt p) { return x * p.y - y * p.x; }
  bool left(pt p, pt q) { return (q - p) % (*this - p) > 0; }
};

const int N = 310;
double g[N][N];

void floyd(int n) {
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      if (g[i][k] >= 1e15) {
        continue;
      }
      for (int j = 0; j < n; ++j) {
        if (g[k][j] >= 1e15) {
          continue;
        }
        g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int n;
    scanf("%d", &n);
    std::vector<pt> v(n);
    for (int i = 0; i < n; ++i) {
      scanf("%lld%lld", &v[i].x, &v[i].y);
    }
    pt me;
    scanf("%lld%lld", &me.x, &me.y);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        g[i][j] = 1e18;
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        // v[i] ------->  v[j]
        //      \
        //       \
        //       v
        //      me
        if (i != j && me.left(v[i], v[j])) {
          g[i][j] = (v[j] - v[i]).norm();
        }
      }
    }

    floyd(n);

    double ans = 1e18;
    for (int i = 0; i < n; ++i) {
      ans = std::min(ans, g[i][i]);
    }

    if (ans >= 1e12) {
      printf("Case #%d: IMPOSSIBLE\n", t);
    } else {
      printf("Case #%d: %.10f\n", t, ans);
    }
  }
  return 0;
}
