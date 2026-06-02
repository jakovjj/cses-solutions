#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
ll n, m, k;
ll t;
vector<int> ppl;
vector<int> aps;
int l, res;
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> m >> k;
  
  for (int i = 0; i < n; i++) {cin >> t; ppl.push_back(t);}
  for (int i = 0; i < m; i++) {cin >> t; aps.push_back(t);}
  
  sort(ppl.begin(), ppl.end()); 
  sort(aps.begin(), aps.end());
  
  for (int i = 0; i < m; i++) {
  	
  	if (aps[i] <= ppl[l]+k && aps[i] >= ppl[l]-k) {l++; res++;}
  	else if (aps.at(i) > ppl.at(l)+k) {l++; i--;}
  	
  	if (l >= n) {break;}
  }
  
  cout << res;
  
  return 0;
}

