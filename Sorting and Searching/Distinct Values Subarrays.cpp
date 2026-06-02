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

ll n, tot, x;
deque<ll> q;
map<ll, bool> vis;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  
  REP(i, n) {
  	cin >> x;
  	while (vis[x]) {
  		vis[q.front()] = 0;
  		q.pop_front();
	}
	q.push_back(x);
	vis[x] = 1;
	tot += q.size();
  }
  
  cout << tot;
  return 0;
}


