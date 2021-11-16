/**
 *    author:  Tanbin_Hasan
 *    created: 16.11.2021 23:46:09
**/
#include <bits/stdc++.h>
 
using namespace std;
 
double BiSection(double a, double b, double c) {
  double low = 0, high = c;
  double eps = 1e-6;
  while (high - low >= eps) {
    double mid = (low + high) / 2;
    double x = a * mid + b * sin(mid);
    if (x <= c) {
      low = mid;
    } else {
      high = mid;
    }
  }
  return (low + high) / 2;
}
 
void Aufdecken(void) {
  double a, b, c;
  cin >> a >> b >> c;
  cout << fixed << setprecision(6);
  cout << BiSection(a, b, c) << '\n';
}
 
int main(void) {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int TT = 1, TC = 0;
  cin >> TT; // Watch Carefully
  while (++TC <= TT) {
    Aufdecken();
  }
  return 0;
} 