#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = a; i <= (b); i++)

int n, x, v[1003];
string ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  FOR(i, 0, 9) {
  	x = (1<<i);
  	if (x > n) break;
  	
  	cout << "? ";
  	FOR(j, 0, n-1) cout << ((j/x)%2); 	
	cout << endl;
	
	cin >> ans;
	FOR(k, 0, n-1) if (ans[k] == '1') v[k] += x;	
  }
  
  cout << "! "; FOR(i, 0, n-1) cout << v[i]+1 << " "; cout << endl;
  return 0;
}


