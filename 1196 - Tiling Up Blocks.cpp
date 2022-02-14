#include <bits/stdc++.h>

#define int long long

using namespace std;

int LIS(vector<pair<int,int>> &vp) {
  vector<int> v;
  for (auto &[x, y] : vp) {
    auto it = upper_bound(v.begin(), v.end(), y);
    if (it == (v).end()) v.push_back(y);
    else *it = y;
  }
  return (int)v.size();
}

// #define MultipleCase       
void Solve(int tc) {
  int n;
  while (cin >> n) {
    if (n == 0) {
      cout << "*\n";
      break;
    }
    vector<pair<int,int>> vp(n);
    for (auto &[x, y] : vp) {
      cin >> x >> y;
    }
    sort(vp.begin(), vp.end());
    cout << LIS(vp) << '\n';
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