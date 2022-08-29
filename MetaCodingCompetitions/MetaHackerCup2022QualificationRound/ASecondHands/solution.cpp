#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <vector>

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int N, K;
    scanf("%d%d", &N, &K);
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
    }
    std::sort(A.begin(), A.end());
    std::vector<int> a, b;
    bool flag = true;
    for (int i = 0, j; i < N; i = j) {
      for (j = i; j < N && A[j] == A[i]; ++j)
        ;
      if (j - i > 2) {
        flag = false;
        break;
      } else if (j - i == 2) {
        a.push_back(A[i]);
        b.push_back(A[i + 1]);
      } else if (a.size() < b.size()) {
        a.push_back(A[i]);
      } else {
        b.push_back(A[i]);
      }
    }
    if (!flag || a.size() > K || b.size() > K) {
      printf("Case #%d: NO\n", t);
    } else {
      printf("Case #%d: YES\n", t);
    }
  }
  return 0;
}
