#include <bits/stdc++.h>

#define int long long

using namespace std;

#define MultipleCase          
void Solve(int tc) {
  int n, m, lim;
  cin >> n >> m >> lim;
  vector<vector<int>> pref(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int x;
      cin >> x;
      pref[i][j] = pref[i][j - 1] + x;
    }
  }
  int area = LLONG_MIN, cost = LLONG_MAX;
  for (int i = 1; i <= m; ++i) {
    for (int j = i; j <= m; ++j) {
      vector<int> ar;
      for (int k = 1; k <= n; ++k) {
        int x = pref[k][j] - pref[k][i - 1];
        ar.push_back(x);
      }
      int sum = 0, s = 0;
      for (int k = 0; k < (int)ar.size(); ++k) {
        sum += ar[k];
        while (sum > lim) sum -= ar[s++];
        int cur = (j - i + 1) * (k - s + 1);
        if (cur > area) {
          area = cur;
          cost = sum;
        } else if (cur == area) {
          cost = min(cost, sum);
        }
      }
    }
  }
  cout << "Case #" << tc << ": " << area << " " << cost << '\n';
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