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

class Trie {
  class node {
   public:
    bool endmark;
    int cnt;
    vector<node*> next;
    node() {
      endmark = false;
      cnt = 0;
      next = vector<node*>(2, nullptr);
    }
  };
  node* head;
 public:
  Trie() { head = new node(); }
  void insert(string s) {
    node* cur = head;
    for (auto& i : s) {
      int ch = i - '0';
      if (cur->next[ch] == nullptr) cur->next[ch] = new node();
      cur = cur->next[ch];
      ++cur->cnt;
    }
    cur->endmark = true;
  }

  bool find(string s) {
    node* cur = head;
    for (auto& i : s) {
      int ch = i - '0';
      if (cur->next[ch] == nullptr) return false;
      cur = cur->next[ch];
    }
    return cur->endmark;
  }

  void erase(string s) {
    if (!find(s)) return;
    node* cur = head;
    for (auto& i : s) {
      int ch = i - '0';
      cur = cur->next[ch];
      --cur->cnt;
    }
    if (!cur->cnt) cur->endmark = false;
  }

  vector<int> frequency(string s) {
    node* cur = head;
    int n = (int)s.size();
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      int ch = s[i] - '0';
      if (cur->next[ch] == nullptr) break;
      cur = cur->next[ch];
      v[i] = cur->cnt;
    }
    return v;
  }
};

void PreCalc(void) {}

#define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  int n;
  cin >> n;
  vector<string> vs(n);
  Trie t;
  for (auto& i : vs) {
    cin >> i;
    t.insert(i);
  }
  int ans = 0;
  for (auto& i : vs) {
    auto v = t.frequency(i);
    for (int j = 0; j < (int)v.size(); ++j) {
      ans = max(ans, v[j] * (j + 1));
    }
  }
  cout << ans << '\n';
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  PreCalc();
  int tt = 1, tc = 0;
#ifdef MultipleCase
  cin >> tt;
#endif
  while (tt--) Solve(++tc);
  return 0;
}