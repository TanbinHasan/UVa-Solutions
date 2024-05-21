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

const int MX = 8;
vector<bool> col(MX), ld(MX * 2 - 1), rd(MX * 2 - 1);
vector<vector<int>> store;
vector<int> v;

void BackTrack(int n, int c) {
  if (c == n) {
    store.push_back(v);
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (col[i] || ld[i + c] || rd[i - c + n - 1]) continue;
    col[i] = ld[i + c] = rd[i - c + n - 1] = true;
    v.push_back(i + 1);
    BackTrack(n, c + 1);
    col[i] = ld[i + c] = rd[i - c + n - 1] = false;
    v.pop_back();
  }
}

void PreCalc(void) {
  BackTrack(8, 0);
}

// #define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  while (1) {
    vector<int> a(8);
    for (auto& i : a) {
      cin >> i;
    }
    if (a.front() == 0) break;
    int mn = 8;
    for (auto& v : store) {
      int cur = 0;
      for (int i = 0; i < 8; ++i) {
        if (v[i] != a[i]) ++cur;
      }
      mn = min(mn, cur);
    }
    cout << "Case " << tc++ << ": " << mn << '\n';
  }
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(12);
  PreCalc();
  int tt = 1, tc = 0;
#ifdef MultipleCase
  cin >> tt;
#endif
  while (tt--) Solve(++tc);
  return 0;
}