constexpr i64 mod = 998244353;

i64 fpow(i64 a, i64 x) {
  i64 res = 1;
  while (x) {
    if (x & 1)
      res = res * a % mod;
    a = a * a % mod;
    x >>= 1;
  }
  return res % mod;
}

const i64 M = 1e5;
i64 fac[M + 10], fnv[M + 10];

i64 C(i64 n, i64 m) {
  if (m < 0 || m > n)
    return 0;
  return fac[n] * fnv[m] % mod * fnv[n - m] % mod;
} // c(n,m)
i64 A(i64 n, i64 m) {
  if (m < 0 || m > n)
    return 0;
  return fac[n] * fnv[m] % mod;
} // a(n,m);
