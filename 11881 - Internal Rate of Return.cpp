/**
 *    author:  Tanbin_Hasan
 *    created: 18.11.2021 18:01:01
**/
#include <bits/stdc++.h>
 
using namespace std;

void Aufdecken(void) {
  int n;
  while (cin >> n && n) {
    vector<double> ar(n + 1);
    for (auto &i : ar) {
      cin >> i;
    }
    double low = -0.9, high = numeric_limits<double>::max(), ans = -1.0;
    while (low <= high) {
      double mid = (low + high) / 2.0;
      double sum = 0;
      for (int i = 0; i <= n; ++i) {
        sum += ar[i] / pow((1.0 + mid), i);
      }
      if (abs(sum) <= 1e-9) {
        ans = mid;
        break;
      } else if (sum > 1e-9) {
        low = mid;
      } else {
        high = mid;
      }
    }
    if (ans == -1.0) {
      cout << "No\n";
    } else {
      cout << fixed << setprecision(2) << ans << '\n';
    }
  }
}
 
int main(void) {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int TT = 1, TC = 0;
  // cin >> TT; // Watch Carefully
  while (++TC <= TT) {
    Aufdecken();
  }
  return 0;
} 