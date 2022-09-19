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

ll d, x;
int n;

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%lld%d%lld", &d, &n, &x);
    // (L, (V, Q))
    std::vector<std::pair<ll, std::pair<ll, ll>>> a;
    for (int i = 1; i <= n; ++i) {
      ll q, l, v;
      scanf("%lld%lld%lld", &q, &l, &v);
      a.push_back({l, {v, q}});
    }

    a.push_back({d, {0, 0}});

    std::sort(a.begin(), a.end());

    ll ans = 0;

    ll last_l = -1;
    // (V, Q)
    std::priority_queue<std::pair<ll, ll>> queue;
    for (int i = 0, j; i <= n; i = j) {
      for (j = i; j <= n && a[i].first == a[j].first; ++j)
        ;

      if (last_l != -1) {
        ll total_x = x * (a[i].first - last_l);

        while (!queue.empty() && total_x > 0) {
          auto [v, q] = queue.top();
          queue.pop();
          ll consume = std::min(total_x, q);
          total_x -= consume;
          q -= consume;
          ans += v * consume;
          if (q > 0)
            queue.push({v, q});
        }
      }

      last_l = a[i].first;
      for (int k = i; k < j; ++k) {
        queue.push(a[k].second);
      }
    }

    printf("Case #%d: %lld\n", t, ans);
  }
  return 0;
}
