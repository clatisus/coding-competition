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

const int N = 1e6 + 10;

int n;
std::vector<int> edge[N];
int height[N];
int cnt[N];

void dfs(int u, int f) {
  cnt[height[u]]++;
  for (auto &v : edge[u]) {
    if (v == f)
      continue;
    height[v] = height[u] + 1;
    dfs(v, u);
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i <= n; ++i) {
      edge[i].clear();
      height[i] = 0;
      cnt[i] = 0;
    }
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edge[u].push_back(v);
      edge[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= q; ++i) {
      int _;
      scanf("%d", &_);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (q >= cnt[i]) {
        q -= cnt[i];
        ans += cnt[i];
      } else {
        break;
      }
    }
    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
