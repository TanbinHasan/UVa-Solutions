/**
 *    author:  Tanbin_Hasan
 *    created: 17.11.2021 17:02:24
**/
#include <bits/stdc++.h>
 
using namespace std;

void Aufdecken(void) {
  int n;
  cin >> n;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  int low = 1, high = 1e9, ans = 1e9;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    int k = mid;
    bool ok = true;
    if (ar[0] > mid) ok = false;
    if (ar[0] == mid) --k;
    for (int i = 1; i < n; ++i) {
      int dif = ar[i] - ar[i - 1];
      if (dif > k) {
        ok = false;
        break;
      }
      if (dif == k) --k;
    }
    if (ok) {
      high = mid - 1;
      ans = min(ans, mid);
    } else {
      low = mid + 1;
    }
  }
  cout << ans << '\n';
}
 
int main(void) {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int TT = 1, TC = 0;
  cin >> TT; // Watch Carefully
  while (++TC <= TT) {
    cout << "Case " << TC << ": ";
    Aufdecken();
  }
  return 0;
} 