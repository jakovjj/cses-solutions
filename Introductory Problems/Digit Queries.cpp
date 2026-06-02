#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define mpair make_pair
#define MEMSET_MAX 0x7f
#define testcases \
  int t;        \
  cin >> t;       \
  while (t--)
 
// !!!
 
ll q, k, a, b, lo, hi, mid, r, dig, d, prevdig;
string s;
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> q;
  
  while (q--) {
  	cin >> k;
  	
	b = 1;
	a = 0;
	prevdig = 0;
	dig = 0;
	while (k > dig) {
		prevdig = dig;
		dig+=b*9*(a+1);
		b*=10;
		a++;
	}
	
	//cout << fixed << "looking at number with " << a << " digits, string locations range between " << prevdig << " and " << dig << "\n";
	
	d = pow(10,a-1);
	
	r = 0;
  	lo = pow(10,a-1); hi = pow(10,a)-1;
  	while (lo <= hi) {
  		mid = (hi+lo)/2;
  		//cout << fixed << "\nlooking at mid " << mid << " that starts on "	<< (prevdig+1+(mid-d)*a) << "\n";
  		
  		if ( (prevdig+(mid-d)*a+1) > k) {hi = mid-1;}
  		else {
  			r = max(r, mid);
  			lo = mid+1;
		  }
	  }
	  
    //cout << fixed << "answer is in number " << r << " that starts on " << (prevdig+(r-d)*a+1) << "\n";
	
	s = to_string(r);
	cout << s[k-(prevdig+(r-d)*a+1)] << "\n";
  }
  
  return 0;
}

