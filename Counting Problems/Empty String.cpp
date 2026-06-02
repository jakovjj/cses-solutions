#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define mpair make_pair
#define elif else if
#define MEMSET_MAX 0x7f
//(0x3f is larger than 1e9)
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
//getline(cin >> ws, s)

//s.upper_bound(2); -> set upper_bound
//upper_bound(v.begin(), v.end(), 35); -> std upper_bound
template<class T> using pqmax = priority_queue< T, vector<T>, greater<T> >;
template<class T> using pqmin = priority_queue<T>;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_set<int> o_set; o_set.insert(i); o_set.order_of_key(i); o_set.find_by_order(i); o_multiset.erase(o_multiset.find_by_order(o_multiset.order_of_key(i)))
const int mod = 1e9+7;
const int inf = 2147483647;
// !!!

ll n, dp[503][503], pascal[503][503];
string s;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> s;
  n = (ll)s.size();
  
  pascal[0][0] = 1;
  for (int i = 1; i <= 500; i++) {
  	for (int j = 0; j <= i; j++) {
  		pascal[i][j] = pascal[i-1][j];
  		if (j != 0) pascal[i][j] += pascal[i-1][j-1];
  		
  		if (pascal[i][j] > mod) pascal[i][j]-=mod;
	}
  }
  
  for (int k = 1; k<n; k++) {
  	for (int y = 1; y<=n-k; y++) {
  		ll x = y+k;
  		dp[y][x] = 0;
  		
  		if ((y-x+1)%2==1) continue;
  		
  		for (int z = y+1; z <= x; z++) {
  			if (s[z-1] == s[y-1]) {

				if((z-y+1)%2==1) continue;
				                            
  				ll bet = dp[y+1][z-1];
  				ll rem = dp[z+1][x];
  				
  				if (z == y+1) bet = 1;
  				if (z+1 > x) rem = 1;
  				
				dp[y][x] += (((bet*rem)%mod)*pascal[(x-y+1)/2][(z-y+1)/2])%mod;
				dp[y][x] %=mod;
			}	
		}
	}
  }
  
  //for (int i = 1; i <= n; i++) { for (int j = 1; j <= n; j++) { cout << dp[i][j] << " ";} cout << "\n";}
  cout << dp[1][n];

  return 0;
}


