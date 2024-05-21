#include <bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>;
vector<tuple<int, int, char>> adj_moves = {{1, 0, 'D'}, {0, -1, 'L'}, {0, 1, 'R'}, {-1, 0, 'U'}};

int CalculateHeuristic(vvi& v) {
  int heuristic = 0, n = (int)v.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!v[i][j]) continue;
      heuristic += llabs(i - (v[i][j] - 1) / n);
      heuristic += llabs(j - (v[i][j] - 1) % n);
    }
  }
  return heuristic;
}

int Heu(vvi& v, int i, int j) {
  int heuristic = 0, n = (int)v.size();
  heuristic += llabs(i - (v[i][j] - 1) / n);
  heuristic += llabs(j - (v[i][j] - 1) % n);
  return heuristic;
}

string ans;

bool DFS(vvi& v, int x, int y, int lastx, int lasty, int d, int h, int lim) {
  if (!h) return true;
  if (h + d > lim) return false;
  for (auto& [dx, dy, ch] : adj_moves) {
    int cx = x + dx, cy = y + dy;
    if (cx < 0 || cy < 0 || cx >= 4 || cy >= 4 || (cx == lastx && cy == lasty)) continue;
    int nh = h - Heu(v, cx, cy);
    swap(v[cx][cy], v[x][y]);
    nh += Heu(v, x, y);
    ans.push_back(ch);
    if (DFS(v, cx, cy, x, y, d + 1, nh, lim)) return true;
    swap(v[cx][cy], v[x][y]);
    ans.pop_back();
  }
  return false;
}

// determine whether the puzzle is solvable
bool IsSolvable(vector<vector<int>> mat, int x, int y) {
  vector<int> v;
  for (auto i : mat) {
    for (auto j : i) if (j) v.push_back(j);
  }
  // count inversions and find blank tile row
  int n = (int)mat.size(), inv = 0;
  for (int i = 0; i < (int)v.size(); ++i) {
    for (int j = i + 1; j < (int)v.size(); ++j) {
      if (v[i] > v[j]) ++inv;
    }
  }
  int rest = n - x;
  if (!(rest % 2)) return inv % 2;
  return !(inv % 2);
}

void PreCalc(void) {}

#define MultipleCase       
void Solve(int tc) {
  ans.clear();
  vvi v(4, vector<int>(4));
  int rootx, rooty;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      cin >> v[i][j];
      if (!v[i][j]) rootx = i, rooty = j;
    }
  }
  if (!IsSolvable(v, rootx, rooty)) return void(cout << "This puzzle is not solvable.\n");
  int h = CalculateHeuristic(v);
  for (int i = h; i <= 45; ++i) {
    if (DFS(v, rootx, rooty, -1, -1, 0, h, i)) return void(cout << ans << '\n');
  }
  cout << "This puzzle is not solvable.\n";
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(12);
  PreCalc();
  int tt;
#ifdef MultipleCase
  cin >> tt;
#endif
  for (int tc = 1; tc <= tt; ++tc) {
    Solve(tc);
  }
  return 0;
}