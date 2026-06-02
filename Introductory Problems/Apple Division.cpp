#include <bits/stdc++.h>

using namespace std;

long long n, r;
long long g1, g2;
long long a[21];

void recursive(long long apple, long long g1, long long g2) { 
	if (apple < n+1) {recursive(apple+1, g1+a[apple], g2); recursive(apple+1, g1, g2+a[apple]);}
	else {
	//cout << abs(g2-g1) << endl;
	r = min(r, abs(g2-g1));
	return;
	}
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  r = 1000000007;
  
  cin >> n;
  for (int i = 0; i < n; i++) {cin >> a[i];}
  
  recursive(0, 0, 0);
  
  cout << r;
  
  return 0;
}


