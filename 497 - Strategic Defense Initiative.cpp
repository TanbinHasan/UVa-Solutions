#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> LIS(vector<int> &ar, int n) {
  vector<int> temp(n);
  vector<int> Prev(n, -1);
  int len = 1;
  for (int i = 1; i < n; ++i) {
    if (ar[i] < ar[temp[0]]) temp[0] = i;
    else if (ar[i] > ar[temp[len - 1]]) {
      Prev[i] = temp[len - 1];
      temp[len++] = i;
    } else {
      int low = 0, high = len - 1, pos = len - 1;
      while (low <= high) {
        int mid = low + (high - low) / 2;
        if (ar[temp[mid]] >= ar[i]) { // Lower Bound
          pos = mid;
          high = mid - 1;
        } else low = mid + 1;
      }
      if (pos) Prev[i] = temp[pos - 1];
      temp[pos] = i;
    }
  }
  vector<int> seq;
  for (int i = temp[len - 1]; i != -1; i = Prev[i]) seq.push_back(ar[i]);
  reverse(seq.begin(), seq.end());
  return seq;
}

#define MultipleCase       
void Solve(int tc) {
  cin.ignore();
  vector<int> ar;
  do {
    int x;
    cin >> x;
    ar.push_back(x);
    cin.ignore();
  } while (cin.peek() >= '0' && cin.peek() <= '9');
  int n = (int)ar.size();
  auto seq = LIS(ar, n);
  if (tc > 1) cout << '\n';
  cout << "Max hits: " << (int)seq.size() << '\n';
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