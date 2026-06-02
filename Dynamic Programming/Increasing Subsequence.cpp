#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9+7;
const int inf = 2147483647;
 
int n;
int hi, lo, mid;
int nums[200003];
int dp[200003];
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  
  for (int i = 0; i < n; i++) {cin >> nums[i];}
  
  int c = 1;
  int last = 0;
  for (int i = 0; i < n; i++) {
  	int r = 99999999;
  	if (nums[i] > last) {
	  dp[c] = nums[i]; last = nums[i]; c++;
	  //cout << "debug: adding " << nums[i] << " length: " << c << endl;
	  }
  	else {
  		lo = 0; hi = c;
  		//cout << "debug: " << nums[i] << " doesnt fit. bs " << endl;
  		while (lo <= hi) {
  			mid = lo+(hi-lo)/2;
  			//cout << "testing" << mid << dp[mid] << endl;
			if (nums[i] < dp[mid]) {hi=mid-1; r=min(r, mid);}
			else if (nums[i] == dp[mid]) {r=mid; break;}
			else if (nums[i] > dp[mid]) { lo = mid+1;}		
		  }
		//cout << "replacing middle at " << r << " (" << dp[r] << ")" << endl;
		dp[r] = nums[i]; if (r == c-1) {last = nums[i];}
	}
  }
  
  cout << c-1;
  
  return 0;
}
 
//JJ

