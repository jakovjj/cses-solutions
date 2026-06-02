#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const ll inf = 1e18;

ll n, a[200003], l[200003];
set<ll> s;

vector<pll> ans;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  
  for (int i = 1; i <= n; i++) s.insert(i);
  for (int i = 1; i <= n-2; i++) {cin >> a[i]; l[a[i]] = i; s.erase(a[i]);}
  
  for (int i = 1; i <= n-2; i++) {
  	if (i > 1 && l[a[i-1]] < i) s.insert(a[i-1]);
  	ans.push_back({a[i], *s.begin()});
  	
  	s.erase(*s.begin());
  }
  
  ans.push_back({*s.begin(), a[n-2]});
  
  for (auto i : ans) cout << i.first << " " << i.second << "\n";

  return 0;
}


