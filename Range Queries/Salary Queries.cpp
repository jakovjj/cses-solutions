#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
int n, q, a, b, cnt, upd, w[200003];
char c;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
ordered_multiset<int> v;
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {cin >> w[i]; v.insert(w[i]);}
  for (int i = 1; i <= q; i++) {
  	cin >> c >> a >> b;
  	if (c == '!') {
  		v.erase(v.find_by_order(v.order_of_key(w[a])));
		w[a] = b; v.insert(w[a]);
	}
	else cout << v.order_of_key(b+1)-v.order_of_key(a) << "\n";
  }
 
  return 0;
}

