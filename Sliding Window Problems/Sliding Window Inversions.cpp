#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//o_set.order_of_key(i); *o_set.find_by_order(i);

ll n, k, a[200003], lo, hi, mid, res;
ordered_set<ll> s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  
  res = 0;
  REP(i, n) {
  	cin >> a[i];
  	
  	s.insert(a[i]);
  	
  	res += s.size()-s.order_of_key(a[i]+1);
	if (i > k) {
		res -= s.order_of_key(a[i-k]);
		s.erase(s.find_by_order(s.order_of_key(a[i-k])));
	}
	
	if (i >= k) cout << res << " ";
  }


  return 0;
}
