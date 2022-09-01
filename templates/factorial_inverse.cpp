const int MAXN = 410;
const int MOD = 1e9 + 7;

int fac[MAXN];
int invf[MAXN];
int inv[MAXN];

void init() {
  fac[0] = invf[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    fac[i] = 1ll * fac[i - 1] * i % MOD;
    inv[i] = i == 1 ? 1 : (MOD - 1ll * (MOD / i) * inv[MOD % i] % MOD) % MOD;
    invf[i] = 1ll * invf[i - 1] * inv[i] % MOD;
  }
}
