#include <bits/stdc++.h>

#define int long long
#define ll __int128_t

using namespace std;

template <int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
  static_assert(D >= 1);
  template <typename... Args>
  Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};
template <typename T>
struct Vec<1, T> : public vector<T> {
  Vec(int n = 0, const T& val = T()) : vector<T>(n, val) {}
};

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void PreCalc(void) {}

void Solve(int tc, int n) {
  vector<string> vs(n);
  for (auto& i : vs) {
    cin >> i;
  }
  vector<pair<int, int>> adjm = {{-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 1}};
  auto f = [&](void) {
    Vec<2, bool> vis(n + 1, n + 1);
    queue<pair<int, int>> q;
    for(int i = 0; i < n; ++i) {
      int x = 0, y = i;
      if (vs[x][y] == 'w') continue;
      vis[x][y] = true;
      q.push({x, y});
    }
    while (!q.empty()) {
      auto[nx, ny] = q.front();
      q.pop();
      for (auto& [dx, dy] : adjm) {
        int cx = nx + dx, cy = ny + dy;
        if (cx < 0 || cy < 0 || cx >= n || cy >= n) continue;
        if (vis[cx][cy] || vs[cx][cy] != 'b') continue;
        vis[cx][cy] = true;
        if (cx == n - 1) return true;
        q.push({cx, cy});
      }
    }
    return false;
  };
  if (f()) {
    cout << tc++ << " " << "B\n";
  } else {
    cout << tc++ << " " << "W\n";
  }
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  PreCalc();
  int cnt = 0, n;
  while (cin >> n && n) Solve(++cnt, n);
  return 0;
}