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

// f[L][P][S][S_target]
// # of combinations of arbitrary L digits d1, d2, ..., dL
// that:
//   S + d1 + d2 + ... + dL            = S_target
//   P * d1 * d2 * ... * dL % S_target = 0
long long _f[14][140][140][140];

long long f(int l, int p, int s, int st) {
  auto &ret = _f[l][p][s][st];
  if (ret != -1)
    return ret;
  if (l == 0) {
    return ret = s == st && p % st == 0;
  }
  ret = 0;
  for (int d = 0; d < 10; ++d) {
    ret += f(l - 1, p * d % st, s + d, st);
  }
  return ret;
}

long long calcPrefixOfN(int st, std::vector<int> &digits, int p, int s, int idx,
                        bool isFirstDigit) {
  if (idx == digits.size()) {
    return s == st && p % st == 0;
  }
  long long ret = 0;
  for (int d = isFirstDigit ? 1 : 0; d < digits[idx]; ++d) {
    ret += f(digits.size() - idx - 1, p * d % st, s + d, st);
  }
  ret += calcPrefixOfN(st, digits, p * digits[idx] % st, s + digits[idx],
                       idx + 1, false);
  return ret;
}

long long calc(long long n) {
  if (n < 1)
    return 0;

  std::vector<int> digits;
  while (n) {
    digits.push_back(n % 10);
    n /= 10;
  }
  std::reverse(digits.begin(), digits.end());
  int len = digits.size();

  long long ret = 0;
  for (int st = 1; st <= 9 * len; ++st) {
    // calculate # of digits < len
    for (int l = 1; l < len; ++l) {
      for (int d = 1; d < 10; ++d) {
        ret += f(l - 1, d % st, d, st);
      }
    }

    ret += calcPrefixOfN(st, digits, 1, 0, 0, true);
  }

  return ret;
}

int main() {
  memset(_f, -1, sizeof(_f));

  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    printf("Case #%d: %lld\n", t, calc(b) - calc(a - 1));
  }
  return 0;
}
