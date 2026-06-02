#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; ll inf = 1e18;

ll res[103][103], mat[103][103], temp[103][103], n, m, k, a, b, c;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m >> k;
  inf+=7;  
  for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) res[i][j] = inf;
  for (int i = 1; i <= n; i++) res[i][i] = 0;
  for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) mat[i][j] = inf;
  for (int i = 1; i <= m; i++) {cin >> a >> b >> c; mat[a][b] = min(mat[a][b], c);}
  
  while (k > 0) {
 	if (k%2) {
 		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) temp[i][j] = res[i][j];
 		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
			res[i][j] = inf;
			for (int l = 1; l <= n; l++) {
				if (temp[i][l] != inf && mat[l][j] != inf) res[i][j] = min(res[i][j], temp[i][l]+mat[l][j]);	
			}
		}
 		
	}
	
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) temp[i][j] = mat[i][j];
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		mat[i][j] = inf;
		for (int l = 1; l <= n; l++) {
			if (temp[i][l] != inf && temp[l][j] != inf) mat[i][j] = min(mat[i][j], temp[i][l]+temp[l][j]);	
		}
	}
  	
  	k/=2;
  }

  (res[1][n] == inf) ? cout << "-1" : cout << res[1][n];
  return 0;
}


