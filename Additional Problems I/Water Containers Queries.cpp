#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)

int a, b, s;
int gcd(int x, int y) {
	if (!x) return y;
	return gcd(y%x, x);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  testcases {
  	cin >> a >> b >> s;
  	if (s%gcd(a,b) == 0 && a >= s) cout << "YES\n";
  	else cout << "NO\n";
  }

  return 0;
}
