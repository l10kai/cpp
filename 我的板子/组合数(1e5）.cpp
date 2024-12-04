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

void init() {
  fac[0] = 1;
  for (int i = 1; i <= M; i++)
    fac[i] = fac[i - 1] * i % mod;
  fnv[M] = fpow(fac[M], mod - 2);
  for (int i = M; i >= 1; i--)
    fnv[i - 1] = fnv[i] * i % mod;
  // assert(fnv[1] == 1);
}

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
