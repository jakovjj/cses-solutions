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
  
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;  
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_set<int> o_set; o_set.insert(i); o_set.order_of_key(i); o_set.find_by_order(i); o_multiset.erase(o_multiset.find_by_order(o_multiset.order_of_key(i)))
//ordered multiset must delete using iterators!
const int mod = 1e9+7;
const int inf = 2147483647;
// !!!

ll n, k, am, arr[200003];
ordered_multiset<int> o_mset;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> k;
  am = 0;
  while (am != k) {
  		cin >> arr[am];
  		o_mset.insert(arr[am]);
  		am++;
	}
 
  if (k%2==0) cout << *(o_mset.find_by_order(k/2-1)) << " ";
  else cout << *(o_mset.find_by_order(k/2)) << " ";
  for (int i = am; i < n; i++) {
	cin >> arr[i];
  	o_mset.insert(arr[i]);
	o_mset.erase(o_mset.find_by_order(o_mset.order_of_key(arr[i-k])));
	if (k%2==0) cout << *(o_mset.find_by_order(k/2-1)) << " ";
  	else cout << *(o_mset.find_by_order(k/2)) << " ";
	
  }
  
  return 0;
}

