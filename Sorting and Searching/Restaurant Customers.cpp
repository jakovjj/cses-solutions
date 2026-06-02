#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int n, a, b, t, m;
vector<pair<int, int>> c;
 
int main()
{
  cin >> n;
  for (int i = 0; i < n; i++) {
	  cin >> a >> b;
	  c.push_back( make_pair(a, 1) );
	  c.push_back( make_pair(b, -1) );
  }
  
  sort(c.begin(), c.end());
  
  for (int i = 0; i < n*2; i++) {
  	t += c.at(i).second;
  	m = max(m, t);
  }
  cout << m;
  
  return 0;
}



