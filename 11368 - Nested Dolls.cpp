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
  int n;
  cin >> n;
  vector<pair<int, int>> vp(n);
  for (auto& [x, y] : vp) {
    cin >> x >> y;
  }
  sort(vp.begin(), vp.end(), [&](pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
  });
  deque<int> dq;
  for (auto& [x, y] : vp) {
    int it = lower_bound(dq.begin(), dq.end(), y) - (dq).begin();
    if (it == 0) dq.push_front(y);
    else dq[it - 1] = y;
  }
  cout << (int)dq.size() << '\n';
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