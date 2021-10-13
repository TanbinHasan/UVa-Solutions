/**
 *    author:  Tanbin_Hasan
 *    created: 14.10.2021 04:12:23
**/
#include <bits/stdc++.h>

using namespace std;

int64_t GCD(int64_t a, int64_t b, int64_t &x, int64_t &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  int64_t x1, y1;
  int64_t G = GCD(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return G;
}

void Run_Case(void) {
  int64_t a, b, x, y;
  while (cin >> a >> b) {
    int64_t G = GCD(a, b, x, y);
    cout << x << ' ' << y << ' ' << G << '\n';
  }
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int total_test = 1, test_case = 0;
  // cin >> total_test; // Watch Carefully
  while (++test_case <= total_test) {
    Run_Case();
  }
  return 0;
}