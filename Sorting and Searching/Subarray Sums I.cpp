#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
ll n,k,a,sum,ct,p;
vector<ll> brojevi;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin>>n>>k;
  for(int i = 0; i<n; i++){
  	cin>>a;
  	sum+=a;
  	brojevi.push_back(sum);
  }  
  /*for(int i = brojevi.size()-1; i>=0; i--){
  	for(int j =i-1; j>=0; j--){
  		cout<<brojevi[i]<<" "<<brojevi[j]<<" :  ";
  		if(brojevi[i]==k){
  			ct++;
  			break;
		  }else if(brojevi[i]-brojevi[j]==k){
  			ct++;
  			break;
		  }else if(brojevi[i]-brojevi[j]>k){
		  	break;
		  }
	  }
  }*/
  p=0;
  for(int i = 0; i<brojevi.size(); i++){
  	for(int j =p; j<brojevi.size(); j++){
//  		cout<<brojevi[i]<<" "<<brojevi[j]<<" :  ";
		ll prev = 0;
		if (i > 0) prev = brojevi[i-1];
		
		  if(brojevi[j]-prev==k){
  			ct++;
  			break;
		  }else if(brojevi[j]-prev>k){
		  	break;
		  }
		  p++;
	  }
  }
  cout<<ct;
  return 0;
}
