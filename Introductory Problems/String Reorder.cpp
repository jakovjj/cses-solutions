#include <bits/stdc++.h>
using namespace std;

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define MEMSET_MAX 0x7f
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int inf = 2147483647; const int mod = 1e9+7;

string s, res;
int c[30], l;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> s;
  for (int i = 0; i < s.size(); i++) c[s[i]-'A']++;
  l = -1; bool w = 1;
  
  for (int i = 0; i < s.size(); i++) {
		bool m = 0;
		for (int k = 0; k < 26; k++) {
			if (c[k]*2-1 > (int)(s.size())-i) {
				w = 0;
				m = 1;
				//cout << "died at " << i << " from " << k << " -> " << c[k] << " -> " << s.size()-i << " " << c[k]*2-1 << "\n";
				break;
			}
			if (c[k]*2-1 == (int)(s.size())-i) { 			
				c[k]--;
				l = k;
				res += (k+'A');
				m = 1;
				break;
			}
		}
		
		if (m) continue;
		for (int k = 0; k < 26; k++) {
			if (k == l || c[k] == 0) continue;
			c[k]--;
			l = k;
			res += (k+'A');
			break;
		}
  }
  
  w ? cout << res : cout << -1;
  return 0;
}
