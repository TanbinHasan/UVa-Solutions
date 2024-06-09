#include <bits/stdc++.h>

#define int long long

using namespace std;

bitset<1201> vis(3);
vector<int> GenPrime(int n) {
  vector<int> prime(2, 1);
  prime[1] = 2;
  for (int i = 3; i <= n; i += 2) {
    if (vis[i]) continue;
    prime.push_back(i);
    for (int j = i * i; j <= n; j += 2 * i) {
      vis[j] = 1;
    }
  }
  return prime;
}

auto prime = GenPrime(1200);

int val[1200][15][200];

int TotalWay(int n, int k, int p) {
  if (n == 0 && k == 0) return 1;
  if (n < 0 || k < 0) return 0;
  int &ret = val[n][k][p];
  if (ret != -1) return ret;
  ret = 0;
  int cur = upper_bound(prime.begin(), prime.end(), prime[p]) - (prime).begin();
  for (int i = cur; i < (int)prime.size(); ++i) {
    if (n - prime[i] < 0) break;
    ret += TotalWay(n - prime[i], k - 1, i);
  }
  return ret;
}

// #define MultipleCase       
void Solve(int tc) {
  int n, k;
  while (cin >> n >> k && (n || k)) {
    memset(val, -1, sizeof val);
    cout << TotalWay(n, k, 0) << '\n';
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