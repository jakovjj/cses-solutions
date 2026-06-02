#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<double, double> pdd;

 
const int inf = 2147483647;
const int mod = 1e9+7;
 
ll k;
long double res, cnt;
long double mat[9][9], temp[9][9], ans[9][9]; 
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> k;
  
  for (int i = 1; i <= 8; i++) for (int j = 1; j <= 8; j++) ans[i][j] = 1;
  for (int ri = 1; ri <= 8; ri++) for (int rj = 1; rj <= 8; rj++) {  	
  	  for (int i = 1; i <= 8; i++) for (int j = 1; j <= 8; j++) mat[i][j] = 0;
  	  mat[ri][rj] = 1;
  	  
	  for (int t = 1; t <= k; t++) {
	  	for (int i = 1; i <= 8; i++) for (int j = 1; j <= 8; j++) {
	  		cnt = 4; if (i == 1 || i == 8) cnt--; if (j == 1 || j == 8) cnt--;
	  		if (i+1 < 9) temp[i+1][j] += mat[i][j]/cnt;
	  		if (i-1 > 0) temp[i-1][j] += mat[i][j]/cnt;
	  		if (j+1 < 9) temp[i][j+1] += mat[i][j]/cnt;
	  		if (j-1 > 0) temp[i][j-1] += mat[i][j]/cnt;
		}
		for (int i = 1; i <= 8; i++) for (int j = 1; j <= 8; j++) {mat[i][j] = temp[i][j]; temp[i][j] = 0;}
	  }
	  
	  for (int i = 1; i <= 8; i++) for (int j = 1; j <= 8; j++) ans[i][j] *= (1-mat[i][j]);
  }
  
  for (int i = 1; i <= 8; i++) for (int j = 1; j <= 8; j++) res += ans[i][j];
  cout << setprecision(6) << fixed << res;
 
  return 0;
}

