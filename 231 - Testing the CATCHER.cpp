#include <bits/stdc++.h>

#define int long long

using namespace std;

int LIS(vector<int> &ar) {
  vector<int> v;
  for (auto &i : ar) {
    auto it = upper_bound(v.begin(), v.end(), i);
    if (it == (v).end()) v.push_back(i);
    else *it = i;
  }
  return (int)v.size();
}

// #define MultipleCase          
void Solve(int tc) {
  int n, pre = 0;
  vector<int> ar;
  while (cin >> n) {
    if (n == -1 && pre == -1) break;
    pre = n;
    if (n == -1) {
      reverse(ar.begin(), ar.end());
      if (tc > 1) cout << '\n';
      cout << "Test #" << tc++ << ":\n";
      cout << "  maximum possible interceptions: " << LIS(ar) << '\n';
      ar.clear();
      continue;
    }
    ar.push_back(n);
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