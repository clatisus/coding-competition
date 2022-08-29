#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <vector>

const int MAX_N = 2e5 + 10;
const int SQRT_N = 700;

int n, m, q;
int degree[MAX_N];
long long ans[SQRT_N][MAX_N];
int label[MAX_N], label_cnt;
std::map<std::pair<int, int>, int> map;
std::vector<std::pair<int, int>> edge[MAX_N];

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d%d%d", &n, &m, &q);

    label_cnt = 0;
    for (int i = 1; i <= n; ++i) {
      edge[i].clear();
      degree[i] = 0;
    }
    map.clear();

    for (int i = 0; i < m; ++i) {
      int u, v, c;
      scanf("%d%d%d", &u, &v, &c);
      edge[u].push_back({v, c});
      edge[v].push_back({u, c});
      ++degree[u];
      ++degree[v];
      map[{u, v}] = c;
      map[{v, u}] = c;
    }
    for (int i = 1; i <= n; ++i) {
      std::sort(edge[i].begin(), edge[i].end());
    }

    int sqrtn = sqrt(n);

    for (int u = 1; u <= n; ++u) {
      if (degree[u] >= sqrtn) {
        label[u] = ++label_cnt;
        for (int i = 1; i <= n; ++i) {
          ans[label[u]][i] = 0;
        }
        for (auto &e1 : edge[u]) {
          int v = e1.first;
          int c1 = e1.second;
          for (auto &e2 : edge[v]) {
            int w = e2.first;
            int c2 = e2.second;
            ans[label[u]][w] += std::min(c1, c2);
          }
        }
      }
    }

    printf("Case #%d:", t);
    while (q--) {
      int u, w;
      scanf("%d%d", &u, &w);
      long long answer = map[{u, w}] * 2ll;

      if (degree[u] > degree[w]) {
        std::swap(u, w);
      }

      if (degree[w] >= sqrtn) {
        answer += ans[label[w]][u];
      } else {
        int i = 0, j = 0;
        while (i < edge[u].size() && j < edge[w].size()) {
          if (edge[u][i].first == edge[w][j].first) {
            answer += std::min(edge[u][i].second, edge[w][j].second);
            ++i;
            ++j;
          } else if (edge[u][i].first < edge[w][j].first) {
            ++i;
          } else {
            ++j;
          }
        }
      }

      printf(" %lld", answer);
    }
    printf("\n");
  }
  return 0;
}
