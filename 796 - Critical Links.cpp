#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

class Graph {
  int n;
  vector<vector<int>> g;
  // d[] = discovery time, low[] = minimum discovery time among all the nodes in subtree
  vector<int> d, low;
  int timer;
 public:
  vector<bool> vis;
  vector<pair<int, int>> bridges;
  Graph(int n) {
    this->n = n;
    g.resize(n);
    vis.resize(n);
    d.resize(n);
    low.resize(n);
    timer = 0;
  }

  void add(int u, int v) { g[u].push_back(v); }

  void dfs(int u, int p = -1) {
    vis[u] = true;
    d[u] = low[u] = timer++;
    bool flag = false;
    for (auto& v : g[u]) {
      if (v == p && !flag) {
        flag = true;
        continue;
      }
      if (vis[v]) {  // u -> v is a back edge
        low[u] = min(low[u], d[v]);
      } else {  // u -> v is a tree edge
        dfs(v, u);
        low[u] = min(low[u], low[v]);
        if (d[u] < low[v]) { // bridges are identified
          bridges.push_back({min(u, v), max(u, v)});
        }
      }
    }
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    Graph g(n);
    for (int i = 0; i < n; ++i) {
      int u;
      cin >> u;
      int m;
      char ch;
      cin >> ch >> m >> ch;
      while (m--) {
        int v;
        cin >> v;
        g.add(u, v);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (!g.vis[i]) g.dfs(i);
    }
    sort(g.bridges.begin(), g.bridges.end());
    cout << (int)g.bridges.size() << " critical links\n";
    for (auto& [u, v] : g.bridges) {
      cout << u << " - " << v << '\n';
    }
    cout << '\n';
  }
  return 0;
}
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=9&page=show_problem&problem=737