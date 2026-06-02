#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
const ll mod = 1e9+7; const ll inf = 1e18;
 
ll n, k, dp[3003][30], dpn[3003][30], a[3003][3003], s, res;
char c;
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n >> k;
  for (int j = 0; j <= n; j++) for (int l = 0; l <= k; l++) {dp[j][l] = (1ll<<60); dpn[j][l] = (1ll<<60);}

  REP(i, n) {
	REP(j, n) {
		cin >> c;
		a[i][j] = c-'A'+1;
		
		s = 1;
		REP(l, k) {
			dpn[j][l] = min({dp[j][l], dpn[j-1][l], dp[j-1][l]})+1;	
			if (a[i][j] == l) dpn[j][l] = 1;
			s = max(s, dpn[j][l]);
		}
		res += max(0ll, min(i, j)-s+1);
	}
	
	REP(j, n) REP(l, k) {
		dp[j][l] = dpn[j][l];
		dpn[j][l] = (1ll<<59);
	}
  }
  
  cout << res;
  return 0;
}
