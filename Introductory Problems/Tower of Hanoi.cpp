#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define mpair make_pair
#define MEMSET_MAX 0x7f
#define testcases \
  int t;        \
  cin >> t;       \
  while (t--)

// !!!

ll n, r;
vector<pll> res;

ll move(ll start, ll aux, ll goal, ll amo) {
	
	//cout << "need to move " << amo << " discs to " << goal << " with " << aux << "\n";
	
	if (amo != 1) {
		move(start, goal, aux, amo-1);
		
		r++;
		res.push_back(mpair(start, goal));
		//cout << start << " " << goal << "\n";	
		move(aux, start, goal, amo-1);
	}
	else {
		//cout << "ok so do it!\n";
		res.push_back(mpair(start, goal));
		//cout << start << " " << goal << "\n";
		r++;
	}
	
	return 0;
}


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  r = 0;
  move(1, 2, 3, n);
  
  cout << r << "\n";
  for (auto i : res) {
  	cout << i.first << " " << i.second << "\n";
  }
  
  return 0;
}

