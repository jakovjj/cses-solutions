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

ll n, m, a[1003], b[1003], dp[1003], dpn[1003], res, resl, t;
vector<ll> ans;
vector<pll> l[1003];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  REP(i, n) cin >> a[i];
  REP(i, m) cin >> b[i];
  
  REP(i, m) {
  	ll mx = 0; ll p = 0;
  	
  	REP(j, n) {
  		dpn[j] = dp[j];
  		if (a[j] == b[i]) {
  			if (mx+1 > dp[j]) {
			  	dpn[j] = mx+1; l[j].push_back({p, i});
			  	if (dpn[j] > res) {res = dpn[j]; resl = j; t = i;}
			}
		}
		
		if (dp[j] > mx) {p = j; mx = dp[j];}
	}
	
	REP(j, n) dp[j] = dpn[j];
  }
  
  cout << res << "\n";
  while (resl) {
  	ans.push_back(a[resl]);
  	while (l[resl].back().second > t) l[resl].pop_back();
  	t = l[resl].back().second-1;
  	resl = l[resl].back().first;
  } reverse(ans.begin(), ans.end());
  for (auto i : ans) cout << i << " ";

  return 0;
}


