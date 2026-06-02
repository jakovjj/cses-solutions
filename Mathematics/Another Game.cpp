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

int n, x, odd, even;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  testcases {
  	cin >> n;
  	odd = 0; even = 0;
  	
  	for (int i = 1; i <= n; i++) {
  		cin >> x; 
  		x%2 ? odd++ : even++;
	}
	
	(even == n) ? cout << "second\n" : cout << "first\n";
  }

  return 0;
}

