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

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int g00, g01, g02, g10, g12, g20, g21, g22;
    scanf("%d%d%d%d%d%d%d%d", &g00, &g01, &g02, &g10, &g12, &g20, &g21, &g22);

    int ans = 0;
    ans += g00 + g02 == 2 * g01;
    ans += g20 + g22 == 2 * g21;
    ans += g00 + g20 == 2 * g10;
    ans += g02 + g22 == 2 * g12;

    std::map<int, int> cnt;
    cnt[g00 + g22]++;
    cnt[g02 + g20]++;
    cnt[g01 + g21]++;
    cnt[g10 + g12]++;

    int max_cnt = 0;
    for (auto [k, v] : cnt) {
      if (k % 2 == 0) {
        max_cnt = std::max(max_cnt, v);
      }
    }

    ans += max_cnt;

    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
