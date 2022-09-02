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

const int MAXN = 500;

int R, C;
char s[MAXN][MAXN];
std::pair<char, std::pair<int, int>> next[MAXN][MAXN];

// merge circles

int dfs(int r, int c) {
  s[r][c] = '#';

  int ret = 1;

  int _r = r;
  int _c = c + 1;
  if (_c <= C && s[_r][_c] == '*') {
    ret += dfs(_r, _c);
    next[2 * r - 1][2 * c] = {'E', {2 * _r - 1, 2 * _c - 1}};
    next[2 * _r][2 * _c - 1] = {'W', {2 * r, 2 * c}};
  }

  _r = r + 1;
  _c = c;
  if (_r <= R && s[_r][_c] == '*') {
    ret += dfs(_r, _c);
    next[2 * r][2 * c] = {'S', {2 * _r - 1, 2 * _c}};
    next[2 * _r - 1][2 * _c - 1] = {'N', {2 * r, 2 * c - 1}};
  }

  _r = r;
  _c = c - 1;
  if (_c >= 1 && s[_r][_c] == '*') {
    ret += dfs(_r, _c);
    next[2 * r][2 * c - 1] = {'W', {2 * _r, 2 * _c}};
    next[2 * _r - 1][2 * _c] = {'E', {2 * r - 1, 2 * c - 1}};
  }

  _r = r - 1;
  _c = c;
  if (_r >= 1 && s[_r][_c] == '*') {
    ret += dfs(_r, _c);
    next[2 * r - 1][2 * c - 1] = {'N', {2 * _r, 2 * _c - 1}};
    next[2 * _r][2 * _c] = {'S', {2 * r - 1, 2 * c}};
  }

  return ret;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d%d", &R, &C);
    int cnt = 0;
    for (int i = 1; i <= R; ++i) {
      scanf("%s", s[i] + 1);
      for (int j = 1; j <= C; ++j) {
        if (s[i][j] == '*') {
          ++cnt;
          next[2 * i - 1][2 * j - 1] = {'E', {2 * i - 1, 2 * j}};
          next[2 * i - 1][2 * j] = {'S', {2 * i, 2 * j}};
          next[2 * i][2 * j] = {'W', {2 * i, 2 * j - 1}};
          next[2 * i][2 * j - 1] = {'N', {2 * i - 1, 2 * j - 1}};
        }
      }
    }

    if (dfs(1, 1) != cnt) {
      printf("Case #%d: IMPOSSIBLE\n", t);
    } else {
      printf("Case #%d: ", t);
      int r = 1, c = 1;
      do {
        auto &n = next[r][c];
        putchar(n.first);
        r = n.second.first;
        c = n.second.second;
      } while (r != 1 || c != 1);
      putchar('\n');
    }
  }
  return 0;
}
