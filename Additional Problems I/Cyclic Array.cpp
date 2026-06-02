#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<double, double> pdd;
#define mpair make_pair
#define mtuple make_tuple
#define elif else if
#define MEMSET_MAX 0x7f
//(0x3f is larger than 1e9)
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//o_set.order_of_key(i); o_set.find_by_order(i);
const int inf = 2147483647;
const int mod = 1e9+7;
// !!!

__int128 pref[400003], up[20][500003], ans, x, temp, idx;
ll n, k, lo, hi, mid, res, a[400003];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = n+1; i <= 2*n; i++) a[i] = a[i-n];
  
  for (int i = 1; i <= 2*n; i++) pref[i] = pref[i-1]+a[i];
  for (int i = 2*n; i <= 2*n+100000; i++) up[0][i] = 2*n;
  
  for (int i = 1; i <= 2*n; i++) {
  	lo = i; hi = 2*n;
  	res = i;
  	
  	while (lo <= hi) {
  		mid = (lo+hi)/2;
  		
  		if (pref[mid]-pref[i-1] > k) hi = mid-1;	
		else {
			res = max(res, mid);
			lo = mid+1;
		}
	}
	
	up[0][i] = res+1;
  }
  
  ans = n;

  for (int i = 1; i <= 19; i++) for (int j = 1; j <= 400000; j++) up[i][j] = up[i-1][up[i-1][j]];
  
  /*
  for (int i = 0; i <= 3; i++) {
  	for (int j = 1; j <= 16; j++) cout << (ll)up[i][j] << " ";
  	cout << "\n";
  }*/
  
  for (int i = 1; i <= n; i++) {
  	x = n+i; temp = 0; idx = i;
  	
  	for (int i = 19; i >= 0; i--) {
  		if (up[i][idx] < x) {idx = up[i][idx]; temp += (1<<i);}	
	}
  	
  	temp++;
  	ans = min(ans, temp);
  }
  
  cout << (ll)ans;
  return 0;
}

