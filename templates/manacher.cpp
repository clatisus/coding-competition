#include <algorithm>

const int size = 1e5 + 10;

namespace Manacher {
// r[0] for odd length, r[1] for even length
// abccba                abcba
//   ^                     ^
//  r[1][..] = 3        r[0][..] = 3

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
