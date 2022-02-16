#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> LIS(vector<int> &ar, int n) {
  vector<int> v;
  vector<int> len(n);
  for (int i = 0; i < n; ++i) {
    auto it = lower_bound(v.begin(), v.end(), ar[i]);
    if (it == (v).end()) v.push_back(ar[i]);
    else *it = ar[i];
    len[i] = (int)v.size();
  }
  return len;
}

// #define MultipleCase       
void Solve(int tc) {
  int n;
  while (cin >> n) {
    vector<int> ar(n);
    for (auto &i : ar) {
      cin >> i;
    }
    auto len1 = LIS(ar, n);
    reverse(ar.begin(), ar.end());
    auto len2 = LIS(ar, n);
    int ans = 1;
    for (int i = 0; i < n; ++i) {
      int mn = min(len1[i], len2[n - 1 - i]);
      ans = max(ans, 2 * mn - 1);
    }
    cout << ans << '\n';
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