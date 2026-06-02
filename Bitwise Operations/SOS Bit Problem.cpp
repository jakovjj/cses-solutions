#include <bits/stdc++.h>
using namespace std;
int n, res[1<<21][4], a[200003], inv;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  // 1 -> x|y = x, 2 -> x&y = x, 3 -> x&y = 0
  
  cin >> n;
  for (int i = 1; i <= n; i++) {
  	cin >> a[i]; res[a[i]][0]++; res[a[i]][1]++;
  }
  
  for (int i = 0; i <= 20; i++) {
  	for (int mask = 0; mask < (1<<20); mask++) {  		
  		if (mask&(1<<i)) res[mask][0] += res[mask^(1<<i)][0];
  		else res[mask][1] += res[mask|(1<<i)][1];
	}
  }
  
  for (int i = 1; i <= n; i++) {
  	inv = (a[i]^((1<<20)-1));
  	cout << res[a[i]][0] << " " << res[a[i]][1] << " " << n-res[inv][0] << "\n";
  }

  return 0;
}


