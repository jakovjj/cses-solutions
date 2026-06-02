#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;

const ll mod = 1e9+7;

ll n, f[1000003], inv[1000003], a, b;
ll exp(ll x, ll y) {ll res = 1; while(y) {if (y%2) res = res*x%mod; x=x*x%mod; y/=2;} return res;}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  
  f[1] = 1; for (int i = 2; i <= 1000001; i++) f[i] = (f[i-1]*i)%mod;

  inv[1000001] = exp(f[1000001], mod-2);
  for (int i = 1000001; i >= 1; i--) {inv[i-1] = inv[i] * i%mod;}

  for (int i = 0; i < n; i++) {
  	cin >> a >> b;
  	
  	//  n!/(k!(n-k)!) %M = (n!%M)*(1/(k!(n-k)!)%M)%M
  	//  Looking for modular inverse of k!(n-k)! -> k!(n-k)! = k!(n-k)!^(M-2)%M
  	//  B)
  	
  	cout << f[a] * (inv[b]%mod*inv[a-b]%mod) % mod << "\n";
  }
 
  return 0;
}


