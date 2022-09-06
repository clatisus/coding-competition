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
#include <string>
#include <vector>

double f[70][70][70];
char choose[70][70][70];

int main() {
  int T, _;
  scanf("%d%d", &T, &_);
  for (int t = 1; t <= T; ++t) {
    int W, E;
    scanf("%d%d", &W, &E);

    for (int r = 0; r <= 60; ++r) {
      for (int p = 0; p <= 60; ++p) {
        for (int s = 0; s <= 60; ++s) {
          f[r][p][s] = 0;
        }
      }
    }

    f[1][0][0] = f[0][1][0] = f[0][0][1] = (W + E) / 3.0;
    choose[1][0][0] = 'R';
    choose[0][1][0] = 'P';
    choose[0][0][1] = 'S';
    for (int n = 2; n <= 60; ++n) {
      for (int r = 0; r <= n; ++r) {
        for (int p = 0; p + r <= n; ++p) {
          int s = n - r - p;
          double fr = -1e20, fp = -1e20, fs = -1e20;
          if (r >= 1) {
            fr = f[r - 1][p][s] + 1.0 * p * W / (n - 1) + 1.0 * s * E / (n - 1);
          }
          if (p >= 1) {
            fp = f[r][p - 1][s] + 1.0 * s * W / (n - 1) + 1.0 * r * E / (n - 1);
          }
          if (s >= 1) {
            fs = f[r][p][s - 1] + 1.0 * r * W / (n - 1) + 1.0 * p * E / (n - 1);
          }
          if (fr > fp && fr > fs) {
            f[r][p][s] = fr;
            choose[r][p][s] = 'R';
          } else if (fp > fr && fp > fs) {
            f[r][p][s] = fp;
            choose[r][p][s] = 'P';
          } else {
            f[r][p][s] = fs;
            choose[r][p][s] = 'S';
          }
        }
      }
    }

    int mr = 0, mp = 0, ms = 60;
    for (int r = 0; r <= 60; ++r) {
      for (int p = 0; p + r <= 60; ++p) {
        int s = 60 - p - r;
        if (f[r][p][s] > f[mr][mp][ms]) {
          mr = r;
          mp = p;
          ms = s;
        }
      }
    }

    std::string ans;
    while (mr || mp || ms) {
      ans += choose[mr][mp][ms];
      if (choose[mr][mp][ms] == 'R') {
        --mr;
      } else if (choose[mr][mp][ms] == 'P') {
        --mp;
      } else {
        --ms;
      }
    }
    std::reverse(ans.begin(), ans.end());

    printf("Case #%d: %s\n", t, ans.c_str());
  }
  return 0;
}
