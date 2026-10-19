#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m, k, ans = 1e18;
vector<ll> v;

bool f(ll h) {
  ll sum = 0;
  vector<ll> w(n);
  for (int i = 0; i < m; i++) {
    w[i] = max(0LL, v[i]-h);
    sum += w[i];
  }
  if (sum <= k) return true;
  for (int i = m; i < n; i++) {
    sum -= w[i-m];
    w[i] = max(0LL, v[i]-h);
    sum += w[i];
    if (sum <= k) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m >> k;
  v = vector<ll>(n);
  for (int i = 0; i < n; i++) cin >> v[i];

  ll l = 0, r = 1e9;
  while (l <= r) {
    ll x = (l+r)/2;
    if (f(x)) r = x-1;
    else l = x+1;
  }
  cout << l;
}