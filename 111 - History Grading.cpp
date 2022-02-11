#include <bits/stdc++.h>

#define int long long

using namespace std;

int LIS(vector<int> &ar) {
  vector<int> v;
  for (auto &i : ar) {
    auto it = lower_bound(v.begin(), v.end(), i);
    if (it == (v).end()) v.push_back(i);
    else *it = i;
  }
  return (int)v.size();
}

// #define MultipleCase          
void Solve(int tc) {
  int n;
  vector<int> order(21);
  vector<int> v;
  string s, temp;
  while (getline(cin >> ws, s)) {
    v.clear();
    stringstream ss(s);
    while (ss >> temp) v.push_back(stoll(temp));
    if ((int)v.size() == 1) {
      n = v.front();
      for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        order[i] = x;
      }
      continue;
    }
    vector<int> ar(n + 1, 25);
    for (int i = 1; i <= n; ++i) {
      ar[v[i - 1]] = order[i];
    }
    cout << LIS(ar) << '\n';
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