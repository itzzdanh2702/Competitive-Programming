#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

bool isnum(char x) { return (x >= 'a' && x <= 'z'); }

string change(string s, int k) {
  if (k > 0) return '(' + s + ')';
  return s;
}

int get(char op) {
  if (op == '/') return 4;
  if (op == '*') return 3;
  if (op == '-') return 2;
  if (op == '+') return 1;
  return 0;
}
string s;

vector<pair<string, int> > num;

int main() {
   freopen("posttoin.INP","r",stdin);
    freopen("posttoin.OUT","w",stdout);
  cin >> s;
  for (int i = 0; i < s.size(); ++i) {
    string temp;
    temp += s[i];
    if (isnum(s[i]))
      num.push_back(make_pair(temp, 0));
    else if (get(s[i]) > 0) {
      pair<string, int> b = num[num.size() - 1];
      num.pop_back();
      pair<string, int> a = num[num.size() - 1];
      num.pop_back();
      string ans;
      if (get(s[i]) == 1) ans = a.fi + temp + b.fi;
      if (get(s[i]) == 2)
        ans = change(a.fi, 0) + temp + change(b.fi, (1 <= b.se && b.se <= 2));
      if (get(s[i]) == 3)
        ans = change(a.fi, (1 <= a.se && a.se <= 2)) + temp +
              change(b.fi, b.se * (b.se != 3));
      if (get(s[i]) == 4)
        ans = change(a.fi, (1 <= a.se && a.se <= 2)) + temp + change(b.fi, b.se);
      num.push_back(make_pair(ans, get(s[i])));
    }
  }
  cout << num[num.size() - 1].fi;
  return 0;
}
