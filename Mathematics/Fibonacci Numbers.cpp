#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const ll inf = 1e18;

ll n, f, res[2][2], mat[2][2], temp[2][2];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  res[1][1] = 1; res[2][2] = 1;
  mat[1][1] = 1; mat[1][2] = 1; mat[2][1] = 1;
  
  while (n > 0) {
  	if (n%2) {
  		temp[1][1] = res[1][1]; temp[1][2] = res[1][2];
		temp[2][1] = res[2][1]; temp[2][2] = res[2][2];
		
		res[1][1] = temp[1][1]*mat[1][1]+temp[1][2]*mat[2][1];
		res[1][2] = temp[1][1]*mat[1][2]+temp[1][2]*mat[2][2];
		res[2][1] = temp[2][1]*mat[1][1]+temp[2][2]*mat[2][1];
		res[2][2] = temp[2][1]*mat[1][2]+temp[2][2]*mat[2][2];
		
		res[1][1] %= mod; res[1][2] %= mod;
		res[2][1] %= mod; res[2][2] %= mod;
	}
  	
  	temp[1][1] = mat[1][1]; temp[1][2] = mat[1][2];
	temp[2][1] = mat[2][1]; temp[2][2] = mat[2][2];
	
	mat[1][1] = temp[1][1]*temp[1][1]+temp[1][2]*temp[2][1];
	mat[1][2] = temp[1][1]*temp[1][2]+temp[1][2]*temp[2][2];
	mat[2][1] = temp[2][1]*temp[1][1]+temp[2][2]*temp[2][1];
	mat[2][2] = temp[2][1]*temp[1][2]+temp[2][2]*temp[2][2];
	
	mat[1][1] %= mod; mat[1][2] %= mod;
	mat[2][1] %= mod; mat[2][2] %= mod;
  	
  	n/=2;
  }
  
  cout << res[1][2];

  return 0;
}


