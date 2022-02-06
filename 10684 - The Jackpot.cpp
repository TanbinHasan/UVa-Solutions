#include <bits/stdc++.h>

#define int long long

using namespace std;

// #define MultipleCase           
void Solve(int tc) {
  int n;
  while (cin >> n && n) {
    vector<int> ar(n);
    for (auto &i : ar) {
      cin >> i;
    }
    int mx = 0;
    int sum = 0;
    for (auto &i : ar) {
      sum += i;
      mx = max(mx, sum);
      sum = max(0LL, sum);
    }
    if (mx == 0) {
      cout << "Losing streak.\n";
    } else {
      cout << "The maximum winning streak is " << mx << ".\n";
    }
  }
}

signed main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1, tc = 0;
  #ifdef MultipleCase
  cin >> tt;
  #endif
  while (tt--)  Solve(++tc);
  return 0;
}