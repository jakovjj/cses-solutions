#include <bits/stdc++.h>
using namespace std;

int main()
{  
  long long x = 0;
  cin >> x;
  
  cout << x;
  while (x != 1) {
  	cout << " ";
    if (x % 2 == 0) {
  		x = x/2;
  		cout << x;
	}
	else {
		x = (x*3)+1;
		cout << x;
	}
  }
  
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  return 0;
}

