#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pll = pair<ll, ll>;
#define ordered_set tree<pll, null_type, less_equal<pll>, rb_tree_tag, tree_order_statistics_node_update>

void m_erase(ordered_set &os, pll val) {
  int idx = os.order_of_key(val);
  ordered_set::iterator it = os.find_by_order(idx);
  if (*it == val) os.erase(it);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ordered_set os;
  ll n, q, ans = 0;
  cin >> n >> q;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    os.insert({v[i], i});
  }
  vector<ll> w = v;
  sort(w.begin(), w.end(), greater<>());
  for (int i = 0; i < n; i++) if (w[i] >= i+1) ans = i+1;

  while (q--) {
    ll i, x;
    cin >> i >> x;
    i--;
    
    m_erase(os, {v[i], i});
    v[i] += x;
    os.insert({v[i], i});
    
    // for (auto [a, b]: os) cout << "(" << a << "," << b << ") ";
    // cout << "\n";
    auto cnt = n-os.order_of_key({ans+1, -1});
    // cout << cnt << " =>";
    if (cnt >= ans+1) ans++;
    cout << ans << " \n";
  }
  
}