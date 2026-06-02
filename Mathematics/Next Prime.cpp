#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 1; i <= (n); i++)
#define FOR(i, a, b) for (ll i = a; i <= (b); i++)
#pragma GCC optimize ("O3,unroll-loops")
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)

ll n, m, sieve[1200003];
bool w;
vector<ll> p;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  m = 1200000;
  for (ll i = 2; i <= m; i++) {
  	if (!sieve[i]) {
  		p.push_back(i);
  		for (ll j = i; j <= m; j += i) sieve[j] = i;
	}
  }
  
  testcases {
  	cin >> n;
  	
  	w = 0;
  	for (ll i = n+1; i <= n+5000; i++) {
  		w = 1;
  		for (auto j : p) {
  			if (j*j > i) break;
			if (i%j == 0) {w = 0; break;}	
		}
		if (w) {cout << i << "\n"; break;}	
	}
  	
  }

  return 0;
}


