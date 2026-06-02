#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const ll inf = 1e18;

ll res, dp[27][27], cnt;
bool seen[27];
string s;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> s;
  for (int i = 0; i < s.size(); i++) {
  	cnt = 0;
  	if (!seen[s[i]-'a']) {cnt++; seen[s[i]-'a'] = 1;}
  	for (int k = 0; k < 26; k++) {cnt = (cnt+dp[k][s[i]-'a'])%mod; dp[k][s[i]-'a'] = 0;}
	res = (res+cnt)%mod;
	for (int k = 0; k < 26; k++) dp[s[i]-'a'][k] = (dp[s[i]-'a'][k]+cnt)%mod;
  }
 
  cout << res;

  return 0;
}


