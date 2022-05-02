#include <bits/stdc++.h>

#define int long long

using namespace std;

#define MultipleCase       
void Solve(int tc) {
  string s;
  getline(cin >> ws, s);
  stringstream ss;
  ss << s;
  vector<int> ar;
  int x;
  while (ss >> x) {
    ar.push_back(x);
  }
  int sum = accumulate(ar.begin(), ar.end(), 0LL);
  if (sum & 1) {
    cout << "NO\n";
    return;
  }
  sum /= 2;
  vector<bool> vis(sum + 1);
  vis[0] = true;
  for (auto &i : ar) {
    for (int j = sum; j >= i; --j) {
      if (vis[j - i]) vis[j] = true;
    }
  }
  cout << ((vis[sum]) ? ("YES\n") : ("NO\n"));
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