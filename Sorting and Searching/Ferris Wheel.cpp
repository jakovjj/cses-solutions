#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, w, r;
int lo, hi;
int x[200005];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> w;
  r=0;
  hi = n-1;
  lo = 0;
  for (int i = 0; i < n; i++) {cin >> x[i];}
  
  sort(x, x+n);
  
  while (lo <= hi) {
  	if (lo == hi) {lo++; r++;}
  	else {
  		if ((x[lo] + x[hi]) <= w) {lo++; hi--; r++;}
  		else {r++;hi--;}}}
  
  cout << r;
  
  return 0;
}

//JJ

