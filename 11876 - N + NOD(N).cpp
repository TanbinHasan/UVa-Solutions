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

const int MX = 1000001;
vector<int> NOD(MX), N(2, 0);
void PreCalc(void) {
  for (int i = 1; i < MX; ++i) {
    for (int j = i; j < MX; j += i) ++NOD[j];
  }
  N[1] = 1;
  for (int i = 2; i < MX; ++i) {
    int cur = N[i - 1] + NOD[N[i - 1]];
    N.push_back(cur);
    if (N.back() > MX) break;
  }
}

#define MultipleCase
void Solve(__attribute__((unused)) int tc) {
  cout << "Case " << tc << ": ";
  int a, b;
  cin >> a >> b;
  int l = lower_bound(N.begin(), N.end(), a) - (N).begin();
  int r = upper_bound(N.begin(), N.end(), b) - (N).begin() - 1;
  cout << (r - l + 1) << '\n';
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  PreCalc();
  int tt = 1, tc = 0;
#ifdef MultipleCase
  cin >> tt;
#endif
  while (tt--) Solve(++tc);
  return 0;
}