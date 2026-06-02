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

ll n, a[103][103], mex;
set<ll> s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  REP(i, n) REP(j, n) {
  	mex = 0; s.clear();
  	for (int k = 1; k < i; k++) s.insert(a[k][j]);
  	for (int k = 1; k < j; k++) s.insert(a[i][k]);
  	
  	for (auto i : s) {
  		if (i == mex) mex++;
		else break;	
	}
  	a[i][j] = mex;
  }
  
  REP(i, n) {
  	REP(j, n) cout << a[i][j] << " ";
  	cout << "\n";
  }

  return 0;
}


