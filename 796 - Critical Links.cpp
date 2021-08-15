/**
 *    author:  Tanbin_Hasan
 *    created: 14.08.2021 19:48:44
**/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> D;
vector<int> low;
int cnt;
set<pair<int,int>> bridge;

void DFS(int node, int par) {
  vis[node] = true;
  D[node] = low[node] = cnt++;
  for (auto &child : adj[node]) {
    if (child == par) continue;
    if (vis[child]) {
      low[node] = min(low[node], D[child]);
    } else {
      DFS(child, node);
      if (low[child] > D[node]) {
        bridge.insert({min(child, node) , max(child, node)});
      }
      low[node] = min(low[node], low[child]);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int nodes;
  while (cin >> nodes) {
    adj.assign(nodes, {});
    vis.assign(nodes, false);
    D.assign(nodes, 0);
    low.assign(nodes, 0);
    cnt = 0;
    bridge.clear();
    for (int i = 0; i < nodes; ++i) {
      int par, no;
      char ch;
      cin >> par;
      cin >> ch >> no >> ch;
      while (no--) {
        int x;
        cin >> x;
        adj[par].push_back(x);
      }
    }
    for (int i = 0; i < nodes; ++i) {
      if (!vis[i]) {
        DFS(i, -1);
      }
    }
    cout << (int)bridge.size() << " critical links\n";
    for (auto &i : bridge) {
      cout << i.first << " - " << i.second << '\n';
    }
    cout << '\n';
  }
  return 0;
}