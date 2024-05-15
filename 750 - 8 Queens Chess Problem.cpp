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
vector<bool> col, ld, rd;
vector<vector<int>> store; // all solutions
vector<int> v; // current solution
void BackTrack(int n, int c, int x, int y) {
  if (c == n) { // all columns have been taken
    bool ok = false;
    for (int i = 0; i < n; ++i) {
      if (i == y && v[i] == x) {
        ok = true;
        break;
      }
    }
    if (ok) store.push_back(v);
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (col[i] || ld[i + c] || rd[i - c + n - 1]) continue;
    col[i] = ld[i + c] = rd[i - c + n - 1] = true;
    v.push_back(i);
    BackTrack(n, c + 1, x, y);
    col[i] = ld[i + c] = rd[i - c + n - 1] = false;
    v.pop_back();
  }
}

void PreCalc(void) {}

#define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  col.assign(MX, 0);
  ld = rd = vector<bool>(2 * MX - 1, false);
  store.clear();
  v.clear();

  int r, c;
  cin >> r >> c;
  BackTrack(8, 0, r - 1, c - 1);
  cout << "SOLN       COLUMN\n";
  cout << " #      1 2 3 4 5 6 7 8\n\n";
  for (int i = 0; i < (int)store.size(); ++i) {
    cout << setfill(' ') << setw(2) << i + 1 << "     ";
    for (auto j : store[i]) {
      cout << " " << j + 1;
    }
    cout << '\n';
  }
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(12);
  PreCalc();
  int tt = 1;
#ifdef MultipleCase
  cin >> tt;
#endif
  for (int tc = 1; tc <= tt; ++tc) {
    Solve(tc);
    if (tc != tt) cout << '\n';
  }
  return 0;
}