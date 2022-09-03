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

const int MAXN = 2e5 + 10;

int n, k;
char s[MAXN];

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    int ans = 0;
    for (int i = 0; i < n / 2; ++i) {
      ans += s[i] != s[n - 1 - i];
    }
    printf("Case #%d: %d\n", t, std::abs(ans - k));
  }
  return 0;
}
