#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(ll i = 1; i <= (n); i++)

ll n, ansa, ansb, ta, tb;
long double lo, hi, mid, a[100003], b[100003], res, pref, mprefa, mprefb;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i];
  
  lo = 0; hi = 1e9; res = 0;
  while (lo <= hi) {
  	mid = (lo+hi)/2;
  	
  	ta = 1; tb = 1; mprefa = a[1]-mid; mprefb = b[1]-mid;
	pref = 0; REP(i, n) {pref += a[i]-mid; if (pref > mprefa) {mprefa = pref; ta = i;}}
  	pref = 0; REP(i, n) {pref += b[i]-mid; if (pref > mprefb) {mprefb = pref; tb = i;}}
  	
  	if (mprefa+mprefb > 0) {lo = mid+1e-7; ansa = ta; ansb = tb;}
	else hi = mid-1e-7;
  }
  
  cout << ansa << " " << ansb;

  return 0;
}


