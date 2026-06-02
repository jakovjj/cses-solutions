#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
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
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//o_set.order_of_key(i); o_set.find_by_order(i); o_multiset.erase(o_multiset.find_by_order(o_multiset.order_of_key(i)))
const int mod = 1e9+7; const int inf = 2147483647;
// !!!

ll a, b, c;

ll exp(ll x, ll y, ll m) {
	ll res = 1;
	while (y > 0) {
		if (y%2) res = res*x%m;
		x*=x;
		x%=m;
		y/=2;
	}
	
	return res%m;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  testcases {
	  cin >> a >> b >> c;
	  cout << exp(a, exp(b, c, mod-1), mod) << "\n";
  }

  return 0;
}


