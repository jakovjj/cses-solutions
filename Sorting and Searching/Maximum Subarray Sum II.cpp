#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define mpair make_pair
#define testcases \
  float t;        \
  cin >> t;       \
  while (t--)

// !!!

ll n, a, b, r;
ll prefixsum[200003];
set<pll> submax;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  r = -1e18;
  cin >> n >> a >> b;
  for (ll i = 1; i < n+1; i++) {cin >> prefixsum[i]; prefixsum[i] += prefixsum[i-1];}
  for (ll i = a; i <= b; i++) {submax.insert(mpair(prefixsum[i], i)); r = max(r, prefixsum[i]);}
  
  //for (int i = 0; i < n+1; i++) {cout << prefixsum[i] << " ";} cout << endl << endl; //debug
  //cout << "tempres is " << r << endl << endl;
  
  for (ll i = 2; i <= n-a+1; i++) {
  	if (i+b-1 <= n) submax.insert(mpair(prefixsum[i+b-1], i+b-1));
  	submax.erase(mpair(prefixsum[i+a-2], i+a-2));
  	
  	r = max(r, (*submax.rbegin()).first - prefixsum[i-1]);
  	
  	//cout << "for i = " << i << "(" << prefixsum[i] << ") adding " << prefixsum[i+b-1] << " and removing " << prefixsum[i+a-2] << endl;
  	//cout << "best possible result: " << (*submax.rbegin()).first << " - " << prefixsum[i-1] << endl;
  }
  
  cout << r;
  
  return 0;
}

//JJ

