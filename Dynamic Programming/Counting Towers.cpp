#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t;
int n;
ll f, g, lf;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> t;
  int mod = 1000000007;

  for (int i = 0; i < t; i++) {
  	cin >> n;
  	lf = 1; g = 1; f = 1;
  	for (int j = 1; j < n; j++) {
  		f = (4*f + g)%mod;
  		g = (lf + 2*g)%mod;
  		lf = f;}
  	
  	cout << (f + g)%mod << endl;
   }
  
  return 0;
}

//JJ

