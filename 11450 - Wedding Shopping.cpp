#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long

template <class T,class C = less<T>> using iset = tree<T,null_type,C,rb_tree_tag,tree_order_statistics_node_update>;
template <class T,class C = less_equal<T>> using imultiset = tree<T,null_type,C,rb_tree_tag,tree_order_statistics_node_update>;

vector<vector<int>> ar;
vector<vector<int>> val;

int MxMoney(int n, int m, int sum, int pos) {
  if (sum > n) return LLONG_MIN;
  if (pos == m) return sum;
  if (val[sum][pos] != -1) return val[sum][pos];
  int mx = LLONG_MIN;
  for (auto &i : ar[pos]) {
    mx = max(mx, MxMoney(n, m, sum + i, pos + 1));
  }
  return val[sum][pos] = mx;
}

#define MultipleCase    
void Solve(int tc) {
  int n, m;
  cin >> n >> m;
  ar.assign(m, {});
  val.assign(n + 1, vector<int>(m, -1));
  for (int i = 0; i < m; ++i) {
    int sz;
    cin >> sz;
    ar[i].resize(sz);
    for (auto &j : ar[i]) {
      cin >> j;
    }
  }
  int res = MxMoney(n, m, 0, 0);
  if (res < 0) {
    cout << "no solution\n";
  } else {
    cout << res << '\n';
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