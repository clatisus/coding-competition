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

int n, k;
// build fail on a, search b + b
int a[N], b[N];
int fail[N];

void makeFail() {
  fail[0] = -1;
  for (int i = 1, j = -1; i <= n; ++i) {
    while (j >= 0 && a[j] != a[i - 1])
      j = fail[j];
    fail[i] = ++j;
  }
}

bool searchForm() {
  for (int i = 0, j = 0; i < n + n; ++i) {
    while (j >= 0 && a[j] != b[i % n])
      j = fail[j];
    if (++j == n) {
      return true;
    }
  }
  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d", &b[i]);
    }
    makeFail();

    bool same = true;
    for (int i = 0; i < n; ++i) {
      same &= a[i] == b[i];
    }

    bool isomorphism = searchForm();

    if (!isomorphism) {
      printf("Case #%d: NO\n", t);
      continue;
    }

    if (k == 0) {
      printf("Case #%d: %s\n", t, same ? "YES" : "NO");
    } else if (k == 1) {
      int circle = n - fail[n];
      printf("Case #%d: %s\n", t,
             (!same || (circle != n && n % circle == 0)) ? "YES" : "NO");
    } else if (n == 2) {
      if (a[0] == a[1]) {
        printf("Case #%d: YES\n", t);
      } else if (same) {
        printf("Case #%d: %s\n", t, k % 2 == 0 ? "YES" : "NO");
      } else {
        printf("Case #%d: %s\n", t, k % 2 == 1 ? "YES" : "NO");
      }
    } else {
      printf("Case #%d: YES\n", t);
    }
  }
  return 0;
}
