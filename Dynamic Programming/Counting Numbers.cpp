#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll n, dp[20][10][2][2], res, resb;
string s;
 
ll solve(ll prev, ll i, bool lz, ll t) {	
	if (i == s.size()) return 1;
	if (prev != -1 && dp[i][prev][lz][t] != -1) return dp[i][prev][lz][t];
	
	ll hi = t ? (s[i]-'0') : 9;
	ll ans = 0;
	
	for (int j = 0; j <= hi; j++) {
		if (j == prev && j != 0) continue;
		if (j == prev && j == 0 && lz == 0) continue;
		ans+=solve(j, i+1, lz&j==0, t&(j==hi));
	}	
	
	dp[i][prev][lz][t] = ans;
	return dp[i][prev][lz][t];
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  memset(dp, -1, sizeof(dp));
  cin >> s; res = solve(-1, 0, 1, 1);
  	 
  bool b = 1; 
  for (int i = 1; i < s.size(); i++) if (s[i] == s[i-1]) b = 0;
  res-=b;
  
  memset(dp, -1, sizeof(dp));
  cin >> s; resb = solve(-1, 0, 1, 1);
  
  cout << resb-res;
  return 0;
}

