#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, temp, t2;
multiset<int> ti;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> m;
  
  for (int i = 0; i < n; i++) {cin >> temp; ti.insert(temp);}
  for (int i = 0; i < m; i++) {
  	cin >> temp;
  	
  	auto it = ti.upper_bound(temp);
  	if (it == ti.begin()) {cout << "-1" << endl;}
  	else {cout << *(--it) << endl; ti.erase(it);}
  }
  
  return 0;
}

//JJ

