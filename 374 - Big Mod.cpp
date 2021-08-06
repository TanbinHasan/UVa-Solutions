/**
 *    author:  Tanbin_Hasan
 *    created: 06.08.2021 13:27:08
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
  int a, b, x;
  while (cin >> a >> b >> x) {
    cout << BigMod(a, b , x) << '\n';
  }
  return 0;
}