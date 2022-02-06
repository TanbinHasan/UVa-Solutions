#include <bits/stdc++.h>

#define int long long

using namespace std;

#define MultipleCase           
void Solve(int tc) {
  int n;
  cin >> n;
  int mx = 0;
  int start = 1, s = 0, f = 0;
  int sum = 0;
  for (int i = 2; i <= n; ++i) {
    int x;
    cin >> x;
    sum += x;
    if (sum < 0) {
      sum = 0;
      start = i;
    }
    if (sum >= mx) {
      if (sum > mx || i - start > f - s) {
        s = start;
        f = i;
      }
      mx = sum;
    }
  }
  if (mx <= 0) {
    cout << "Route " << tc << " has no nice parts\n";
  } else {
    cout << "The nicest part of route " << tc << " is between stops " << s << " and " << f << '\n'; 
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