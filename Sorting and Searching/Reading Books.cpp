#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll b[200005];
int lo, hi;
ll t1, t2, r;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  for (int i = 0; i < n; i++) {cin >> b[i];}
  sort(b, b+n);
  
  t1=0;t2=0;
  lo = 0; hi = n-1;
  while (lo < hi+1) {
  	t2 += b[hi]; hi--;
  	if (lo < hi+1) {
  	while (t1+b[lo] <= t2) {t1+=b[lo]; lo++;}}
  }
  
  //cout << t1 << " " << t2 << " " << lo << hi << endl; 
  r = max(t1+t2, b[n-1]*2);
  cout << r;
  
  return 0;
}

//JJ

