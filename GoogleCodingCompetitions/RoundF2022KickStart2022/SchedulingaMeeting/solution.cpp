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

struct TopK {
  int k;
  std::multiset<int> top_k;
  std::multiset<int> rest;
  int sum;

  TopK(int k) : k(k), sum(0) {
    top_k.clear();
    rest.clear();
  }

  void insert(int x) {
    if (top_k.size() < k) {
      top_k.insert(x);
      sum += x;
    } else {
      auto it = top_k.end();
      it--;
      if (x < *it) {
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
        auto it = rest.begin();
        top_k.insert(*it);
        sum += *it;
        rest.erase(it);
      }
    } else {
      rest.erase(rest.find(x));
    }
  }

  void print() {
    printf("----------\n");
    printf("sum = %d\n", sum);
    for (auto &v : top_k) {
      printf("%d ", v);
    }
    printf("\n");
    for (auto &v : rest) {
      printf("%d ", v);
    }
    printf("\n");
  }
};

int n, k, x, d;

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d%d%d%d", &n, &k, &x, &d);
    TopK top_k(k);

    int m;
    scanf("%d", &m);
    std::vector<std::vector<int>> left(d + 1);
    std::vector<std::vector<int>> right(d + 1);

    std::vector<int> meetings(n + 1);

    for (int i = 1; i <= m; ++i) {
      int p, l, r;
      scanf("%d%d%d", &p, &l, &r);
      left[l].push_back(p);
      right[r].push_back(p);

      if (l < x) {
        meetings[p]++;
      }
    }

    for (int p = 1; p <= n; ++p) {
      top_k.insert(meetings[p]);
    }

    int ans = top_k.sum;
    for (int s = 1; s + x <= d; ++s) {
      for (auto &p : right[s]) {
        top_k.erase(meetings[p]);
        meetings[p]--;
        top_k.insert(meetings[p]);
      }
      for (auto &p : left[s + x - 1]) {
        top_k.erase(meetings[p]);
        meetings[p]++;
        top_k.insert(meetings[p]);
      }
      ans = std::min(ans, top_k.sum);
    }

    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
