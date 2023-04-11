#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<vector<int>> ans;
vector<int> v;
vector<bool> vis;
void Rec(vector<vector<int>> &adj, int n) {
  if ((int)v.size() == n) {
    ans.push_back(v);
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (vis[i]) continue;
    for (auto &child : adj[i])
      if (vis[child]) return; // cycle
    vis[i] = true;
    v.push_back(i);
    Rec(adj, n);
    vis[i] = false;
    v.pop_back();
  }
}

vector<vector<int>> AllTopoSorting(vector<vector<int>> &adj, int n) {
  v.clear();
  ans.clear();
  vis.assign(n, false);
  Rec(adj, n);
  return ans;
}

string f(string s) {
  string t;
  for (auto &i : s) {
    if (isalpha(i)) t.push_back(i);
  }
  return t;
}

int pos(string &s, char ch) {
  return lower_bound(s.begin(), s.end(), ch) - (s).begin();
}

// #define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  string s;
  bool ok = false;
  while (getline(cin >> ws, s)) {
    string t;
    getline(cin >> ws, t);
    s = f(s);
    t = f(t);
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    int n = (int)s.size();
    vector<vector<int>> adj(n);
    for (int i = 1; i < (int)t.size(); i += 2) {
      int x = pos(s, t[i - 1]), y = pos(s, t[i]);
      adj[x].push_back(y);
    }
    if (ok) cout << '\n';
    ok = true;
    auto ans = AllTopoSorting(adj, n);
    for (auto &i : ans) {
      for (auto &j : i) {
        cout << s[j];
      }
      cout << '\n';
    }
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