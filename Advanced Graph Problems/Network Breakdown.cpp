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

ll n, m, a, b, dsu[100003], r, q;
stack<ll> s;
vector<pll> quers, roads;
map<pll, bool> br;
vector<ll> res;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {dsu[i] = i;} r = n;
  for (int i = 0; i < m; i++) {cin >> a >> b; roads.push_back(mpair(a, b));}
  for (int i = 0; i < q; i++) {cin >> a >> b; br[mpair(a, b)] = br[mpair(b, a)] = 1; quers.push_back(mpair(a, b));}
  
  for (auto i : roads) {
  	if(br[i] == 1) continue;
  	
  	a = i.first;
  	b = i.second;
  	if (a > b) swap(a, b);
  	
  	s.push(a);
  	while(dsu[a] != a) {a = dsu[a]; s.push(a);}
  	while(dsu[b] != b) {s.push(b);b = dsu[b];}
  	
  	if (a!=b) r--;
  	while (!s.empty()) {
  		dsu[s.top()] = b;
		s.pop();	
	}
  }
  
  //cout << "DEBUG:\n"; for (int i = 1; i <= n; i++) cout << dsu[i] << " "; cout << "\n\n";
  
  for (int i = quers.size()-1; i >= 0; i--) {
    res.push_back(r);				
	a = quers[i].first;
	b = quers[i].second;
	if (a > b) swap(a, b);
				
	s.push(a);
	while(dsu[a] != a) {a = dsu[a]; s.push(a);}
	while(dsu[b] != b) {s.push(b);b = dsu[b];}
	
	if (a!=b) r--;
	
	while (!s.empty()) {
		dsu[s.top()] = b;
		s.pop();	
	}
  }
  
  for (int i = res.size()-1; i >=0; i--) cout << res[i] << " ";

  return 0;
}


