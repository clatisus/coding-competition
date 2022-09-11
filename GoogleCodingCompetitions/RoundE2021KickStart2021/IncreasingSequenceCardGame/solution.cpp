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

const long long N = 1e6;

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    long long n;
    scanf("%lld", &n);
    double ans = 0;

    for (int i = 1; i <= std::min(N, n); ++i) {
      ans += 1.0 / i;
    }

    if (n > N) {
      ans += std::log(n + 1) - std::log(N + 1);
    }

    printf("Case #%d: %.10f\n", t, ans);
  }
  return 0;
}
