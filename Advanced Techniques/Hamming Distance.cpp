#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define mpr make_pair
#define mtp make_tuple
#define MEMSET_MAX 0x7f
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//o_set.order_of_key(i); *o_set.find_by_order(i);
const int mod = 1e9+7; const int inf = 2147483647;

int n, k, arr[20003], res;
char c;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  res = inf;
  
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
  	for (int j = 0; j < k; j++) {
  		cin >> c;
  		if (c == '1') arr[i] += (1<<j);
	  }
  }
  
  for (int i = 1; i <= n; i++) {
  	for (int j = i+1; j <= n; j++) {
  		res = min(res, __builtin_popcount(arr[i]^arr[j]));
	  }
  }
  
  cout << res;

  return 0;
}


