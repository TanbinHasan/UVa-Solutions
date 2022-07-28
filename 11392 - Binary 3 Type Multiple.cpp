#include <bits/stdc++.h>

#define int long long

using namespace std;

// #define MultipleCase       
void Solve(int tc) {
  int k;
  while (cin >> k) {
    int three = 0, opt1 = 0, opt2;
    vector<bool> vis(k + 1);
    tuple<int, int, int> ans;
    while (++three) {
      opt1 = (opt1 * 10 + 3) % k;
      opt2 = opt1;
      int zero = -1;
      bool ok = false;
      while (++zero >= 0) {
        if (opt2 == 0) {
          ok = true;
          ans = {three + zero, three, zero};
          break;
        }
        opt2 = (opt2 * 10) % k;
        if (vis[opt2]) break;
        vis[opt2] = true;
      }
      if (ok) break;
    }
    cout << get<0>(ans) << " " << get<1>(ans) << " " << get<2>(ans) << '\n';
  }
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1, tc = 0;
#ifdef MultipleCase
  cin >> tt;
#endif
  while (tt--) Solve(++tc);
  return 0;
}