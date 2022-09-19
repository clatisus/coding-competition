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

int main() {
  int T;
  std::cin >> T;
  for (int t = 1; t <= T; ++t) {
    int n;
    std::cin >> n;

    std::vector<std::pair<std::string, int>> a;
    std::vector<std::pair<int, int>> b;
    for (int i = 1; i <= n; ++i) {
      std::string c;
      int d, u;
      std::cin >> c >> d >> u;

      a.emplace_back(c, u);
      b.emplace_back(d, u);
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += a[i].second == b[i].second;
    }
    std::cout << "Case #" << t << ": " << ans << std::endl;
  }
  return 0;
}
