#include <bits/stdc++.h>

#define int long long

using namespace std;

// #define MultipleCase           
void Solve(int tc) {
  int n, m;
  bool nl = false;
  while (cin >> n >> m) {
    vector<vector<int>> mat(n, vector<int>(n));
    vector<vector<int>> pref(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> mat[i][j];
        pref[i + 1][j + 1] = mat[i][j];
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        pref[i][j] += pref[i][j - 1];
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        pref[j][i] += pref[j - 1][i];
      }
    }
    if (nl) cout << '\n';
    nl = true;
    int sum = 0;
    for (int r = 1; r <= n - m + 1; ++r) {
      int up = r, down = r + m - 1;
      for (int c = 1; c <= n - m + 1; ++c) {
        int left = c, right = c + m - 1;
        int x = pref[down][right] - pref[down][left - 1] - pref[up - 1][right] + pref[up - 1][left - 1];
        cout << x << '\n';
        sum += x;
      }
    }
    cout << sum << '\n';
  }
}

signed main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1, tc = 0;
  #ifdef MultipleCase
  cin >> tt;
  #endif
  while (tt--) Solve(++tc);
  return 0;
}