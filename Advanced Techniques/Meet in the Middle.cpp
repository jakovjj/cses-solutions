#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

ll n, x, v[43], r, sum;
vector<ll> q;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> x;
  for (int i = 0; i < n; i++) {cin >> v[i];}
  
  if (n == 1) {
  	v[0] == x ? cout << 1 : cout << 0;
  	return 0;
  }
  
  for (ll i = 0; i < (1<<(n/2)); i++) {
  	sum = 0;
  	for (ll k = 0; k < (n/2); k++) {if ( ((1<<k)&i) != 0) {sum+=v[k];}}
	q.push_back(sum);
  }
  
  sort(q.begin(), q.end());
  
  for (ll i = 0; i < (1<< ((n/2)+n%2)); i++) {
  sum = 0;
  for (ll k = 0; k < (n/2)+n%2; k++) {
  	if ( ((1<<k)&i) != 0) {sum+=v[k+(n/2)];}}	
    
    auto loit = lower_bound(q.begin(), q.end(), x-sum);
    auto hiit = upper_bound(q.begin(), q.end(), x-sum);
    
    ll lo = loit - q.begin();
    ll hi = hiit - q.begin();
    r+= hi-lo;
	
  }
    
  cout << r;

  return 0;
}

