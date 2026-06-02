#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define mpair make_pair
#define MEMSET_MAX 0x7f
#define testcases \
  int t;        \
  cin >> t;       \
  while (t--)

// !!!

ll n, k, d, p, r;
map<ll, ll> v;
ll arr[200003];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> k;
  p = 0;
  for (int i = 0; i < n; i++) {cin >> arr[i];
  	if (v[arr[i]] == 0) {d++;}
  	v[arr[i]]++;
  	//cout << i << " " << d << " distinct values" << endl;
  	while (d > k) {
  		v[arr[p]]--;
		if (v[arr[p]] == 0) {d--;}
		p++;
	}
	
  	r+=i-p+1;
  }
  
  cout << r;
  
  return 0;
}

