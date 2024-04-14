#include <bits/stdc++.h>

#define int long long
#define ll __int128_t

using namespace std;

template <int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
  static_assert(D >= 1);
  template <typename... Args>
  Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};
template <typename T>
struct Vec<1, T> : public vector<T> {
  Vec(int n = 0, const T& val = T()) : vector<T>(n, val) {}
};

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int32_t LIM = 100;  // b + 1
using T = array<int32_t, 2>;
const T mod = {127657753, 987654319};
const T B = {137, 277};
T pw[LIM], ipw[LIM];
bool iscalc;
T operator+(T a, T b) { return {(a[0] + b[0]) % mod[0], (a[1] + b[1]) % mod[1]}; }
T operator-(T a, T b) { return {(a[0] - b[0] + mod[0]) % mod[0], (a[1] - b[1] + mod[1]) % mod[1]}; }
T operator*(T a, T b) { return {(int32_t)(1LL * a[0] * b[0] % mod[0]), (int32_t)(1LL * a[1] * b[1] % mod[1])}; }

int32_t power(int b, int p, int mod) {
  b %= mod;
  if (b < 0) b += mod;
  int32_t res = 1;
  while (p) {
    if (p & 1) res = (1LL * (res % mod) * (b % mod)) % mod;
    b = (1LL * (b % mod) * (b % mod)) % mod;
    p >>= 1;
  }
  return res;
}

class Hashing {
  bool PreCalc(void) {
    T iB = {power(B[0], mod[0] - 2, mod[0]), power(B[1], mod[1] - 2, mod[1])};
    pw[0] = ipw[0] = {1, 1};
    for (int i = 1; i < LIM; ++i) {
      pw[i] = pw[i - 1] * B;
      ipw[i] = ipw[i - 1] * iB;
    }
    return true;
  }
  array<T, 2> f(char c, int i) {
    T a = {(int32_t)(1LL * c * pw[i][0] % mod[0]), (int32_t)(1LL * c * pw[i][1] % mod[1])};
    T b = {(int32_t)(1LL * c * pw[n - 1 - i][0] % mod[0]), (int32_t)(1LL * c * pw[n - 1 - i][1] % mod[1])};
    return {a, b};
  }
  int n;
  vector<array<T, 2>> h;  // (normal, rev) hash
 public:
  Hashing(string s) {
    if (!iscalc) iscalc = PreCalc();
    n = (int)s.size();
    h.resize(n);
    for (int i = 0; i < n; ++i) {
      auto [a, b] = f(s[i], i);
      h[i][0] = a + (i == 0 ? (T){0, 0} : h[i - 1][0]);
      h[i][1] = b + (i == 0 ? (T){0, 0} : h[i - 1][1]);
    }
  }
  T get_h(int l, int r) {
    T x = h[r][0] - (l == 0 ? (T){0, 0} : h[l - 1][0]);
    return x * ipw[l];
  }
  T get_rh(int l, int r) {
    T x = h[r][1] - (l == 0 ? (T){0, 0} : h[l - 1][1]);
    return x * ipw[n - 1 - r];
  }
};

void PreCalc(void) {}

#define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  string s;
  cin >> s;
  int n = (int)s.size();
  Hashing h(s);
  auto f = [&](int m) {
    T cur = h.get_h(0, m - 1);
    for (int i = 0; i + m - 1 < n; i += m) {
      if (h.get_h(i, i + m - 1) != cur) return false;
    }
    return true;
  };
  for (int i = 1; i <= n; ++i) {
    if (n % i) continue;
    if (f(i)) {
      cout << i << '\n';
      return;
    }
  }
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  PreCalc();
  int tt = 1, tc = 0;
#ifdef MultipleCase
  cin >> tt;
#endif
  while (tt--) {
    Solve(++tc);
    if (tt) cout << '\n';
  }
  return 0;
}