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
    std::string s;
    std::cin >> s;

    std::vector<std::pair<char, int>> vec;
    std::vector<int> cnt(26, 0);
    for (int i = 0; i < s.size(); ++i) {
      vec.push_back({s[i], i});
      cnt[s[i] - 'a']++;
    }
    std::sort(vec.begin(), vec.end());

    int max_cnt = *std::max_element(cnt.begin(), cnt.end());
    if (2 * max_cnt > vec.size()) {
      std::cout << "Case #" << t << ": "
                << "IMPOSSIBLE" << std::endl;
      continue;
    }

    std::vector<std::pair<char, int>> vec2(vec.size());
    for (int i = 0; i < vec.size(); ++i) {
      vec2[i] = {vec[(i - max_cnt + vec.size()) % vec.size()].first,
                 vec[i].second};
    }

    std::sort(vec2.begin(), vec2.end(),
              [](const std::pair<char, int> &a, const std::pair<char, int> &b) {
                return a.second < b.second;
              });

    std::string ans;
    for (auto [c, _] : vec2) {
      ans.push_back(c);
    }

    std::cout << "Case #" << t << ": " << ans << std::endl;
  }
  return 0;
}
