#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const ll inf = 1e18;

ll t, n, k, a[21], f[23];
set<ll> s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  f[0] = 1; REP(i, 20) f[i] = f[i-1]*i;

  testcases {
  	cin >> t;
  	if (t == 1) {
  		cin >> n >> k; k--;
		REP(i, n) s.insert(i);
		REP(i, n) {
			auto it = s.begin();
			while (k >= f[n-i]) {it++; k -= f[n-i];}
			cout << *it << " "; s.erase(*it);
		}
	}
	if (t == 2) {
		cin >> n; k = 1;
		REP(i, n) {
			cin >> a[i];
			s.insert(i);
		}
		
		REP(i, n) {
			auto it = s.begin();
			while (*it != a[i]) {
				it++; k += f[n-i];
			}
			s.erase(*it);
		}
		
		cout << k;
	}
  	cout << "\n";
  }

  return 0;
}

