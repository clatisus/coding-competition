#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <vector>

const int size = 1e5 + 10;

namespace Manacher {

int r[2][size]; // palindromic radius
template <typename T> void manacher(T S, int len, int type) {
  int i, j, k;
  int *R = r[type];
  for (i = j = 0; i < len; i += k, j = std::max(j - k, 0)) {
    while (i - j >= 0 && i + j + type < len && S[i - j] == S[i + j + type])
      ++j;
    R[i] = j;
    for (k = 1; k < j && R[i - k] != R[i] - k; ++k)
      R[i + k] = std::min(R[i - k], R[i] - k);
  }
}

} // namespace Manacher

int n;
char s[size];

bool isPalindrome(int l, int r) {
  if (l > r)
    return true;
  int len = r - l + 1;
  if (len & 1) {
    return Manacher::r[0][(l + r) / 2] >= (len + 1) / 2;
  }
  return Manacher::r[1][(l + r) / 2] >= len / 2;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d", &n);
    scanf("%s", s);
    Manacher::manacher(s, n, 0);
    Manacher::manacher(s, n, 1);
    printf("Case #%d: ", t);
    for (int i = 0; i < n; ++i) {
      if (isPalindrome(0, i) && isPalindrome(i + 1, n - 1)) {
        s[i + 1] = '\0';
        printf("%s\n", s);
        break;
      }
    }
  }
  return 0;
}
