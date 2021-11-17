/**
 *    author:  Tanbin_Hasan
 *    created: 18.11.2021 00:30:09
**/
#include <bits/stdc++.h>

using namespace std;

double BiSection(double p, double q, double r, double s, double t, double u) {
  auto func = [&](double mid) {
    return p * exp(-mid) + q * sin(mid) + r * cos(mid) + s * tan(mid) + t * mid * mid + u;
  };
  double low = 0.0, high = 1.0;
  if (func(low) * func(high) > 0.0) return -1.0;
  while (high - low >= 0.00000001) {
    double mid = (low + high) / 2;
    double x = func(mid);
    if (x <= 0.0) {
      high = mid;
    } else {
      low = mid;
    }
  }
  return (low + high) / 2;
}

void Aufdecken(void) {
  double p, q, r, s, t, u;
  while (cin >> p >> q >> r >> s >> t >> u) {
    double ans = BiSection(p, q, r, s, t, u);
    if (ans == -1.0) {
      cout << "No solution\n";
      continue;
    }
    cout << fixed << setprecision(4);
    cout << BiSection(p, q, r, s, t, u) << '\n';
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