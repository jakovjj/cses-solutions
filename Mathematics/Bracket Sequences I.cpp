#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
 
const ll mod = 1e9+7;
 
ll n, f[1000003], inv[1000003], r;
ll exp(ll x, ll y) {ll res = 1; while(y) {if (y%2) res = res*x%mod; x=x*x%mod; y/=2;} return res;}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n;
  
  if (n%2==1) {
  	cout << "0";
  	return 0;
  }
  
  f[1] = 1; for (int i = 2; i <= 1000001; i++) f[i] = (f[i-1]*i)%mod;
 
  inv[1000001] = exp(f[1000001], mod-2);
  for (int i = 1000001; i >= 1; i--) {inv[i-1] = inv[i] * i%mod;}

  r = f[n] * (inv[n/2+1]%mod*inv[n/2]%mod) % mod;
  cout << r;
 	
  return 0;
}

