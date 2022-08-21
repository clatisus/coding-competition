#include <cstdio>

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int n;
    scanf("%d", &n);
    int ans = 1;
    if (n > 1) {
      ans += (n - 2) / 5 + ((n - 2) % 5 == 4);
    }
    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
