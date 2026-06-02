#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int n, t, tr, r, lo, x[200005];
map<int, int> m;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  
  for (int i = 1; i <= n; i++) {
  	cin >> x[i];
  	
  	(m[x[i]] < lo) ? tr++ : lo = m[x[i]];
	m[x[i]] = i;
	
	tr = i-lo;
	r = max(r, tr);
  }
  cout << r;
  
  return 0;
}
 

