#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> val(1001);
vector<int> nxt(1001, -1);

vector<int> PathofLIS(vector<tuple<int,int,int>> &ar, int n) {
  for (int pos = n - 1; pos >= 0; --pos) {
    int len = 0;
    for (int i = pos + 1; i < n; ++i) {
      if (get<0>(ar[pos]) > get<0>(ar[i]) and -get<1>(ar[pos]) < -get<1>(ar[i])) {
        if (val[i] > len) {
          len = val[i];
          nxt[pos] = i;
        }
      }
    }
    val[pos] = len + 1;
  }
  vector<int> seq;
  int x = max_element(val.begin(), val.end()) - (val).begin();
  while (x != -1) {
    seq.push_back(-get<2>(ar[x]));
    x = nxt[x];
  }
  return seq;
}

// #define MultipleCase       
void Solve(int tc) {
  vector<tuple<int,int,int>> ar;
  int x, y;
  while (cin >> x >> y) {
    ar.push_back({y, -x, -tc++});
  }
  sort(ar.rbegin(), ar.rend());
  auto seq = PathofLIS(ar, (int)ar.size());
  cout << (int)seq.size() << '\n';
  for (auto &i : seq) {
    cout << i << '\n';
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