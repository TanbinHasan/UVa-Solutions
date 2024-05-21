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

bool f(vector<int>& a, int pos, int sum) {
  if (pos == 5) return (sum == 23);
  return f(a, pos + 1, sum + a[pos]) || f(a, pos + 1, sum - a[pos]) || f(a, pos + 1, sum * a[pos]);
}

void PreCalc(void) {}

// #define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  while (1) {
    vector<int> a(5);
    for (auto& i : a) {
      cin >> i;
    }
    sort(a.begin(), a.end());
    if (a.front() == a.back() && a.front() == 0) break;
    bool ok = false;
    do {
      if (f(a, 1, a.front())) {
        ok = true;
        break;
      }
    } while (next_permutation(a.begin(), a.end()));
    cout << ((ok) ? ("Possible") : ("Impossible")) << '\n';
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