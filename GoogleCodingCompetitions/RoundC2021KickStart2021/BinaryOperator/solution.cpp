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
#include <vector>

const int MOD = 1000050131;
const int N = 200;

std::mt19937_64 rnd(std::time(nullptr));
int ans[N];
std::map<std::pair<int, int>, int> f;

int get_value(std::string &str, int l, int r) {
  int ret = 0;
  for (int i = l; i <= r; ++i) {
    ret = (ret * 10ll + str[i] - '0') % MOD;
  }
  return ret;
}

int merge(int a, char op, int b) {
  switch (op) {
  case '+':
    return (a + b) % MOD;
  case '*':
    return (1ll * a * b) % MOD;
  case '#':
    if (f.find({a, b}) == f.end()) {
      f[{a, b}] = rnd() % MOD;
    }
    return f[{a, b}];
  }
  return 0;
}

int solve(std::string &str, int l, int r) {
  if (str[l] != '(') {
    return get_value(str, l, r);
  }
  int m = l + 1, cnt = 0;
  do {
    if (str[m] == '(')
      ++cnt;
    if (str[m] == ')')
      --cnt;
    ++m;
  } while (cnt != 0 || (str[m] != '*' && str[m] != '+' && str[m] != '#'));

  int a = solve(str, l + 1, m - 1);
  int b = solve(str, m + 1, r - 1);

  return merge(a, str[m], b);
}

int main() {
  int T;
  std::cin >> T;
  for (int t = 1; t <= T; ++t) {
    f.clear();

    int n;
    std::cin >> n;

    std::string str;
    std::map<int, int> map;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      std::cin >> str;
      int value = solve(str, 0, str.length() - 1);
      if (map.find(value) == map.end()) {
        map[value] = ++cnt;
      }
      ans[i] = map[value];
    }

    std::cout << "Case #" << t << ":";
    for (int i = 1; i <= n; ++i) {
      std::cout << " " << ans[i];
    }
    std::cout << std::endl;
  }
  return 0;
}
