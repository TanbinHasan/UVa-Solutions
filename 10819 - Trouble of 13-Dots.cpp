#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<pair<int,int>> ar(101);
vector<vector<int>> val;

int MaxVal(int n, int w, int sum) {
  if (sum > w + 200) return INT_MIN;
  if (n == 0) {
    if ((sum <= w) || (sum > 2000 && sum <= w + 200)) return 0;
    else return INT_MIN;
  }
  int &ret = val[n][sum];
  if (ret != -1) return ret;
  int opt1 = MaxVal(n - 1, w, sum + ar[n].first) + ar[n].second;
  int opt2 = MaxVal(n - 1, w, sum);
  return ret = max(opt1, opt2);
}

// #define MultipleCase
void Solve(int tc) {
  int w, n;
  while (cin >> w >> n) {
    for (int i = 1; i <= n; ++i) {
      cin >> ar[i].first >> ar[i].second;
    }
    val.assign(n + 1, vector<int> (w + 202, -1));
    cout << MaxVal(n, w, 0) << '\n';
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