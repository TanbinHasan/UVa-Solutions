/**
 *    author:  Tanbin_Hasan
 *    created: 10.12.2021 20:24:54
**/
#include <bits/stdc++.h>
 
using namespace std;

string BigPow(int n, int p) {
  int len = 0, carry = 0;
  vector<int> ar(1, 1);
  while (p--) {
    for (int i = 0; i <= len; ++i) {
      ar[i] = ar[i] * n + carry;
      carry = ar[i] / 10;
      ar[i] %= 10;
    }
    while (carry) {
      ar.push_back(carry % 10);
      carry /= 10, ++len;
    }
  }
  string s;
  for (int i = len; i >= 0; --i)
    s.push_back(ar[i] + '0');
  return s;
}

void Aufdecken(int TC) {
  int a, p;
  char ch;
  string b;
  while (cin >> a >> ch >> b >> p) {
    while (b.back() == '0') b.pop_back();
    int dig = (int)b.size();
    a *= (int) powl(10.0L, dig);
    if (b.empty()) b = "0";
    a += stoi(b);
    string s = BigPow(a, p), ans;
    reverse(s.begin(), s.end());
    int point = dig * p;
    for (int i = 0; i < (int)s.size(); ++i) {
      ans.push_back(s[i]);
      if (i + 1 == point) ans.push_back('.');
    }
    if (point >= (int)ans.size()) {
      point -= (int)ans.size();
      while (point--) {
        ans.push_back('0');
      }
      ans.push_back('.');
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int TT = 1, TC = 0;
  // cin >> TT; // Watch Carefully
  while (++TC <= TT) {
    Aufdecken(TC);
  }
  return 0;
}