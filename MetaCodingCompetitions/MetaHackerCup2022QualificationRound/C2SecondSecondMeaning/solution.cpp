#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <vector>

char s[200];

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    printf("Case #%d:\n", t);
    char prefix = s[0] == '.' ? '-' : '.';
    for (int i = 1; i < n; ++i) {
      putchar(prefix);
      for (int j = 0; j < 9; ++j) {
        putchar(((i >> j) & 1) ? '.' : '-');
      }
      putchar('\n');
    }
  }
  return 0;
}
