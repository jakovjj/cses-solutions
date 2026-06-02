#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
ll n,t,a,mn;
struct uint256_t
{
    uint64_t bits[4];
};

vector<ll> brojevi;
long long bs(ll l, ll r, ll x){
	while(l<=r){
		ll mid;
		__int128 sum;
		sum=0;
		mid=l+(r-l)/2;
		for(int i = 0; i<n; i++){
//			if(brojevi[i]<=mid)
			sum+=mid/brojevi[i];
		}
		
		/*if(sum==x){
			retu;
		}*/
		if(sum>=x){
			r=mid-1;
			mn=min(mn,mid);
		}
		if(sum<x){
			l=mid+1;
		}
	}
	return -1;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin>>n>>t;
  mn=1e18+9;
  for(int i = 0; i<n; i++){
  	cin>>a;
  	brojevi.push_back(a);
  }
  ll s=bs(1,1e18+9,t);
  /*if(s==-1){
  	  cout<<mn;
  }else */cout<<mn;

  return 0;
}
//3 7
//3 2 5
