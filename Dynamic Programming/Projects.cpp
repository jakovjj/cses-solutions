#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

ll n;
ll a, b, c;
tuple<ll, ll, ll> p[200003];
pll dp[200003];

ll hi, lo, mid;

bool endtimesort(tuple<ll, ll, ll> i, tuple<ll, ll, ll> j) {
	return (get<1>(i) < get<1>(j));
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  for (int i = 1; i < n+1; i++) {
  	cin >> a >> b >> c;
  	p[i] = make_tuple(a, b, c);
  }
  
  sort(p, p+n+1, endtimesort);
  
  //cout << endl << "SORTED: " << endl; for (int i = 1; i < n+1; i++) {cout << get<0>(p[i]) << " " << get<1>(p[i]) << " " << get<2>(p[i]) << endl;}
  
  dp[0] = make_pair(0, 0);
  for (int i = 1; i < n+1; i++) {
	  
	hi = i-1; lo = 0;
  	ll r = 0;
  	
  	ll begin = get<0>(p[i]);
  	//cout << "Testing " << get<0>(p[i]) << " " << get<1>(p[i]) << " " << get<2>(p[i]) << endl;
  	
  	if (begin > dp[i-1].first) {dp[i] = make_pair(get<1>(p[i]), dp[i-1].second+get<2>(p[i])); continue;}
  	
  	while (lo <= hi) {
  		mid = lo + (hi-lo)/2;
  		//cout  << "debug mid: " << mid << " " << dp[mid].first << "," << dp[mid].second << endl;
  		
  		
		if (begin > dp[mid].first) {lo = mid+1; r = max(r, mid);}
		else {hi = mid-1;}
	}
	
	//cout  << "debug: " << r << " " << dp[r].first << "," << dp[r].second << endl;
	//cout << "         is " << dp[r].second << " + " << get<2>(p[i]) << " better than " << dp[i-1].second << "?" << endl;
	
	if (dp[r].second + get<2>(p[i]) > dp[i-1].second) {
		dp[i] = make_pair(get<1>(p[i]), dp[r].second+get<2>(p[i]));
	}
	else {dp[i] = dp[i-1];}
  	
  }
  
  //for (int i = 0; i < n+1; i++) {cout << dp[i].first << "," << dp[i].second << "  ";}
  
  cout << dp[n].second;
  
  return 0;
}

//JJ

