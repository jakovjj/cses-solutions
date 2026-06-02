#include <bits/stdc++.h>

using namespace std;

int t;
long long a, b;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> t;
  
  for (int i = 0; i < t; i++) { cin >> a >> b; 
  
	if (max(a, b)%2==0) {
		if (a > b) {cout << max(a,b)*max(a,b)-(b-1) << endl;}
		else {cout << max(a,b)*max(a,b)-(b-1)-(b-a) << endl;}
	}
	else {
		if (a > b) {cout << max(a,b)*max(a,b)-(a-1)-(a-b) << endl;}
		else {cout << max(a,b)*max(a,b)-(a-1) << endl;}
	}
  
  
  }
  
  return 0;
}


