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

const int N = 2e5 + 10;

int n;
char s[N];
int dp[N];

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d%s", &n, s);
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
      dp[i] = s[i] > s[i - 1] ? dp[i - 1] + 1 : 1;
    }
    printf("Case #%d:", t);
    for (int i = 0; i < n; ++i) {
      printf(" %d", dp[i]);
    }
    printf("\n");
  }
  return 0;
}
