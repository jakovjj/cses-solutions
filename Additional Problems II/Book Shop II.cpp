#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;

ll n, x, p, dp[100008], sum, h[103], s[103], c[103], res;
vector<pll> book;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> x;
  
  for (int i = 1; i <= n; i++) cin >> h[i];
  for (int i = 1; i <= n; i++) cin >> s[i];
  for (int i = 1; i <= n; i++) cin >> c[i];
  
  book.push_back({0LL, 0LL});
  for (ll i = 1; i <= n; i++) {
	p = 1; sum = 0;
	while (p*2 <= c[i]) {
		book.push_back({p*h[i], p*s[i]});
		sum += p;
		p*=2;	
	}
	p = c[i]-sum;
	if (p > 0) book.push_back({p*h[i], p*s[i]});
  }
  
  for (ll i = 1; i < (ll)book.size(); i++) {
  	for (ll k = x; k >= 1; k--) {
  		if (k >= book[i].first) dp[k] = max(dp[k], dp[k-book[i].first]+book[i].second);
  		res = max(res, dp[k]);
	}
  }
  
  cout << res;
  
  return 0;
}


