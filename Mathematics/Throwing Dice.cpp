#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const ll inf = 1e18;

ll n, res[7], mat[7][7], temp[7][7];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  n--;
  
  mat[1][6] = 1;
  mat[2][1] = 1; mat[2][6] = 1;
  mat[3][2] = 1; mat[3][6] = 1;
  mat[4][3] = 1; mat[4][6] = 1;
  mat[5][4] = 1; mat[5][6] = 1;
  mat[6][5] = 1; mat[6][6] = 1;
  
  res[1] = 1; res[2] = 2; res[3] = 4; res[4] = 8; res[5] = 16; res[6] = 32;
  
  while (n) {
  	if (n%2) {
  		for (int i = 1; i <= 6; i++) {temp[i][0] = res[i]; res[i] = 0;} 
  		for (int i = 1; i <= 6; i++) for (int j = 1; j <= 6; j++) res[i] = (res[i]+temp[j][0]*mat[j][i])%mod;
	}
  	n/=2;
  	
  	for (int i = 1; i <= 6; i++) for (int j = 1; j <= 6; j++) {temp[i][j] = mat[i][j]; mat[i][j] = 0;}
  	
  	for (int i = 1; i <= 6; i++) for (int j = 1; j <= 6; j++) {
  		for (int k = 1; k <= 6; k++) mat[i][j] = (mat[i][j]+temp[i][k]*temp[k][j])%mod;
	}
  	
  }
  
  cout << res[1];

  return 0;
}


