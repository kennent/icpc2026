#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, lx1, rx1, ly1, ry1, lx2, rx2, ly2, ry2;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  int x1, y1, x2, y2, w1, h1, w2, h2;
  cin >> x1 >> y1 >> x2 >> y2;
  lx1 = rx1 = x1, ly1 = ry1 = y1;
  lx2 = rx2 = x2, ly2 = ry2 = y2;
  w1 = h1 = w2 = h2 = 0;
  while (--n) {
    cin >> x1 >> y1 >> x2 >> y2;
    // 1->1, 2->2
    int tw1 = max(x1, rx1)-min(x1, lx1), th1 = max(y1, ry1)-min(y1, ly1);
    int tw2 = max(x2, rx2)-min(x2, lx2), th2 = max(y2, ry2)-min(y2, ly2);
    int k1 = tw1-w1 + th1-h1 + tw2-w2 + th2-h2;

    int atw1 = max(x1, rx2)-min(x1, lx2), ath1 = max(y1, ry2)-min(y1, ly2);
    int atw2 = max(x2, rx1)-min(x2, lx1), ath2 = max(y2, ry1)-min(y2, ly1);
    int k2 = atw1-w2 + ath1-h2 + atw2-w1 + ath2-h1;

    if (k1 < k2) {
      rx1 = max(rx1, x1), lx1 = min(lx1, x1), ry1 = max(ry1, y1), ly1 = min(ly1, y1);
      rx2 = max(rx2, x2), lx2 = min(lx2, x2), ry2 = max(ry2, y2), ly1 = min(ly2, y2);
      w1 = rx1-lx1, h1 = ry1-ly1, w2 = rx2-lx2, h2 = ry2-ly2;
    } else {
      rx1 = max(rx1, x2), lx1 = min(lx1, x2), ry1 = max(ry1, y2), ly1 = min(ly1, y2);
      rx2 = max(rx2, x1), lx2 = min(lx2, x1), ry2 = max(ry2, y1), ly1 = min(ly2, y1);
      w1 = rx1-lx1, h1 = ry1-ly1, w2 = rx2-lx2, h2 = ry2-ly2;
    }
  }

  cout << max({w1, h1, w2, h2});
}