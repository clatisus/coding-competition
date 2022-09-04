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

const int N = 3e5 + 10;

int n;
int a[N], left[N], right[N];

int solve() {
  if (n == 2)
    return 2;

  memset(left, 0, sizeof left);
  memset(right, 0, sizeof right);
  int ret = 2;

  left[1] = 1;
  left[2] = 2;
  for (int i = 3; i <= n; ++i) {
    if (a[i - 2] + a[i] == a[i - 1] * 2) {
      left[i] = left[i - 1] + 1;
    } else {
      left[i] = 2;
    }
    ret = std::max(ret, left[i]);
  }

  right[n] = 1;
  right[n - 1] = 2;
  for (int i = n - 2; i; --i) {
    if (a[i + 2] + a[i] == a[i + 1] * 2) {
      right[i] = right[i + 1] + 1;
    } else {
      right[i] = 2;
    }
    ret = std::max(ret, right[i]);
  }

  // modify a border
  if (ret < n)
    ++ret;

  for (int i = 2; i < n; ++i) {
    int sum = a[i - 1] + a[i + 1];
    if (sum & 1)
      continue;
    ;
    int after = sum / 2;
    int dis = a[i + 1] - after;

    int now = 1;
    if (i + 2 <= n && a[i + 2] - a[i + 1] == dis) {
      now += right[i + 1];
    } else {
      ++now;
    }

    if (i - 2 >= 1 && a[i - 1] - a[i - 2] == dis) {
      now += left[i - 1];
    } else {
      ++now;
    }

    ret = std::max(ret, now);
  }

  return ret;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int test = 1; test <= T; ++test) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    printf("Case #%d: %d\n", test, solve());
  }
  return 0;
}
