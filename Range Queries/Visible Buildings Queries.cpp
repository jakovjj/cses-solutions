#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = a; i <= (b); i++)

int n, q, h[100003], t, up[100003][19], a, b, res;
deque<pair<int, int>> d;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> q;
  REP(i, n) cin >> h[i];
  
  d.push_back({1e9+3, n+1});
  up[n+1][0] = n+1;
  for (int i = n; i >= 1; i--) {
  	while (d.back().first <= h[i]) d.pop_back();
  	up[i][0] = d.back().second; d.push_back({h[i], i});
  }
  
  REP(i, 18) REP(j, n+1) up[j][i] = up[up[j][i-1]][i-1];
  
  REP(i, q) {
  	cin >> a >> b; res = 1;
  	for (int i = 18; i >= 0; i--) {
  		if (up[a][i] <= b) {a = up[a][i]; res += (1<<i);}	
	}
	cout << res << "\n";
  }

  return 0;
}
