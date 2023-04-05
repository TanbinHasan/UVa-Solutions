#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> TopoSorting(vector<vector<int>> &adj, int n) {
  vector<int> ind(n), ans;
  for (int i = 0; i < n; ++i) {
    for (auto &child : adj[i]) {
      ++ind[child];
    }
  }
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < n; ++i) {
    if (ind[i] == 0) pq.push(i);
  }
  int cnt = 0;
  while (!pq.empty()) {
    int node = pq.top();
    pq.pop();
    ans.push_back(node);
    for (auto &child : adj[node]) {
      if (--ind[child] == 0) pq.push(child);
    }
    ++cnt;
  }
  if (cnt != n) return {};
  return ans;
}

// #define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  int n, m;
  cin >> n >> m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) break;
    vector<vector<int>> adj(n);
    while (m--) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      adj[x].push_back(y);
    }
    auto ans = TopoSorting(adj, n);
    for (auto &i : ans) {
      cout << i + 1 << " ";
    }
    cout << '\n';
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