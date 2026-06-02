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
//upper_bound(v.begin(), v.end(), 35); -> vector upper_bound
template<class T> using pqmax = priority_queue< T, vector<T>, greater<T> >;
template<class T> using pqmin = priority_queue<T>;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_set<int> o_set; o_set.insert(i); o_set.order_of_key(i); o_set.find_by_order(i); o_multiset.erase(o_multiset.find_by_order(o_multiset.order_of_key(i)))
const int mod = 1e9+7;
const int inf = 2147483647;
// !!!

ll n, up[200003][20], q, a, b, depth[200003], depdif;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> q;
  for (int i = 0; i < n-1; i++) {
  	cin >> up[i+2][0];
  	depth[i+2] = depth[up[i+2][0]]+1;
  }
  
  for (int i = 1; i <= 17; i++) {
  	for (int j = 2; j <= n; j++) {
  		up[j][i] = up[up[j][i-1]][i-1];
	}
  }
  
  for (int i = 0; i < q; i++) {
  	cin >> a >> b;
  	//cout << "Depths: " << depth[a] << " " << depth[b] << "\n";
  	
  	if (depth[b] > depth[a]) swap(a, b);
  	depdif = depth[a]-depth[b];
  	
  	for (int i = 0; (1<<i) <= depdif; i++) {
  		if ((depdif & (1<<i)) != 0) {
  			a = up[a][i];
		}
	  }
  	
  	if(a == b) {cout << a << "\n"; continue;}
  	
  	for (int i = 17; i >= 0; i--) {
  		if(up[a][i] != up[b][i]) {
  			a = up[a][i];
  			b = up[b][i];
		  }
	  }
	  
	cout << up[a][0] << "\n";
  }
  

  return 0;
}


