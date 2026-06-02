#include <bits/stdc++.h>

using namespace std;

long long n, k;
long long hi, lo, mid, sum, arrs, min_sum, r;
long long a[200007];

int array_division(long long ar_size) {
	sum = 0; arrs = 1;
	
	//	cout << "TESTING FOR " << ar_size << endl;
	
	for (long long i = 0; i < n; i++) {
		
		if (a[i] > ar_size) {return 0;}
		else if (sum+a[i] > ar_size && arrs < k) {
		//cout << "SPLITTING ARRAY AFTER " << a[i] << ". " << endl;
		arrs += 1; sum = a[i];}
		else if (sum+a[i] > ar_size && arrs >= k) {return 0;}
		else {sum += a[i];
		//cout << "ADDING " << a[i] << " TO ARRAY." << endl;
		}
	
	}
	
	return 1;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> k;
  sum = 0;
  for (long long i = 0; i < n; i++) {cin >> a[i]; sum += a[i];}
  
  lo = 0; hi = sum; r = 0; min_sum = sum;

  while (hi > lo && lo < hi) {
  	mid = lo + (hi-lo)/2;
  	
  	if (array_division(mid)) {
  		min_sum = min(min_sum, mid);
  		hi = mid;
	}
	else {
		lo = mid+1;
	}
  }
  
  cout << min_sum;
  
  return 0;
}


