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

int n, m;
char a[503][503], t;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  REP(i, n) REP(j, m) cin >> a[i][j];
  REP(i, n) REP(j, m) {
  	t = 'A';
  	if (a[i-1][j] == 'A' || a[i][j-1] == 'A' || a[i][j] == 'A') {t = 'B';
	if (a[i-1][j] == 'B' || a[i][j-1] == 'B' || a[i][j] == 'B') {t = 'C';
	if (a[i-1][j] == 'C' || a[i][j-1] == 'C' || a[i][j] == 'C') {t = 'D';
	}}}
	
	a[i][j] = t;
  }
  
  REP(i, n) {
  	REP(j, m) cout << a[i][j];
  	cout << "\n";
  }

  return 0;
}


