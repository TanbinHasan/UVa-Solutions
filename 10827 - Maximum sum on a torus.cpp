#include <bits/stdc++.h>

#define int long long

using namespace std;

int Kadane(deque<int> &ar) {
  int mx = LLONG_MIN, sum = 0;
  for (auto &i : ar) {
    sum += i;
    mx = max(mx, sum);
    sum = max(0LL, sum);
  }
  return mx;
}

int MaxSubMatSum(vector<vector<int>> &mat, int n) {
  vector<vector<int>> pref(n, vector<int>(2 * n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2 * n; ++j) {
      if (!j) pref[i][j] = mat[i][j];
      else pref[i][j] = pref[i][j - 1] + mat[i][j];
    }
  }
  int mxsum = LLONG_MIN;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < i + n; ++j) {
      vector<int> ar(n);
      deque<int> d(n);
      for (int k = 0; k < n; ++k) {
        int x = ((i == 0) ? (pref[k][j]) : (pref[k][j] - pref[k][i - 1]));
        d[k] = ar[k] = x;
      }
      mxsum = max(mxsum, Kadane(d));
      for (auto &k : ar) {
        if ((int)d.size() == n) {
          d.pop_front();
          d.push_back(k);
          mxsum = max(mxsum, Kadane(d));
        }
      }
    }
  }
  return mxsum;
}

#define MultipleCase           
void Solve(int tc) {
  int n;
  cin >> n;
  vector<vector<int>> mat(n, vector<int>(2 * n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x;
      cin >> x;
      mat[i][j] = mat[i][j + n] = x;
    }
  }
  cout << MaxSubMatSum(mat, n) << '\n';
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