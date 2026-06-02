#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define mpr make_pair
#define mtp make_tuple
#define MEMSET_MAX 0x7f
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)

const ll mod = 1e9+7;
const ll p = 4294967296;
ll hashv[1000003], pot[1000003], lhash;
string s;

vector<int> res;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> s;
  
  hashv[0] = (int)s[0]; pot[0] = 1; for (int i = 1; i < (int)s.size(); i++) {
	hashv[i] = (hashv[i-1]*p%mod+s[i])%mod;
	pot[i] = pot[i-1]*p%mod;
  }
  
  for (int k = 1; k <= s.size(); k++) {
  	
  	bool w = 1;
  	//cout << "main hash is: " << hashv[k-1] << "\n"; 
  	
  	for (int idx = k; idx+k <= s.size(); idx+=k) {
  		//cout << "from " << idx << " to " << idx+k-1 << " hash : " <<(hashv[idx+k-1]-hashv[idx-1]*pot[k]%mod+mod)%mod << "\n";
  		if ((hashv[idx+k-1]-hashv[idx-1]*pot[k]%mod+mod)%mod != hashv[k-1]) {w = 0; break;}
	  }
	  
	//last interval
	ll d = s.size()%k;
	
	if (d) {
		lhash = (hashv[s.size()-1]-hashv[s.size()-1-d]*pot[d]%mod+mod)%mod;
		if (lhash != hashv[d-1]) w = 0;	
	}
	
	//cout << "last interval main hash is: " << hashv[d-1] << "\n";
	//cout << "last interval actual hash is " << lhash << "\n";
	  
	if (w) res.push_back(k);
  }
  
  for (auto i : res) cout << i << " ";

  return 0;
}


