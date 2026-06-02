#include <bits/stdc++.h>

using namespace std;

long long t;
long long a, b;

int max_take;

bool done;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> t;
  
  for (long long i = 0;i<t;i++) {
  	cin >> a >> b;
  	if (a==0 and b==0) {cout << "YES" << endl;}
  	else if ((a+b)%3==0 and a<=2*b and b<=2*a) {cout << "YES" << endl;}
  	else {cout << "NO" << endl;}
  }
  
  return 0;
}


