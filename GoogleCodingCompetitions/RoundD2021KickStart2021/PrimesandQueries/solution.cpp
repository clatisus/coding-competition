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

// https://en.wikipedia.org/wiki/Lifting-the-exponent_lemma

const int N = (1 << 19) + 10;

int n, q;
long long p;
long long seg[N << 1][4];
long long a[N];

long long get_v(long long a) {
  long long ret = 0;
  while (a && a % p == 0) {
    ++ret;
    a /= p;
  }
  return ret;
}

void build(int t, int l, int r) {
  if (l == r) {
    if (a[l] % p == 0) {
      seg[t][0] = 0;
      seg[t][1] = 0;
      seg[t][2] = get_v(a[l]);
      seg[t][3] = 0;
    } else {
      seg[t][0] = get_v(a[l] - a[l] % p);
      seg[t][1] = get_v(a[l] - a[l] % p) + get_v(a[l] + a[l] % p) - 1;
      seg[t][2] = 0;
      seg[t][3] = (a[l] > p);
    }
    return;
  }
  int m = (l + r) >> 1;
  build(t << 1, l, m);
  build(t << 1 | 1, m + 1, r);

  seg[t][0] = seg[t << 1][0] + seg[t << 1 | 1][0];
  seg[t][1] = seg[t << 1][1] + seg[t << 1 | 1][1];
  seg[t][2] = seg[t << 1][2] + seg[t << 1 | 1][2];
  seg[t][3] = seg[t << 1][3] + seg[t << 1 | 1][3];
}

void insert(int t, int l, int r, int x, long long v) {
  if (l == r) {
    if (v % p == 0) {
      seg[t][0] = 0;
      seg[t][1] = 0;
      seg[t][2] = get_v(v);
      seg[t][3] = 0;
    } else {
      seg[t][0] = get_v(v - v % p);
      seg[t][1] = get_v(v - v % p) + get_v(v + v % p) - 1;
      seg[t][2] = 0;
      seg[t][3] = (v > p);
    }
    return;
  }
  int m = (l + r) >> 1;
  if (x <= m) {
    insert(t << 1, l, m, x, v);
  } else {
    insert(t << 1 | 1, m + 1, r, x, v);
  }
  seg[t][0] = seg[t << 1][0] + seg[t << 1 | 1][0];
  seg[t][1] = seg[t << 1][1] + seg[t << 1 | 1][1];
  seg[t][2] = seg[t << 1][2] + seg[t << 1 | 1][2];
  seg[t][3] = seg[t << 1][3] + seg[t << 1 | 1][3];
}

long long query(int type, int t, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) {
    return seg[t][type];
  }
  int m = (l + r) >> 1;
  long long ret = 0;
  if (!(m < ql)) {
    ret += query(type, t << 1, l, m, ql, qr);
  }
  if (!(qr <= m)) {
    ret += query(type, t << 1 | 1, m + 1, r, ql, qr);
  }
  return ret;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d%d%lld", &n, &q, &p);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", a + i);
    }

    build(1, 1, n);

    printf("Case #%d:", t);
    while (q--) {
      int op;
      scanf("%d", &op);
      if (op == 1) {
        int x;
        long long v;
        scanf("%d%lld", &x, &v);
        insert(1, 1, n, x, v);
      } else {
        long long s;
        int l, r;
        scanf("%lld%d%d", &s, &l, &r);

        int cnt = query(3, 1, 1, n, l, r);
        long long ans = query(2, 1, 1, n, l, r) * s;

        if (p == 2 && s % 2 == 0) {
          ans += query(1, 1, 1, n, l, r) + cnt * get_v(s);
        } else {
          ans += query(0, 1, 1, n, l, r) + cnt * get_v(s);
        }

        printf(" %lld", ans);
      }
    }
    printf("\n");
  }
  return 0;
}
