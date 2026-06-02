#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define mpair make_pair
#define MEMSET_MAX 0x7f
#define testcases \
  int t;        \
  cin >> t;       \
  while (t--)
 
// !!!
 
string s, p;
ll r, idx;
ll lps[1000003];
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> s;
  cin >> p;
  
  if ((int)p.size() > (int)s.size()) {cout << 0; return 0;}
  if (s == p) {cout << 1; return 0;}
  
  r = 0; idx = 0;
  for (int i = 1; i < (int)p.size(); i++) {
  	while (p[idx] != p[i] && idx > 0) {idx = lps[idx-1];}
	if (p[idx] == p[i]) idx++;
	lps[i] = idx;
  }
  
  //for (int i = 0; i < (int)p.size(); i++) {cout << lps[i] << " ";}
  
  idx = 0;
  for (int i = 0; i < (int)s.size(); i++) {
  	while (p[idx] != s[i] && idx > 0) {idx = lps[idx-1];}
  	
  	if (p[idx] == s[i]) {
  		idx++;
  		//cout << idx-1 << " and " << i << "\n";
  		if (idx == (int)p.size()) {
  			idx = lps[idx-1];
  			r++;
		  }
	  }
  }
  
  cout << r;
  
  return 0;
}

