#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const ll inf = 1e18;

ll n, m, mat[103][103], res[103][103], temp[103][103], k, a, b;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m >> k;
  
  for (int i = 1; i <= m; i++) {cin >> a >> b; mat[a][b]++;}
  for (int i = 1; i <= n; i++) res[i][i] = 1;

  while (k > 0){
  	if (k%2) {
  		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) temp[i][j] = res[i][j];
  		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
  			res[i][j] = 0;
  			for (int l = 1; l <= n; l++) res[i][j] = (res[i][j]+temp[i][l]*mat[l][j])%mod;
		}
	}
  	
  	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) temp[i][j] = mat[i][j];
  	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
  		mat[i][j] = 0;
  		for (int l = 1; l <= n; l++) mat[i][j] = (mat[i][j]+temp[i][l]*temp[l][j])%mod;
	}
  	
  	k/=2;
  }
  
  cout << res[1][n];
  return 0;
}


