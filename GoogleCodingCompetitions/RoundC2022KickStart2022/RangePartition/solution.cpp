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

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    int sumn = n * (n + 1) / 2;
    if (sumn % (x + y) != 0) {
      printf("Case #%d: IMPOSSIBLE\n", t);
      continue;
    }
    int k = sumn / (x + y);
    int now = x * k;
    std::vector<int> ans;
    for (int i = n; i >= 1; --i) {
      if (now >= i) {
        ans.push_back(i);
        now -= i;
      } else {
        ans.push_back(now);
        now = 0;
      }
      if (now == 0) {
        break;
      }
    }
    printf("Case #%d: POSSIBLE\n", t);
    printf("%lu\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
    }
  }
  return 0;
}
