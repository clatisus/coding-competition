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
typedef unsigned long long ull;

inline int sig(ll p) { return (p > 0) - (p < 0); }

struct P {
  ll x, y;
  explicit P(ll x = 0, ll y = 0) : x(x), y(y) {}
  ll det(const P &p) const { return x * p.y - y * p.x; }
  P sub(const P &p) const { return P(x - p.x, y - p.y); }
  ll abs2() const { return x * x + y * y; }

  bool operator<(const P &p) const {
    if (sig(x - p.x))
      return x < p.x;
    return y < p.y;
  }

  bool operator==(const P &p) const { return !sig(x - p.x) && !sig(y - p.y); }
};

struct L {
  P p, v;
  L() {}
  L(P a, P b) : p(a), v(b.sub(a)) {}
};

ll onLeft(L l, P p) { return l.v.det(p.sub(l.p)); }

std::vector<P> convexHull(std::vector<P> &ps) {
  static P st[1000010];
  std::sort(ps.begin(), ps.end());
  int n = ps.size(), top = 0;
  auto check = [&](int i) {
    return sig(onLeft(L(st[top - 2], st[top - 1]), ps[i])) <= 0;
  };
  for (int i = 0; i < n; ++i) {
    while (top > 1 && check(i))
      --top;
    st[top++] = ps[i];
  }
  for (int i = n - 2, tmp = top; ~i; --i) {
    while (top > tmp && check(i))
      --top;
    st[top++] = ps[i];
  }
  if (n > 1)
    --top;
  std::vector<P> ret;
  for (int i = 0; i < top; ++i)
    ret.push_back(st[i]);
  return ret;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int n;
    ll k, d;
    scanf("%d%lld%lld", &n, &k, &d);
    std::vector<P> ps;
    for (int i = 0; i < n; ++i) {
      ll x, y;
      scanf("%lld%lld", &x, &y);
      ps.push_back(P(x, y));
    }
    ps = convexHull(ps);

    std::sort(ps.begin(), ps.end());

    n = ps.size();
    std::vector<ull> dis(n, ULLONG_MAX);
    std::vector<bool> vis(n);
    dis[0] = 0;
    for (int i = 0; i < n - 1; ++i) {
      int u = -1;
      ull min_dis = ULLONG_MAX;
      for (int j = 0; j < n; ++j) {
        if (!vis[j] && dis[j] < min_dis) {
          u = j;
          min_dis = dis[j];
        }
      }
      if (u == -1) {
        break;
      }
      vis[u] = true;
      for (int v = 0; v < n; ++v) {
        ll w = ps[u].sub(ps[v]).abs2();
        if (vis[v] || w > d * d) {
          continue;
        }
        dis[v] = std::min(dis[v], dis[u] + std::max(k, w));
      }
    }

    if (dis[n - 1] == ULLONG_MAX) {
      printf("Case #%d: -1\n", t);
    } else {
      printf("Case #%d: %llu\n", t, dis[n - 1]);
    }
  }
  return 0;
}
