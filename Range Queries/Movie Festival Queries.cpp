#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int inf = 2147483647;

int n, q, a, b, up[22][1000003], mov[1000003], res;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> q;
  
  for (int i = 1; i <= 1000001; i++) up[0][i] = inf; 
  for (int i = 1; i <= 1000000; i++) mov[i] = inf; 
  
  for (int i = 1; i <= n; i++) {cin >> a >> b; mov[a] = min(mov[a], b);}
  
  for (int i = 1000000; i >= 1; i--) up[0][i] = min(up[0][i+1], mov[i]);
  
  for (int k = 1; k <= 21; k++) {
  	for (int i = 1000000; i >= 1; i--) {  		
  		if (up[k-1][i] == inf) {up[k][i] = inf; continue;}
  		else up[k][i] = up[k-1][up[k-1][i]];
	  }
  }
  
  for (int i = 1; i <= q; i++) {	
  	res = 0;
  	
  	cin >> a >> b;
  	for (int k = 21; k >= 0; k--) {
  		if (up[k][a] <= b) {
  			res += (1<<k);
  			a = up[k][a];
		  }
	  }
  	
  	cout << res << "\n";
  }

  return 0;
}


