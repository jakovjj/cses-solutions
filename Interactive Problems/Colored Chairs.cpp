#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
int n, lo, hi, mid, res;
bool v;

bool ask(int x) {
	cout << "? " << x << endl;
	char ans; cin >> ans;
	return (ans == 'R');
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  v = ask(1);
  
  res = n+1; lo = 2; hi = n;
  while (lo <= hi) {
  	mid = (lo+hi)/2;
	
	bool c = ask(mid);
	if (c == ((mid-1)%2)^v) {lo = mid+1;}
	else {res = mid-1; hi = mid-1;}
	  	
  }

  cout << "! " << res << endl;
  return 0;
}


