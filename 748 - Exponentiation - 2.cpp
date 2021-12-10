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
  string b;
  int p;
  while (cin >> b >> p) {
    while (b.back() == '0') b.pop_back();
    int point = ((int)b.size() - b.find('.') - 1) * p;
    b.erase((b).begin() + b.find('.'));
    string s = BigPow(stoi(b), p);
    reverse(s.begin(), s.end());
    if (point >= (int)s.size()) {
      point -= (int)s.size();
      s = s + string(point, '0') + ".";
    } else {
      s.insert(point, ".");
    }
    reverse(s.begin(), s.end());
    cout << s << '\n';
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