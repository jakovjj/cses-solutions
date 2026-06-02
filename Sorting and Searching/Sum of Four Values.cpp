#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9+7;
const int inf = 2147483647;

int n, k;
bool b;
int num[1003];
map<int, pii> v;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> k;
  for (int i = 1; i < n+1; i++) {cin >> num[i];}
  
  for (int i = 1; i < n+1; i++) {
  	
  	if (b == 1) {break;}
  	
  	if (i >= 3) {
  		int t = i-1;
  		for (int l = 1; l < t; l++) {v[num[t]+num[l]] = make_pair(t, l);}
	}
  	
  	for (int j = i+1; j < n+1; j++) {
  		if (v[k-(num[i]+num[j])].first != 0) {cout << i << " " << j << " " << v[k-(num[i]+num[j])].first << " " << v[k-(num[i]+num[j])].second; b = 1; break;}
  		
	  }
  }
  
  if (b == 0) {cout << "IMPOSSIBLE";}
  
  return 0;
}

//JJ

