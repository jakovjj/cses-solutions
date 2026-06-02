#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const ll inf = 1e18;
mt19937 rng(time(0));

ll lo, hi, mid, res;
string ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  lo = 1; hi = 1e9;
  while (lo <= hi) {
  	mid = (lo+hi)/2;
  	cout << "? " << mid << endl;
  	cin >> ans;
  	
  	if (ans == "YES") {lo = mid+1;}
	else {res = mid; hi = mid-1;}
  }
  
  cout << "! " << res << endl;

  return 0;
}


