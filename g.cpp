#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ismo[128] = {0};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s, cur;
  vector<string> v;
  vector<int> idx;

  cin >> s;

  ismo['a'] = ismo['A'] = ismo['e'] = ismo['E'] = ismo['o'] = ismo['O'] = ismo['u'] = ismo['U'] = ismo['w'] = ismo['i'] = 1;
  ismo['g'] = ismo['n'] = ismo['d'] = ismo['r'] = ismo['m'] = ismo['b'] = ismo['s'] = ismo['x'] = ismo['j'] = ismo['c'] = 2;
  ismo['k'] = ismo['t'] = ismo['p'] = ismo['h'] = 2;
  
  if (ismo[s.front()] != 2) {
    cout << "-ERROR-";
    return 0;
  }

  for (int i = 1; i < s.length(); i++) {
    if (!ismo[s[i]]) {
      cout << "-ERROR-";
      return 0;
    }
    if (ismo[s[i]] == 1) {
      if (ismo[s[i-1]] == 1) {
        cout << "-ERROR-";
        return 0;
      }
      idx.push_back(i-1);
    }
  }
  for (int i = 0; i < idx.size(); i++) {
    if (i+1 == idx.size()) v.push_back(s.substr(idx[i]));
    else v.push_back(s.substr(idx[i], idx[i+1]-idx[i]));
  }
  string w;
  for (auto e: v) w.append(e);

  if (s == w) {
    cout << v.front();
    for (int i = 1; i < v.size(); i++) cout << "-" << v[i];
  } else cout << "-ERROR-";
}