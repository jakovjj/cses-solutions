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

ll n, k, a[200003];
map<ll, ll> m;
set<pll> s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  REP(i, n) cin >> a[i];
  
  REP(i, k) {
  	if (m[a[i]]) s.erase({m[a[i]], -a[i]});
  	m[a[i]]++;
  	s.insert({m[a[i]], -a[i]});
  }
  cout << -(*s.rbegin()).second << " ";
  
  FOR(i, k+1, n) {
  	if (m[a[i]]) s.erase({m[a[i]], -a[i]});
  	m[a[i]]++;
  	s.insert({m[a[i]], -a[i]});

  	s.erase({m[a[i-k]], -a[i-k]});
  	m[a[i-k]]--;
  	
  	if (m[a[i-k]]) s.insert({m[a[i-k]], -a[i-k]});
  	cout << -(*s.rbegin()).second << " ";
  }

  return 0;
}


