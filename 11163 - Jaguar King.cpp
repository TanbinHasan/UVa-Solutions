#include <bits/stdc++.h>
#define int long long
#define ll __int128_t
using namespace std;
using vvi = vector<vector<int>>;

const int MX = 41;
vvi adj_moves = {{-3, -1, 4, -4}, {1, 3, 4, -4}, {1, -1, 4, -4}, {1, -1, 4, -4}};
vvi dis(MX, vector<int>(MX, INT_MAX));

void PreCalc(void) {
  for (int i = 1; i < MX; ++i) {
    dis[i][i] = 0;
    for (auto& dx : adj_moves[i % 4]) {
      int cx = i + dx;
      if (cx < 1 || cx >= MX) continue;
      dis[i][cx] = 1;
    }
  }
  for (int k = 1; k < MX; ++k) {
    for (int i = 1; i < MX; ++i) {
      for (int j = 1; j < MX; ++j) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
}

int CalculateHeuristic(vector<int>& a) {
  int n = (int)a.size(), heuristic = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] == 1) continue;
    heuristic += dis[i][a[i]];
  }
  return heuristic;
}

int lim, moves;
int IDA(vector<int>& a, int n, int pos, int d, int h, int prv) {
  if (!h) return moves = d;
  if (d + h > lim) return d + h;
  int ret = INT_MAX;
  for (auto& dx : adj_moves[pos % 4]) {
    int cx = pos + dx;
    if (cx < 1 || cx > n || cx == prv) continue;
    int new_h = h;
    new_h -= dis[cx][a[cx]];
    swap(a[pos], a[cx]);
    new_h += dis[pos][a[pos]];
    int cur = IDA(a, n, cx, d + 1, new_h, pos);
    if (moves) return moves;
    swap(a[pos], a[cx]);
    ret = min(ret, cur);
  }
  return ret;
}

// #define MultipleCase       
void Solve(int tc) {
  int n;
  while (cin >> n && n) {
    cout << "Set " << tc++ << ":\n";
    vector<int> a(n + 1);
    int pos;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      if (a[i] == 1) pos = i;
    }
    int init = CalculateHeuristic(a);
    if (!init) {
      cout << 0 << '\n';
      continue;
    }
    lim = init;
    moves = 0;
    while (!moves) lim = IDA(a, n, pos, 0, init, -1);
    cout << moves << '\n';
  }
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(12);
  PreCalc();
  int tt = 1;
#ifdef MultipleCase
  cin >> tt;
#endif
  for (int tc = 1; tc <= tt; ++tc) {
    Solve(tc);
  }
  return 0;
}