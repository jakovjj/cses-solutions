#include <bits/stdc++.h>

using namespace std;

long long n;
long long result;
long long mod;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  mod = 1000000007;
  
  result = 1;
  
  cin >> n;
  for (int i = 0; i < n; i++) {
  	result = result*2;
  	if (result > mod) {result -= mod;}
  }  
  
  cout << result;
  
  return 0;
}


