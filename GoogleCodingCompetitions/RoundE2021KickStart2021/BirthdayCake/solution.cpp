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

int R, C, K;
int r1, c1, r2, c2;

long long cnt(long long a, int b) { return (a + b - 1) / b; }

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d%d%d", &R, &C, &K);
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);

    long long n = r2 - r1 + 1;
    long long m = c2 - c1 + 1;

    bool r1_open = r1 == 1;
    bool r2_open = r2 == R;
    bool c1_open = c1 == 1;
    bool c2_open = c2 == C;
    int open_cnt = r1_open + r2_open + c1_open + c2_open;

    long long ans = LONG_MAX;
    if (open_cnt == 4) {
      ans = 0;
    } else if (open_cnt == 3) {
      if (!c1_open || !c2_open) {
        ans = std::min(ans, cnt(n, K));
      }
      if (!r1_open || !r2_open) {
        ans = std::min(ans, cnt(m, K));
      }
    } else if (open_cnt == 2) {
      if (!r1_open && !r2_open) {
        ans = std::min(ans, 2 * cnt(m, K));
      } else if (!c1_open && !c2_open) {
        ans = std::min(ans, 2 * cnt(n, K));
      } else {
        ans = std::min(ans, cnt(n, K) + cnt(m, K));
      }
    } else if (open_cnt == 1) {
      if (r1_open || r2_open) {
        ans = std::min(ans, 2 * cnt(n, K) + cnt(m, K));
      } else if (c1_open || c2_open) {
        ans = std::min(ans, 2 * cnt(m, K) + cnt(n, K));
      }
    } else {
      ans = std::min(ans, std::min(cnt(r2, K), cnt(R - r1 + 1, K)) +
                              2 * cnt(m, K) + cnt(n, K));
      ans = std::min(ans, std::min(cnt(c2, K), cnt(C - c1 + 1, K)) +
                              2 * cnt(n, K) + cnt(m, K));
    }

    ans += n * m - 1 + ((n - 1) / K) * ((m - 1) / K);

    printf("Case #%d: %lld\n", t, ans);
  }
  return 0;
}
