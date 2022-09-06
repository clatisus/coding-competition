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

long long g;

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%lld", &g);
    int sqrt = std::sqrt(g) * 3;

    int ans = 0;
    for (long long x = 0; x <= sqrt; ++x) {
      long long a = 2 * g - x * x - x;
      if (a <= 0)
        break;
      long long b = 2 * (x + 1);
      if (a % b == 0) {
        ++ans;
      }
    }
    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
