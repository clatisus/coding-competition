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

typedef long long ll;

#define left second
#define right first

void push(ll l, ll r, std::set<std::pair<ll, ll>> &s) {
  if (l > r)
    return;
  s.emplace(r, l);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int n, m;
    scanf("%d%d", &n, &m);

    std::set<std::pair<ll, ll>> s;

    for (int i = 1; i <= n; ++i) {
      ll a, b;
      scanf("%lld%lld", &a, &b);
      push(a, b, s);
    }

    printf("Case #%d:", t);

    for (int i = 1; i <= m; ++i) {
      ll x;
      scanf("%lld", &x);

      auto it = s.lower_bound({x, 0});
      if (it == s.end()) {
        --it;
        printf(" %lld", it->right);
        auto now = *it;
        s.erase(it);
        push(now.left, now.right - 1, s);
      } else if (it->left <= x) {
        printf(" %lld", x);
        auto now = *it;
        s.erase(it);
        push(now.left, x - 1, s);
        push(x + 1, now.right, s);
      } else if (it == s.begin()) {
        printf(" %lld", it->left);
        auto now = *it;
        s.erase(it);
        push(now.left + 1, now.right, s);
      } else {
        auto pre = it;
        --pre;
        if (x - pre->right > it->left - x) {
          printf(" %lld", it->left);
          auto now = *it;
          s.erase(it);
          push(now.left + 1, now.right, s);
        } else {
          printf(" %lld", pre->right);
          auto now = *pre;
          s.erase(pre);
          push(now.left, now.right - 1, s);
        }
      }
    }

    printf("\n");
  }
  return 0;
}
