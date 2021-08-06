/**
 *    author:  Tanbin_Hasan
 *    created: 06.08.2021 14:03:33
**/
#include <bits/stdc++.h>

using namespace std;

int BigMod(int a, int b , int mod) {
  if (!b) {
    return 1;
  }
  if (b & 1) {
    return ((a % mod) * BigMod(a, b - 1, mod)) % mod;
  }
  int res = BigMod(a, b >> 1, mod);
  return ((res % mod) * (res % mod)) % mod;
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int trail = BigMod(n, k, 1000);
    long double pw = (long double)k * log10l((long double)n);
    int lead = powl(10.0L, pw - (int)pw) * 100.0L;
    cout << lead << "..." << setfill('0') << setw(3) << trail << '\n';
  }
  return 0;
}