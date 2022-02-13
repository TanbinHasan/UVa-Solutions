#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> LIS(vector<int> &ar, int n) {
  vector<int> temp(n);
  vector<int> Prev(n, -1);
  int len = 1;
  for (int i = 1; i < n; ++i) {
    if (ar[i] < ar[temp[0]]) {
      temp[0] = i;
      continue;
    } else if (ar[i] > ar[temp[len - 1]]) {
      Prev[i] = temp[len - 1];
      temp[len++] = i;
      continue;
    }
    int low = 0, high = len - 1, pos = len - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (ar[temp[mid]] >= ar[i]) {
        pos = mid;
        high = mid - 1;
      } else low = mid + 1;
    }
    if (pos) Prev[i] = temp[pos - 1];
    temp[pos] = i;
  }
  vector<int> seq;
  for (int i = temp[len - 1]; i != -1; i = Prev[i]) seq.push_back(ar[i]);
  reverse(seq.begin(), seq.end());
  return seq;
}

// #define MultipleCase       
void Solve(int tc) {
  vector<int> ar;
  int x;
  while (cin >> x) ar.push_back(x);
  int n = (int)ar.size();
  auto seq = LIS(ar, n);
  cout << (int)seq.size() << "\n-\n";
  for (auto &i : seq) {
    cout << i << '\n';
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