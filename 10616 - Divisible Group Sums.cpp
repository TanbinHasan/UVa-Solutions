#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> ar(201);
vector<vector<vector<int>>>  val;

int TotalWay(int n, int m, int w, int d) {
  if (n >= 0 && m == 0 && w % d == 0) return 1;
  if (n <= 0 || m <= 0) return 0;
  int &ret = val[n][m][w];
  if (ret != -1) return ret;
  ret = 0;
  int x = TotalWay(n - 1, m - 1, (w + ar[n]) % d, d);
  int y = TotalWay(n - 1, m, w, d);
  return ret = (x + y);
}

// #define MultipleCase       
void Solve(int tc) {
  int N, Q;
  while (cin >> N >> Q && (N || Q)) {
    cout << "SET " << tc++ << ":\n";
    vector<int> vi(N + 1);
    for (int i = 1; i <= N; ++i) {
      cin >> vi[i];
    }
    for (int q = 1; q <= Q; ++q) {
      cout << "QUERY " << q << ": ";
      int D, M;
      cin >> D >> M;
      for (int i = 1; i <= N; ++i) {
        ar[i] = ((vi[i] % D) + D) % D;
      }
      val.assign(N + 1, vector<vector<int>> (M + 1, vector<int> (D + 1, -1)));
      cout << TotalWay(N, M, D, D) << '\n';
    }
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