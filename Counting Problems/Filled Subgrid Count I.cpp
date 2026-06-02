#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const ll inf = 1e18;

ll n, k, a[3003][3003], dp[3003][3003], res[30];
char c;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  REP(i, n) REP(j, n) {
  	cin >> c;
  	a[i][j] = c-'A'+1;
  }
  
  REP(i, n) REP(j, n) {
  	dp[i][j] = min({dp[i][j-1]*(a[i][j-1] == a[i][j]), dp[i-1][j]*(a[i-1][j] == a[i][j]), dp[i-1][j-1]*(a[i-1][j-1] == a[i][j])})+1;
  	res[a[i][j]] += dp[i][j];
	//if (a[i][j] == 2) cout << i << "," << j << " adds " << dp[i][j] << " to " << a[i][j] << "\n";
  }
  
  REP(i, k) cout << res[i] << "\n";

  return 0;
}

