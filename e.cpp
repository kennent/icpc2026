#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
char c;

int f() {
  string s;
  cin >> s;
  
  ll g[1003][1003][2] = {0}; // br;
  for (int i = 0; i < s.length(); i++) {
    g[i][i+1][0] = s[i] == 'B';
    g[i][i+1][1] = s[i] == 'R';
  }

  for (int len = 2; len <= s.length(); len++) {
    for (int i = 0; i+len <= s.length(); i++) {
      int j = i+len; // [i, j)
      int b[5] = {0}, r[5] = {0}; // b
      if ((s[i+1] == 'B' || s[j-1] == 'B') && s[i] == 'B') b[g[i+1][j][0]] = 1;
      if ((s[i] == 'B' || s[j-2] == 'B') && s[j-1] == 'B') b[g[i][j-1][0]] = 1;
      if ((s[i+1] == 'R' || s[j-1] == 'R') && s[i] == 'B') b[g[i+1][j][1]] = 1;
      if ((s[i] == 'R' || s[j-2] == 'R') && s[j-1] == 'B') b[g[i][j-1][1]] = 1;

      if ((s[i+1] == 'B' || s[j-1] == 'B') && s[i] == 'R') r[g[i+1][j][0]] = 1;
      if ((s[i] == 'B' || s[j-2] == 'B') && s[j-1] == 'R') r[g[i][j-1][0]] = 1;
      if ((s[i+1] == 'R' || s[j-1] == 'R') && s[i] == 'R') r[g[i+1][j][1]] = 1;
      if ((s[i] == 'R' || s[j-2] == 'R') && s[j-1] == 'R') r[g[i][j-1][1]] = 1;

      for (int i = 0; i < 5; i++) {
        if (!b[i]) {
          g[i][j][0] = i;
          break;
        }
      }

      for (int i = 0; i < 5; i++) {
        if (!r[i]) {
          g[i][j][1] = i;
          break;
        }
      }
    }
  }

  return g[0][s.length()][c == 'R'];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> c;
  ll g = 0;
  for (int i = 0; i < n; i++) g ^= f();
  cout << g;
}