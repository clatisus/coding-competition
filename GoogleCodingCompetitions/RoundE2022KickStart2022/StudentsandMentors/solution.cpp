#include <cstdio>
#include <cstdlib>
#include <set>

const int MAX_N = 1e5 + 10;

int n;
int a[MAX_N];

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    std::multiset<int> s;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
      s.insert(a[i]);
    }
    printf("Case #%d:", t);
    for (int i = 0; i < n; ++i) {
      int ans = -1;
      s.erase(s.find(a[i]));
      auto it = s.upper_bound(a[i] * 2);
      if (it != s.begin()) {
        ans = *(--it);
      }
      s.insert(a[i]);
      printf(" %d", ans);
    }
    printf("\n");
  }
  return 0;
}
