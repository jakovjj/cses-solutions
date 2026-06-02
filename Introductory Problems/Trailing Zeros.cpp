#include <bits/stdc++.h>

using namespace std;

long long n, d, r, t;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  d = 5; r = 0;
  while (n/d != 0) {
  	r+=n/d;
  	d*=5;
  }
  
  cout << r;
  
  return 0;
}


