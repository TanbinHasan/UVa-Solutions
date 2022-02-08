#include <bits/stdc++.h>

#define int long long

using namespace std;

int MaxSubMat(vector<vector<int>> &mat, int n) {
  vector<vector<int>> pref(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!j) pref[i][j] = mat[i][j];
      else pref[i][j] = pref[i][j - 1] + mat[i][j];
    }
  }
  int mxsum = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      vector<int> ar;
      for (int k = 0; k < n; ++k) {
        int x = ((i == 0) ? (pref[k][j]) : (pref[k][j] - pref[k][i - 1]));
        ar.push_back(x);
      }
      int mx = 0, sum = 0;
      for (auto &k : ar) {
        sum += k;
        mx = max(mx, sum);
        sum = max(0LL, sum);
      }
      mxsum = max(mxsum, mx);
    }
  }
  return mxsum;
}

#define MultipleCase           
void Solve(int tc) {
  if (tc > 1) cout << '\n';
  string s;
  cin >> s;
  int len = (int)s.size();
  vector<vector<int>> mat(len, vector<int>(len));
  for (int i = 0; i < len; ++i) {
    if (s[i] == '0') mat[0][i] = INT_MIN;
    else mat[0][i] = 1;
  }
  for (int i = 1; i < len; ++i) {
    cin >> s;
    for (int j = 0; j < len; ++j) {
      if (s[j] == '0') mat[i][j] = INT_MIN;
      else mat[i][j] = 1;
    }
  }
  cout << MaxSubMat(mat, len) << '\n';
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