#include <bits/stdc++.h>

#define int long long
#define ll __int128_t

using namespace std;

void PreCalc(void) {}

#define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  vector<string> vs;
  string s;
  while (getline(cin, s)) {
    if (s.empty()) break;
    vs.push_back(s);
  }
  int n = (int)vs.size();
  int m = (int)vs[0].size();
  vector<vector<bool>> vis(n + 1, vector<bool>(m + 1));
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (vs[i][j] != '1' || vis[i][j]) continue;
      int comp = 1;
      vis[i][j] = true;
      queue<pair<int, int>> q;
      q.push({i, j});
      while (!q.empty()) {
        auto [nx, ny] = q.front();
        q.pop();
        vector<pair<int,int>> all_adj_moves = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        for (auto& [dx, dy] : all_adj_moves) {
          int cx = nx + dx, cy = ny + dy;
          if (cx < 0 || cy < 0 || cx >= n || cy >= m) continue;
          if (vs[cx][cy] != '1' || vis[cx][cy]) continue;
          vis[cx][cy] = true;
          ++comp;
          q.push({cx, cy});
        }
      }
      ans = max(ans, comp);
    }
  }
  cout << ans << '\n';
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  PreCalc();
  int tt = 1, tc = 0;
#ifdef MultipleCase
  cin >> tt;
#endif
  // while (tt--) Solve(++tc);
  cin.ignore();
  cin.ignore();
  for (int tc = 1; tc <= tt; ++tc) {
    Solve(tc);
    if (tc != tt) cout << '\n';
  }
  return 0;
}