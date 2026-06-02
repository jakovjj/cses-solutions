#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
ll n, s_mx, s_mn, t_mx, t_mn, x, y, s, t;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  
  t_mn = LONG_MAX; s_mn = LONG_MAX; t_mx = -LONG_MAX; s_mx = -LONG_MAX;
  REP(i, n) {
  	cin >> x >> y;
  	s = x+y; t = x-y;
  	s_mx = max(s_mx, s);
  	s_mn = min(s_mn, s);
  	t_mx = max(t_mx, t);
  	t_mn = min(t_mn, t);
  	cout << max(t_mx-t_mn, s_mx-s_mn) << "\n";
  }

  return 0;
}


