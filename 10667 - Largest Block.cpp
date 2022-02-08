#include <bits/stdc++.h>

#define int long long

using namespace std;

#define MultipleCase          
void Solve(int tc) {
  int n;
  cin >> n;
  vector<vector<int>> pref(n + 1, vector<int>(n + 1, 1));
  for (int i = 1; i <= n; ++i) pref[i][0] = pref[0][i] = 0;
  int m;
  cin >> m;
  while (m--) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    for (int i = r1; i <= r2; ++i) {
      for (int j = c1; j <= c2; ++j) {
        pref[i][j] = INT_MIN;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      pref[i][j] += pref[i][j - 1];
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
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
      ans = max(ans, mx);
    }
  }
  cout << ans << '\n';
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