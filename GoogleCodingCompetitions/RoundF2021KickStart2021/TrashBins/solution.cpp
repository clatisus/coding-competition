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

const int N = 5e5 + 10;

int n;
char s[N];
int left[N];

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d%s", &n, s + 1);
    int last = INT_MAX;
    for (int i = 1; i <= n; ++i) {
      if (s[i] == '1') {
        last = 0;
      }
      left[i] = last;
      if (last != INT_MAX) {
        ++last;
      }
    }
    long long ans = 0;
    last = INT_MAX;
    for (int i = n; i; --i) {
      if (s[i] == '1') {
        last = 0;
      }
      ans += std::min(last, left[i]);
      if (last != INT_MAX) {
        ++last;
      }
    }
    printf("Case #%d: %lld\n", t, ans);
  }
  return 0;
}
