#include <bits/stdc++.h>
using namespace std;

// if the graph isn't acylic topological sorting doesn't exist
class Graph {
  int n;
  vector<vector<int>> g;
  vector<int> vis, store;

 public:
  Graph(int n) : n(n), g(n), vis(n, -1) {}
  void add(int u, int v) { g[u].push_back(v); }

  bool dfs(int u) {
    vis[u] = 1;
    for (auto& v : g[u]) {
      if (vis[v] == 1) return false;
      if (vis[v] == -1) if (!dfs(v)) return false;
    }
    vis[u] = 2;
    store.push_back(u);
    return true;
  }

  vector<int> TopoSorting(void) {
    for (int i = 0; i < n; ++i) {
      if (vis[i] != -1) continue;
      if (!dfs(i)) return {};
    }
    reverse(store.begin(), store.end());
    return store;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  while (cin >> n >> m) {
    if (!n && !m) break;
    Graph g(n);
    while (m--) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g.add(u, v);
    }
    auto ans = g.TopoSorting();
    for (auto& i : ans) {
      cout << i + 1 << " ";
    }
    cout << '\n';
  }
  return 0;
}
/*
https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1246  
*/