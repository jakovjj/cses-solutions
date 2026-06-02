#include <bits/stdc++.h>

using namespace std;

int n;
long long a[200007];
long long r_min, r_max;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  for (int i = 0; i < n; i++) {cin >> a[i];}
  for (int i = 1; i < n; i++) {a[i] += a[i-1];}
  
  r_max = a[0]; r_min=0;
  
  for (int i = 0; i < n; i++) {
  	r_max = max(r_max, a[i]-r_min);
  	//cout << "MAX IS NOW " << r_max << endl;
  	r_min = min(r_min, a[i]);
  	//cout << "MIN IS NOW " << r_min << endl;
  }
  
  cout << r_max;
  
  return 0;
}


