#include <bits/stdc++.h>

using namespace std;

long long n, r;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  cout << "0" << endl;
  for (long long t = 2; t < n+1; t++) {
  	r = 0;
  	
  	r+=((t*t*t*t)-(t*t))/2;
  		
  	r-= 24;
  	r-=20*(t-4);
  	r-=4*(t-4)*(t-4);
  	
  	cout << r << endl;
  }
  
  return 0;
}


