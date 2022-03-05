#include <bits/stdc++.h>

#define int long long

using namespace std;

#define MultipleCase       
void Solve(int tc) {
  int n;
  cin >> n;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  int sum = accumulate(ar.begin(), ar.end(), 0LL);
  bitset<50001> valid(1);
  for (auto &i : ar) {
    for (int j = sum; j >= i; --j) {
      if (valid[j - i]) valid[j] = 1;
    }
  }
  int mn = LLONG_MAX;
  for (int i = 0; i < sum + 1; ++i) {
    if (!valid[i]) continue;
    int x = i;
    int y = sum - x;
    mn = min(mn, llabs(x - y));
  }
  cout << mn << '\n';
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