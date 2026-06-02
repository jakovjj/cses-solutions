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


template<class T> using pqmax = priority_queue< T, vector<T>, greater<T> >;
template<class T> using pqmin = priority_queue<T>;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_set<int> o_set; o_set.insert(i); o_set.order_of_key(i); o_set.find_by_order(i); o_multiset.erase(o_multiset.find_by_order(o_multiset.order_of_key(i)))
const int mod = 1e9+7;
const int inf = 2147483647;
// !!!

ll n, pt, k, sz;
vector<ll> removals;
ordered_set<ll> circle;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  
  for (int i = 1; i <= n; i++) {circle.insert(i);}
  
  pt = 0;
  sz = circle.size();
  while (sz > 1) {
  	
  	//cout << endl; for (auto i : circle) {cout << i << " ";} cout << endl;
  	
  	while (pt+k < sz) {
  		pt+=k;
  		cout << *(circle.find_by_order(pt)) << " ";
  		removals.push_back(*(circle.find_by_order(pt)));
  		pt++;
	}
	
	pt+=k;
	if (pt >= sz) pt-= sz;
	
	for (auto i : removals) {circle.erase(i); sz--;}
	removals.clear();
	if (sz == 0) break;
	
	pt %= sz;
	cout << *(circle.find_by_order(pt)) <<" ";
	
	removals.push_back(*(circle.find_by_order(pt)));
	pt++;
  }
  
  if(pt == 0 && sz==1) {cout << *(circle.find_by_order(pt)) << " ";}

  return 0;
}


