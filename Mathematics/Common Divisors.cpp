#include <bits/stdc++.h>
using namespace std;

int n, a, r, divs[1000003], res;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
  	cin >> a;
  	for (int k = 1; k <= 1000; k++) {
      if (k*k > a) break;
	  if (a%k==0) {
	  	divs[k]++;
		if (a/k!=k) divs[a/k]++;
		
		if (divs[k] > 1) res = max(res, k);
		if (divs[a/k] > 1) res = max(res, a/k);
		
		}
	}
  }
  
  cout << res;

  return 0;
}


