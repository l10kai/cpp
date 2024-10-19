// a * x + b * y = gcd(a, b) 的一组特解
pll exgcd(i64 a, i64 b) {
  if (!b)
    return {1, 0};
  pll res = exgcd(b, a % b);
  return {res.se, res.fi - a / b * res.se};
}
