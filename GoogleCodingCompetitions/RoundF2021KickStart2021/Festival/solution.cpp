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

struct TopK {
  int k;
  std::multiset<int> top_k;
  std::multiset<int> rest;
  ll sum;

  TopK(int k) : k(k), sum(0) {
    top_k.clear();
    rest.clear();
  }

  void insert(int x) {
    if (top_k.size() < k) {
      top_k.insert(x);
      sum += x;
    } else {
      auto it = top_k.begin();
      if (x > *it) {
        rest.insert(*it);
        sum -= *it;
        top_k.erase(it);
        top_k.insert(x);
        sum += x;
      } else {
        rest.insert(x);
      }
    }
  }

  void erase(int x) {
    auto it = top_k.find(x);
    if (it != top_k.end()) {
      top_k.erase(it);
      sum -= x;
      if (!rest.empty()) {
        auto it = rest.end();
        --it;
        top_k.insert(*it);
        sum += *it;
        rest.erase(it);
      }
    } else {
      rest.erase(rest.find(x));
    }
  }
};

int d, n, k;

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d%d%d", &d, &n, &k);
    std::vector<std::pair<int, int>> vec;
    for (int i = 1; i <= n; ++i) {
      int h, s, e;
      scanf("%d%d%d", &h, &s, &e);

      vec.emplace_back(s, h);
      vec.emplace_back(e + 1, -h);
    }

    std::sort(vec.begin(), vec.end());

    TopK top_k(k);
    ll ans = 0;
    for (auto &[_, x] : vec) {
      if (x > 0) {
        top_k.insert(x);
      } else {
        top_k.erase(-x);
      }
      ans = std::max(ans, top_k.sum);
    }

    printf("Case #%d: %lld\n", t, ans);
  }
  return 0;
}
