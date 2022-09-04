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

const int N = (1 << 18) + 10;

int n, q;
int maxl;
std::vector<std::pair<int, std::pair<int, long long>>> edge[N];
std::vector<std::pair<int, int>> query[N];
long long seg[N << 1];
long long seg_v[N];
long long ans[N];

long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

void update(int t, int l, int r, int x, long long y) {
  if (l == r) {
    seg[t] = y;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    update(t << 1, l, mid, x, y);
  else
    update(t << 1 | 1, mid + 1, r, x, y);
  seg[t] = gcd(seg[t << 1], seg[t << 1 | 1]);
}

long long ask(int t, int l, int r, int x) {
  if (r <= x) {
    return seg[t];
  }
  int mid = (l + r) >> 1;
  if (x <= mid) {
    return ask(t << 1, l, mid, x);
  }
  return gcd(seg[t << 1], ask(t << 1 | 1, mid + 1, r, x));
}

void dfs(int u, int fa) {
  for (auto &[w, id] : query[u]) {
    ans[id] = ask(1, 1, maxl, w);
  }

  for (auto &[v, p] : edge[u]) {
    if (v == fa) {
      continue;
    }
    auto &[l, a] = p;
    long long tmp = seg_v[l];

    seg_v[l] = gcd(seg_v[l], a);
    update(1, 1, maxl, l, seg_v[l]);

    dfs(v, u);

    seg_v[l] = tmp;
    update(1, 1, maxl, l, seg_v[l]);
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
      query[i].clear();
      edge[i].clear();
      seg_v[i] = 0;
    }
    memset(seg, 0, sizeof(seg));

    maxl = 0;
    for (int i = 1; i < n; ++i) {
      int u, v, l;
      long long a;
      scanf("%d%d%d%lld", &u, &v, &l, &a);
      edge[u].push_back({v, {l, a}});
      edge[v].push_back({u, {l, a}});

      maxl = std::max(maxl, l);
    }
    for (int i = 1; i <= q; ++i) {
      int c, w;
      scanf("%d%d", &c, &w);
      query[c].push_back({w, i});
    }

    dfs(1, 0);

    printf("Case #%d:", t);
    for (int i = 1; i <= q; ++i) {
      printf(" %lld", ans[i]);
    }
    printf("\n");
  }
  return 0;
}
