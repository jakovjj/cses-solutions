#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
const int inf = 1e9;
int n, h[200003], dp[200003], res, cnt, x, l, r, last;
set<pair<int, int>> s;
set<int> t, q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  REP(i, n) {
  	cin >> h[i];
  	s.insert({h[i], i});
  }
  
  t.insert(n+1); t.insert(0); last = (*s.rbegin()).first;
  while (!s.empty()) {
  	x = (*s.rbegin()).second;
  	s.erase(*s.rbegin());
  	
  	if (h[x] != last) {
  		while (!q.empty()) {
  			t.insert(*q.begin());
  			q.erase(*q.begin());
		}	
	}
  	
  	q.insert(x);
  	l = *t.upper_bound(x);
  	r = *--t.lower_bound(x);
  	
  	dp[x] = max(dp[l], dp[r])+1;
	res = max(res, dp[x]); last = h[x];
  }

  cout << res;
  return 0;
}


