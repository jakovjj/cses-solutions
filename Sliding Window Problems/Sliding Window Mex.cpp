#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//o_set.order_of_key(i); *o_set.find_by_order(i);

int n, k, a[200003], cnt[200003], lo, hi, mid, res;
ordered_set<int> s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  REP(i, n) {
  	cin >> a[i];
  	
  	if (a[i] <= n) {
  		if (!cnt[a[i]]) s.insert(a[i]);
		cnt[a[i]]++; 
	}
	if (i > k && a[i-k] <= n) {
		if (cnt[a[i-k]] == 1) {
			auto it = s.find_by_order(s.order_of_key(a[i-k]));
			s.erase(it);
		}
		cnt[a[i-k]]--;
	}
	
	if (i >= k) {
			
		lo = 1; hi = s.size(); res = 0;
		while (lo <= hi) {
			mid = (lo+hi)/2;
			if (*s.find_by_order(mid-1) == mid-1) {res = mid; lo = mid+1;}
			else hi = mid-1;
				
		}
		
		cout << res << " ";
	}
  }


  return 0;
}
