#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const ll inf = 1e18;
mt19937 rng(time(0));

ll n, res, sum, a[200003];
map<ll, ll> c;
ll exp(ll a, ll b) {
	ll r = 1;
	while (b) {if (b%2) r = (r*a)%mod; a = (a*a)%mod; b/=2;}
	return r;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  
  sum = 1;
  REP(i, n) {
  	cin >> a[i];
  	sum = (sum*exp(c[a[i]]+1, mod-2))%mod;
  	res = (res+sum)%mod;
  	
  	c[a[i]]++;
  	sum = (sum*(c[a[i]]+1))%mod;
  }
  
  cout << res;
  return 0;
}


