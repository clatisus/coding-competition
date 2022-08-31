#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <vector>

const int MAXN = 1e5 + 10;

std::vector<int> edge[MAXN];
int inqueue[MAXN], inq_cnt;

bool check(int u, int k) {
  ++inq_cnt;
  std::queue<int> queue;
  queue.push(u);
  inqueue[u] = inq_cnt;
  int cnt = 1;
  while (!queue.empty()) {
    u = queue.front();
    queue.pop();
    for (auto v : edge[u]) {
      if (inqueue[v] == inq_cnt)
        continue;
      inqueue[v] = inq_cnt;
      queue.push(v);
      if (++cnt > k)
        return false;
    }
  }
  return true;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
      edge[i].clear();
    }
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edge[v].push_back(u);
    }
    int ans = n;
    for (int i = 1; i <= n; ++i) {
      if (check(i, k)) {
        --ans;
      }
    }
    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
