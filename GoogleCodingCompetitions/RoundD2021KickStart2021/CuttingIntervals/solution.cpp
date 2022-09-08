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

int n;
long long c;

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d%lld", &n, &c);

    std::vector<std::pair<long long, int>> vec;
    for (int i = 1; i <= n; ++i) {
      long long l, r;
      scanf("%lld%lld", &l, &r);

      vec.emplace_back(l + 1, 1);
      vec.emplace_back(r, -1);
    }

    std::sort(vec.begin(), vec.end());

    std::vector<std::pair<int, long long>> cuts;

    int now = 0;
    long long last_pos = -1;
    for (int i = 0, j, sz = vec.size(); i < sz; i = j) {
      if (last_pos != -1) {
        cuts.emplace_back(now, vec[i].first - last_pos);
      }

      last_pos = vec[i].first;
      for (j = i; vec[j].first == vec[i].first && j < sz; ++j) {
        now += vec[j].second;
      }
    }

    std::sort(cuts.begin(), cuts.end(),
              std::greater<std::pair<int, long long>>());

    long long ans = n;
    for (auto &[v, cnt] : cuts) {
      long long cut = std::min(cnt, c);

      ans += cut * v;
      c -= cut;
      if (c == 0) {
        break;
      }
    }

    printf("Case #%d: %lld\n", t, ans);
  }
  return 0;
}
