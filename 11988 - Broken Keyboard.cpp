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

// #define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  string s;
  while (getline(cin >> ws, s)) {
    list<char> l;
    auto it = (l).begin();
    for (auto& i : s) {
      if (i == '[') it = (l).begin();
      else if (i == ']') it = (l).end();
      else l.insert(it, i);
    }
    for (auto& i : l) {
      cout << i;
    }
    cout << '\n';
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
  while (tt--) Solve(++tc);
  return 0;
}