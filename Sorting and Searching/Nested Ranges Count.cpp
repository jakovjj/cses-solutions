#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define mpair make_pair
#define elif else if

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_set<int> o_set; o_set.insert(i); o_set.order_of_key(i); o_set.find_by_order(i); o_multiset.erase(o_multiset.find_by_order(o_multiset.order_of_key(i)))
const int mod = 1e9+7;
const int inf = 2147483647;
// !!!
 
ll n, a, b, contains[200003], contained[200003];
vector< pair<pll, ll> > arr;
ordered_multiset<ll> o_mset;
map<ll, ll> m;
 
bool customsort(pair<pll, ll> x, pair<pll, ll> y) {
	if (x.first.first > y.first.first) return 0;
	elif (y.first.first > x.first.first) return 1;
	else {
		if(x.first.second < y.first.second) return 0;
		else return 1;
	}
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n;
  
  for (int i = 0; i < n; i++) {
  	cin >> a >> b;
  	arr.push_back(mpair(mpair(a, b), i));
  }
  
  sort(arr.begin(), arr.end(), customsort);
  
  for (int i = 0; i < arr.size(); i++) {
  	o_mset.insert(arr[i].first.second);  	
  	contained[arr[i].second] = i-o_mset.order_of_key(arr[i].first.second);
  }
  o_mset.clear();
  for (int i = arr.size()-1; i >= 0; i--) {
  	o_mset.insert(arr[i].first.second);
  	contains[arr[i].second] = (o_mset.order_of_key(arr[i].first.second))+m[arr[i].first.second];
  	m[arr[i].first.second]++;
  }
  
  for (int i = 0; i < n; i++) cout << contains[i] << " ";
  cout << "\n";
  for (int i = 0; i < n; i++) cout << contained[i] << " ";
 
  return 0;
}
