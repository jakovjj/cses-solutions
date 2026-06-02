#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, r, x;
int p[200009];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  r = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {cin >> p[i];}
  
  sort(p, p+n);
  x = p[n/2];
  
  for (int i = 0; i < n; i++) {
  	if (p[i] >= x) {r+=p[i]-x;}
  	else {r+=x-p[i];}
  }
  cout << r;
  
  
  
  
  return 0;
}

//JJ

