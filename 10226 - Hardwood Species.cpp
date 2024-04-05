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

void PreCalc(void) {}

#define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  string s;
  map<string, int> cnt;
  int tot = 0;
  while (getline(cin, s)) {
    if (s.empty()) break;
    ++cnt[s];
    ++tot;
  }
  for (auto& [x, y] : cnt) {
    cout << x << " ";
    cout << fixed << setprecision(4) << (long double) y / tot * 100.0l << '\n';
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
  cin.ignore();
  cin.ignore();
  while (tt--) {
    Solve(++tc);
    if (tt) cout << '\n';
  }
  return 0;
}