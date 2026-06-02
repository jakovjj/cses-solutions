#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
long long a, b, c, x;
int res, p, n ,k;
stack<pair<int, int>> pref, suff;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n >> k;
  cin >> x >> a >> b >> c;
 
  REP(i, n) {
 	if (i > 1) x = (x*a+b)%c; 	
  	
	if (suff.empty()) suff.push({x, x});
	else suff.push({suff.top().first|x, x});
	
	if (i >= k) {
		if (pref.empty()) {
			while (!suff.empty()) {
				p = suff.top().second; suff.pop();
				if (pref.empty()) pref.push({p, p});
				else pref.push({pref.top().first|p, p});
			}
		}
		
		p = 0;
		if (!suff.empty()) p |= suff.top().first;
		if (!pref.empty()) p |= pref.top().first;
		res ^= p;
		
		pref.pop();
	}	
  }
  
  cout << res;
  return 0;
}
