#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const int inf = 2147483647;

int n, m, res, v;
stack<int> s;
char mat[1003][1003];
int h[1003][1003];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> mat[i][j];
	
  for (int i = 1; i <= n; i++) {
  	for (int j = 1; j <= m; j++) {
  		if (mat[i][j] == '.') h[i][j] = 1+h[i-1][j];
  		else h[i][j] = 0;
	}
  }
  
  /*
  for (int i = 1; i <= n; i++) {
  	for (int j = 1; j <= m; j++) {
  		cout << h[i][j] << " ";
	  } cout << "\n";
  }*/
  
  for (int i = n; i >= 1; i--) {
  	s.push(0);
  	
  	for (int j = 1; j <= m; j++) {
		  	
  		while (h[i][s.top()] > h[i][j]) {
  			v = h[i][s.top()];
  			s.pop();
  			res = max(res, v*(j-1-s.top()));
		  }
  		
  		s.push(j);
	}
	
	while (s.size() > 1) {
		v = h[i][s.top()];
		s.pop();
		res = max(res, v*(m-s.top()));
	}  
  	
  }
  
  
  cout << res;
 
  return 0;
}


