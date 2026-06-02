#include <bits/stdc++.h>
using namespace std;
 
long long n,a,sum;
long long cs[200009];
long long ct;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
  	cin>>a;
  	sum+=a;
  	long long b;
  	if(sum%n==0) ct++;
  	b=sum%n;
  	if (b < 0) b+=n;
  	cs[b]++;
  }
  for(int i=0;i<n;i++) {ct+=(cs[i]*(cs[i]-1))/2;}
  
  cout<<ct;
  return 0;
}

