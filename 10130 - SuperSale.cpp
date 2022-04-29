#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<vector<int>> val;
vector<pair<int,int>> vp(1001);

int Max(int n, int w) {
  if (w < 0) return INT_MIN;
  if (w == 0 || n == 0) return 0;
  int &ret = val[n][w];
  if (ret != -1) return ret;
  int opt1 = Max(n - 1, w - vp[n].second) + vp[n].first;
  int opt2 = Max(n - 1, w);
  return ret = max(opt1, opt2);
}

#define MultipleCase       
void Solve(int tc) {
  int n;
  cin >> n;
  val.assign(n + 1, vector<int> (31, -1));
  for (int i = 1; i <= n; ++i) {
    cin >> vp[i].first >> vp[i].second;
  }
  int ans = 0;
  int m;
  cin >> m;
  while (m--) {
    int x;
    cin >> x;
    ans += Max(n, x);
  }
  cout << ans << '\n';
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