#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const ll inf = 1e18;
 
int n, c, r, palidx, mx, dp[2000003];
string t, s;
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> t;
  s = "#";
  for (int i = 0; i < t.size(); i++) {s += t[i]; s += '#';}
  
  palidx = 0; mx = 0; c = 0; r = 0;
  n = s.size();
  
  for (int i = 1; i < n; i++) {
  	dp[i] = 1;
  	if (i <= r) dp[i] = min(dp[2*c-i], r-i+1);
	if (i+dp[i] >= r) {c = i; r = i+dp[i]-1;}
	
	while (c+dp[c] < n && i-dp[i] >= 0 && s[i+dp[i]] == s[i-dp[i]]) {dp[i]++; r++;}
	
	if (dp[i]*2-2+(s[i] != '#') > mx) {palidx = i; mx = dp[i]*2-2+(s[i] != '#');}
  }
  
  for (int i = palidx-mx/2; i <= palidx+mx/2; i++) if (s[i] != '#') cout << s[i];
 
  return 0;
}

