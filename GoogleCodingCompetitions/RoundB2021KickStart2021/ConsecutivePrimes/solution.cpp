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

template <typename T> constexpr bool is_prime(T n) {
  if (n <= 1) {
    return false;
  }
  for (T i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    long long Z;
    scanf("%lld", &Z);

    long long left = 1, right = 1e9, sqrt;
    while (left <= right) {
      long long mid = (left + right) / 2;
      if (mid * mid <= Z) {
        sqrt = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    long long p1, p2, p3;
    for (p3 = sqrt + 1; !is_prime(p3); ++p3)
      ;
    for (p2 = sqrt; !is_prime(p2); --p2)
      ;
    if (p2 * p3 <= Z) {
      printf("Case #%d: %lld\n", t, p2 * p3);
    } else {
      for (p1 = p2 - 1; !is_prime(p1); --p1)
        ;
      printf("Case #%d: %lld\n", t, p1 * p2);
    }
  }
  return 0;
}
