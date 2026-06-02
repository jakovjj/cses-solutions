#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const int inf = 2147483647;

ll res, mn;
bool inc[26];
array<int, 26> w, req;
string s;

map<array<int, 26>, ll> m;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> s;
  m[w]++;
  
  for (int i = 0; i < s.size(); i++) inc[s[i]-'a'] = 1;
  
  for (int i = 0; i < s.size(); i++) {
  	w[s[i]-'a']++;
  	
  	mn = 1e9; for (int k = 0; k < 26; k++) if (inc[k]) mn = min(mn, (ll)w[k]);
  	for (int k = 0; k < 26; k++) if (inc[k]) req[k] = w[k]-mn;
  	
  	res += m[req];
  	m[req]++;
  }
  
  cout << res;

  return 0;
}


