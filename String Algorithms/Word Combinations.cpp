#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const int inf = 2147483647;

ll n, dp[100003];
string s, t;

struct trie {
	int x = 0;
	trie* a[26];
	
	trie() {
		x = 0;
		for (int i = 0; i < 26; i++) a[i] = nullptr;
	}
};
trie* root;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> s;
  
  dp[s.size()] = 1;
  root = new trie();
  
  cin >> n;
  for (int i = 1; i <= n; i++) {
  	cin >> t;
  	trie* temp = root;
  	for (int k = 0; k < t.size(); k++) {
  		if (temp->a[t[k]-'a'] == nullptr) temp->a[t[k]-'a'] = new trie();
  		temp = temp->a[t[k]-'a'];
  		
  		if (k == t.size()-1) temp->x++;
	  }
  }
  
  for (int i = s.size()-1; i >= 0; i--) {
  	trie* temp = root;
  	
  	for (int j = i; j < s.size(); j++) {
  		if (temp->a[s[j]-'a'] == nullptr) break;
		temp = temp->a[s[j]-'a'];
		
		dp[i] += temp->x*dp[j+1];
		dp[i] %= mod;	
	  }
  }
  
  cout << dp[0];

  return 0;
}


