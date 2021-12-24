/**
 *    author:  Tanbin_Hasan
 *    created: 24.12.2021 18:19:16
**/
#include <bits/stdc++.h>

using namespace std;

void Aufdecken(int TC) {
  int n, m;
  while (cin >> n >> m) {
    vector<vector<pair<int,int>>> adj(n + 1);
    while (m--) {
      int a, b, c;
      cin >> a >> b >> c;
      adj[a].push_back({b, c});
      adj[b].push_back({a, c});
    }
    priority_queue<tuple<int64_t,int,int>,vector<tuple<int64_t,int,int>>,greater<tuple<int64_t,int,int>>> q;
    vector<vector<int64_t>> dis(n + 1, vector<int64_t>(2, INT_MAX));
    dis[1][0] = 0;
    q.push({0, 1, 0});
    while (!q.empty()) {
      auto [nw, nx, tn] = q.top();
      q.pop();
      for (auto &[cx, cw] : adj[nx]) {
        int par = (tn + 1) % 2;
        if (dis[nx][tn] + cw < dis[cx][par]) {
          dis[cx][par] = dis[nx][tn] + cw;
          q.push({dis[cx][par], cx, par});
        }
      }
    }
    if (dis[n][0] == INT_MAX) {
      cout << -1 << '\n';
      continue;
    }
    cout << dis[n][0] << '\n';
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int TT = 1, TC = 0;
  // cin >> TT;
  while (++TC <= TT) {
    Aufdecken(TC);
  }
  return 0;
}