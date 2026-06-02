#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, a, b, res;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;

  for (int i = 0; i < n; i++) {
  	cin >> a >> b;
  	res = 1;
  	
  	while (b > 0) {
  		if (b%2==1) {
  			res = (a*(res%1000000007))%1000000007;
		}	
		a = (a*a)%1000000007;
		b = b/2;
	}
	
	cout << res << endl;
  }
  
  return 0;
}

//JJ

