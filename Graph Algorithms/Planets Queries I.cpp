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

ll lifting[200003][31], n, q, x, k;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
  	cin >> lifting[i][0];
  }
  
  for (int jump = 1; jump <= 30; jump++) {
  	for (int i = 1; i <= n; i++) {
  		lifting[i][jump] = lifting[lifting[i][jump-1]][jump-1];
	  }
  }
  
  for (int i = 0; i < q; i++) {
  	cin >> x >> k;
  	
  	while (k!=0) {
  		ll jumper = 1; ll pot = 0;
  		while (jumper < k) {jumper*=2; pot++;}
  		if (jumper > k) {pot--; jumper /= 2;}
  		
  		x = lifting[x][pot];
  		k-=jumper;
	  }
	  
	cout << x << "\n";
  }
  
  return 0;
}

