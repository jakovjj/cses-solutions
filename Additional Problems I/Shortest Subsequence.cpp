#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//o_set.order_of_key(i); o_set.find_by_order(i);
const int mod = 1e9+7; const int inf = 2147483647;

string s, res;
bool visited[4]; //1 -> A, 2 -> C, 3 -> G, 4 -> T

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> s;
  for (int i = 0; i < s.size(); i++) {
  	
  	if (s[i] == 'A') visited[1] = 1;
  	else if (s[i] == 'C') visited[2] = 1;
  	else if (s[i] == 'G') visited[3] = 1;
  	else if (s[i] == 'T') visited[4] = 1;
  	
  	if (visited[1] && visited[2] && visited[3] && visited[4]) {
  		res+=s[i];
  		visited[1] = 0; visited[2] = 0; visited[3] = 0; visited[4] = 0;
	  }
  	
  }
  
  if (visited[1] == 0) res+='A';
  else if (visited[2] == 0) res+='C';
  else if (visited[3] == 0) res+='G';
  else if (visited[4] == 0) res+='T';
  
  cout << res;

  return 0;
}


