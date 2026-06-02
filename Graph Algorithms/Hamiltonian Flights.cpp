#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
// !!!

ll n, m, a, b, sumdp;
ll flights[21][21];
ll dp[1<<20][21];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> m;
  for (int i = 0; i < m; i++) {cin >> a >> b; flights[a][b] += 1;}
  
  dp[1][1] = 1;
  for (int i = 1; i < (1<<n); i++) {
      if ((i&(1<<n)) != 0 || (i&1) == 0) continue;
            
      for (int k = 1; k < n; k++) {
          if((i&(1<<k))!=0) continue;
          
        for (int l = 1; l <= n; l++) {
            if(dp[i][l] == 0 || flights[l][k+1] == 0) continue;
            
            //cout << "looking at path " << l << " with " << k << endl;
            dp[i|(1<<k)][k+1] += dp[i][l]*flights[l][k+1];
            dp[i|(1<<k)][k+1] = dp[i|(1<<k)][k+1]%1000000007;
        }
    }
  }
  
  cout << dp[(1<<n)-1][n];
  
  return 0;
}

