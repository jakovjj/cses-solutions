#include <bits/stdc++.h>

using namespace std;


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  int n;
  cin >> n;
  
  int nl[n];
  
  if (n > 1 && n < 4) { 
  cout << "NO SOLUTION"; }
  
  else if (n == 4) {
  	cout << "2 4 1 3";
    }
    
  else {
  	for (int temp = n; temp > 1; temp = temp - 2) {
  		nl[temp] = temp;
  		cout << nl[temp] << " ";
    }
    
    if (n%2 == 1) cout << "1 ";
    
    for (int temp = n-1; temp > 1; temp = temp - 2) {
  		nl[temp] = temp;
  		cout << nl[temp] << " ";
    }
    
    if (n%2 == 0) cout << "1 ";
  
  }

  return 0;
}


