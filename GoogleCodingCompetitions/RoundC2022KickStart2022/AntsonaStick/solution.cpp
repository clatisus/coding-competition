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
    int n, l;
    scanf("%d%d", &n, &l);
    std::vector<std::pair<int, int>> vec;
    std::vector<std::pair<int, int>> pos;
    for (int i = 0; i < n; ++i) {
      int p, d;
      scanf("%d%d", &p, &d);
      pos.emplace_back(p, i);
      if (d == 0) {
        vec.emplace_back(p, 0);
      } else {
        vec.emplace_back(l - p, 1);
      }
    }
    std::sort(vec.begin(), vec.end());
    std::sort(pos.begin(), pos.end());
    std::vector<int> ans;
    int head = 0, tail = n - 1;
    for (int i = 0, j; i < vec.size(); i = j) {
      for (j = i; j < vec.size() && vec[j].first == vec[i].first; ++j)
        ;
      if (j - i == 1) {
        if (vec[i].second == 0) {
          ans.push_back(pos[head++].second);
        } else {
          ans.push_back(pos[tail--].second);
        }
      } else {
        int h = pos[head++].second;
        int t = pos[tail--].second;
        if (h > t) {
          std::swap(h, t);
        }
        ans.push_back(h);
        ans.push_back(t);
      }
    }
    printf("Case #%d:", t);
    for (int i = 0; i < n; ++i) {
      printf(" %d", ans[i] + 1);
    }
    printf("\n");
  }
  return 0;
}
