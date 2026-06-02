#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, sum;
bool b;
int x[200003];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  for (int i = 0; i < n; i++) {cin >> x[i];}
  sort (x, x+n);
  b = false;
  
  sum = 0;
  for (int i = 0; i < n; i++) {
	if (x[i]-1 > sum) {cout << sum+1; b = true; break;}
	sum = x[i]+sum;
  }
  if (b == false) {cout << sum+1;}
  
  return 0;
}

//JJ

