#include <bits/stdc++.h>

using namespace std;

int n, a, b, r, ft;
vector<pair<int, int>> m;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  
  for (int i = 0; i < n; i++) {
  	cin >> a >> b;
  	m.push_back(make_pair(b, a));
  }
  
  sort(m.begin(), m.end());
  
  ft = -1;
  r = 0;
  for (int i = 0; i < m.size(); i++) {
  	if (m.at(i).second >= ft) {r+=1; ft = m.at(i).first;}
  }
  
  cout << r;
  
  return 0;
}


