#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int n, k;
int lo, hi, mid;
int r;
bool b;
 
vector<int> towers;
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n;
  
  cin >> k; towers.push_back(k);
  
  for (int i = 1; i < n; i++) {
	  lo = 0;
	  cin >> k;
	  hi = towers.size()-1;
	  b = 0;
	  
	  //cout << "NUMBER " << k;
  
	  while (lo <= hi ) {
	  	mid = lo + (hi-lo)/2;
	  	
	  		//cout << "( running mid " << mid << " " << towers.at(mid) << ")";	
	  	
			if (mid+1 == towers.size()) {
				if (k >= towers.at(mid)) {break;}
				else {b=1; towers.at(mid) = k; break;}
			}
			else if (mid == 0) {
				if (k < towers.at(mid)) {b = 1; towers.at(mid) = k; break;}
				else if (1 == towers.size()) {break;}
				else {lo = mid+1;}
			}
			else {
				if (k >= towers.at(mid)) {lo = mid+1;}
				else if (k < towers.at(mid) && k < towers.at(mid-1)) {hi=mid-1;}
				else {b=1; towers.at(mid) = k; break;}
				
			}

   		}
   		
   	
  		
  		
  if (b==0) {towers.push_back(k);
  //cout << "P" << k <<" " << endl;
  }
  //cout << " / ";
  
  }
  
  cout << towers.size();
  
  return 0;
}
 
//JJ


