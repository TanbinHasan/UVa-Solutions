/**
 *    author:  Tanbin_Hasan
 *    created: 18.11.2021 02:03:47
**/
#include <bits/stdc++.h>
 
using namespace std;

int Consumption(int cost) {
  int sum = 0;
  vector<pair<int,int>> ar = {{2, 100}, {3, 9900}, {5, 990000}, {7, (int)1e9}};
  for (auto &[x, y] : ar) {
    int a = cost / x;
    if (a > y) sum += y, cost -= y * x;
    else sum += a, cost -= a * x;
  }
  return sum;
}

int64_t Cost(int consumption) {
  int64_t sum = 0;
  vector<pair<int,int>> ar = {{2, 100}, {3, 9900}, {5, 990000}, {7, (int)1e9}};
  for (auto &[y, x] : ar) {
    if (consumption > x) {
      consumption -= x;
      sum += (x * y);
    } else {
      sum += (consumption * y);
      consumption = 0;
    }
  }
  return sum;
}

void Aufdecken(void) {
  int a, b;
  while (cin >> a >> b && (a || b)) {
    int tot = Consumption(a);
    int low = 1, high = tot;
    int64_t ans = LONG_LONG_MAX;
    while (low <= high) {
      int x = low + (high - low) / 2;
      int y = tot - x;
      int64_t p = Cost(x);
      int64_t q = Cost(y);
      if (q - p == b) {
        ans = p;
        break;
      } else if (q - p > b) {
        low = x + 1;
      } else {
        high = x - 1;
      }
    }
    cout << ans << '\n';
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