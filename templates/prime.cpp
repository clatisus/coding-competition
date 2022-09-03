#include <vector>

namespace Prime {
std::vector<int> min, prime;

std::vector<int> mu, phi, cnt, power, sigma;

void init(int n) {
  int N = n + 10;
  min.resize(N);
  mu.resize(N);
  phi.resize(N);
  cnt.resize(N);
  power.resize(N);
  sigma.resize(N);
  mu[1] = phi[1] = sigma[1] = 1;

  for (int i = 2; i < N; ++i) {
    if (!min[i]) {
      min[i] = i;
      prime.push_back(i);

      mu[i] = -1;
      phi[i] = i - 1;
      cnt[i] = 1;
      power[i] = i;
      sigma[i] = i + 1;
    }
    for (auto u : prime) {
      if (i * u >= N) {
        break;
      }
      min[i * u] = u;
      if (i % u == 0) {
        mu[i * u] = 0;
        phi[i * u] = phi[i] * u;
        cnt[i * u] = cnt[i] + 1;
        power[i * u] = power[i] * u;
        sigma[i * u] = sigma[i / power[i]] * power[i * u] + sigma[i];

        break;
      }

      mu[i * u] = -mu[i];
      phi[i * u] = phi[i] * (u - 1);
      cnt[i * u] = 1;
      power[i * u] = u;
      sigma[i * u] = sigma[i] * (u + 1);
    }
  }
}

template <typename T> constexpr bool is_prime(T n) {
  if (n <= 1) {
    return false;
  }
  for (T i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

template <typename T> constexpr T primitive_root(T n) {
  T x = n - 1;
  T fact[20]{};
  int cnt = 0;
  for (T i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      fact[cnt++] = i;
      while (x % i == 0) {
        x /= i;
      }
    }
  }
  if (x > 1) {
    fact[cnt++] = x;
  }
  for (T i = 1; i < n; ++i) {
    bool flag = true;
    for (int j = 0; j < cnt; ++j) {
      if (powermod(i, (n - 1) / fact[j], n) == 1) {
        flag = false;
        break;
      }
    }
    if (flag) {
      return i;
    }
  }
  return -1;
}
} // namespace Prime
