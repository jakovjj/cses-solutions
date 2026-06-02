#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int n, temp, h;
int c[103];
 
set<int> r, temp_r;
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  for (int i = 0; i < n; i++) {cin >> c[i];}
  
  r.insert(0);
  
  for (int i = 0; i < n; i++) {
    for (auto s : r) temp_r.insert(c[i]+s);
    for (auto k : temp_r) r.insert(k);
    temp_r.clear();
  }
  
  r.erase(0);
  cout << r.size() << endl;
  for (auto s:r) cout << s << " ";
  
  return 0;
}
