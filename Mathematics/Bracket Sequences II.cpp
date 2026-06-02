#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
 
const ll mod = 1e9+7;
 
ll n, f[1000003], inv[1000003], r, cnt;
string s;
ll exp(ll x, ll y) {ll res = 1; while(y) {if (y%2) res = res*x%mod; x=x*x%mod; y/=2;} return res;}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n;
  cin >> s;
  
  for (int i = 0; i < s.size(); i++) {
  	(s[i] == '(') ? cnt++ : cnt--;
	if (cnt < 0) {cout << "0"; return 0;}	
  }
  
  if (cnt > n-s.size() || n%2) {cout << "0"; return 0;}
  if (!cnt && n == s.size()) {cout << "1"; return 0;}
  
  f[1] = 1; for (int i = 2; i <= 1000001; i++) f[i] = (f[i-1]*i)%mod;
 
  inv[1000001] = exp(f[1000001], mod-2);
  for (int i = 1000001; i >= 1; i--) {inv[i-1] = inv[i] * i%mod;}

  n-=s.size(); cnt = (cnt+n)/2;
  cout << ( f[n]*inv[cnt]%mod*inv[n-cnt]%mod - f[n]*inv[cnt+1]%mod*inv[n-(cnt+1)]%mod +mod)%mod;
 	
  return 0;
}

