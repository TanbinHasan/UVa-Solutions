#include <bits/stdc++.h>

#define int long long

using namespace std;

// #define MultipleCase           
void Solve(int tc) {
  int n, m;
  while (cin >> n >> m) {
    if (!n && !m) break;
    vector<vector<int>> pref(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        int x;
        cin >> x;
        pref[i][j] = ((x == 1) ? (INT_MIN) : (1));
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        pref[i][j] += pref[i][j - 1];
      }
    }
    int area = 0;
    for (int i = 1; i <= m; ++i) {
      for (int j = i; j <= m; ++j) {
        vector<int> ar;
        for (int k = 1; k <= n; ++k) {
          int x = pref[k][j] - pref[k][i - 1];
          ar.push_back(x);
        }
        int mx = 0, sum = 0;
        for (auto &k : ar) {
          sum += k;
          mx = max(mx, sum);
          sum = max(sum, 0LL);
        }
        area = max(area, mx);
      }
    }
    cout << area << '\n';
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