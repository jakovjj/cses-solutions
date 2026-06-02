#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll; const ll inf = 1e18;
ll n, q, l, r, a[200003], pref[200003], up[200003][20], sumup[200003][20], x, res;
stack<pll> s;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) pref[i] = pref[i-1]+a[i];
  s.push({inf, n+1}); up[n+1][0] = n+1;
  
  for (int i = n; i >= 1; i--) {
  	while (s.top().first < a[i]) s.pop();
  	up[i][0] = s.top().second;
  	sumup[i][0] = a[i]*((up[i][0]-1)-(i+1)+1)-(pref[up[i][0]-1]-pref[i]);
  	s.push({a[i], i});
  }
  
  for (int k = 1; k <= 19; k++) for (int i = 1; i <= n+1; i++) {
  	up[i][k] = up[up[i][k-1]][k-1]; 
	sumup[i][k] = sumup[i][k-1]+sumup[up[i][k-1]][k-1];
  }
  
  for (int i = 1; i <= q; i++) {
  	cin >> l >> r;
  	res = 0;
  	for (int k = 19; k >= 0; k--) {
  		if (up[l][k] <= r) {res += sumup[l][k]; l = up[l][k];}	
	}
	res += a[l]*(r-(l+1)+1)-(pref[r]-pref[l]);
  	
  	cout << res << "\n";
  }  
  return 0;
}
