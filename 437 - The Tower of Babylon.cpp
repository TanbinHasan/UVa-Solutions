#include <bits/stdc++.h>

#define int long long

using namespace std;

// #define MultipleCase          
void Solve(int tc) {
  int n;
  while (cin >> n && n) {
    map<pair<int,int>,int> mp;
    map<pair<int,int>,int> val;
    vector<pair<int,int>> vp;
    while (n--) {
      vector<int> ar(3);
      for (auto &i : ar) {
        cin >> i;
      }
      sort(ar.begin(), ar.end());
      do {
        if (ar[0] <= ar[1]) {
          pair<int,int> p = {ar[0], ar[1]};
          if (mp[p] == 0) vp.push_back(p);
          mp[p] = max(mp[p], ar[2]);
        }
      } while (next_permutation(ar.begin(), ar.end()));
    }
    int mx = 0;
    for (auto &[x, y] : vp) {
      queue<tuple<int,int,int>> q;
      q.push({x, y, mp[{x, y}]});
      while (!q.empty()) {
        auto [a, b, c] = q.front();
        mx = max(mx, c);
        q.pop();
        for (auto &[x1, y1] : vp) {
          if (x1 >= a || y1 >= b || c + mp[{x1, y1}] <= val[{x1, y1}]) continue;
          val[{x1, y1}] = max(val[{x1, y1}], c + mp[{x1, y1}]);
          q.push({x1, y1, c + mp[{x1, y1}]});
        }
      }
    }
    cout << "Case " << tc++ << ": maximum height = " << mx << '\n';
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