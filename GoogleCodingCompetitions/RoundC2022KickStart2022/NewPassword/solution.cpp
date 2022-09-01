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

const int MAXN = 1e4 + 10;

std::set<char> special = {'#', '@', '*', '&'};

int n;
char s[MAXN];

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d%s", &n, s);
    bool hasDigit = false;
    bool hasLower = false;
    bool hasUpper = false;
    bool hasSpecial = false;
    for (int i = 0; i < n; ++i) {
      if (std::isdigit(s[i])) {
        hasDigit = true;
      } else if (std::islower(s[i])) {
        hasLower = true;
      } else if (std::isupper(s[i])) {
        hasUpper = true;
      } else if (special.find(s[i]) != special.end()) {
        hasSpecial = true;
      }
    }

    if (!hasDigit) {
      s[n++] = '0';
    }
    if (!hasLower) {
      s[n++] = 'a';
    }
    if (!hasUpper) {
      s[n++] = 'A';
    }
    if (!hasSpecial) {
      s[n++] = '#';
    }

    while (n < 7) {
      s[n++] = 'a';
    }
    s[n] = '\0';

    printf("Case #%d: %s\n", t, s);
  }
  return 0;
}
