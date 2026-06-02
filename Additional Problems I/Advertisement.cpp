#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//reference -> o_set.insert(x), *(o_set.find_by_order(i)), o_set.order_of_key(i), ordered_set<int> o_set

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mpair make_pair
#define elif else if
#define MEMSET_MAX 0x7f
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7;
const int inf = 2147483647;

ll n, v, arr[200003], res;
stack<ll> s;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  s.push(0);
  for (int i = 1; i <= n; i++) {
  	
  	cin >> arr[i];
  	
  	while (arr[s.top()] > arr[i]) {
  		v = arr[s.top()];
		s.pop();
  		res = max(v*(i-s.top()-1), res);
	  }
  	s.push(i);
  }
  
  while ((ll)s.size() > 1) {
  	v = arr[s.top()];
  	s.pop();
  	res = max(v*(n+1-s.top()-1), res);
  }

  cout << res;

  return 0;
}

//JJ

