#include <bits/stdc++.h>
using namespace std;

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
const ll mod = 1e9+7;

ll n, res, be, en, sum, c;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  
  c = 1;
  while (c <= n) {
  	
  	be = n/c;
  	en = n/be;
  	
  	res=(res+be*   ((((en-c+1)%mod) * ((c+en)%mod) %mod)*500000004LL%mod)  )%mod;
  	
  	c = en+1;
  }
  
  cout << res;

  return 0;
}


