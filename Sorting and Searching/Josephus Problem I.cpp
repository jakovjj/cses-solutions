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

int n, pt;
ordered_set<int> circle;
ordered_set<int> newcircle;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  
  for (int i = 1; i <= n; i++) {
  	circle.insert(i);
  }
  
  pt = 0;
  while (circle.size() != 1) {
  	while (pt < circle.size()) {
  		//cout << "player " << *(circle.find_by_order(pt)) << "'s turn, pt=" << pt << ", sz="<< circle.size()<<endl;
  		if (pt != circle.size()-1) cout << *(circle.find_by_order(pt+1)) << " ";
  		newcircle.insert(*(circle.find_by_order(pt)));
		pt+=2;
	}
	
	//cout << "pt is " << pt << endl;
	pt = pt-circle.size();
	
	circle.clear();
	for (int i = 0; i < newcircle.size(); i++) {
		circle.insert(*(newcircle.find_by_order(i)));
	}

	if (pt == 1) {
		cout << *(circle.find_by_order(pt-1)) << " ";
	}
	
	newcircle.clear();
  }
  if(pt == 0 && circle.size()==1) {
		cout << *(circle.find_by_order(pt)) << " ";
  }

  return 0;
}


