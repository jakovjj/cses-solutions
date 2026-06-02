#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, x[200003], pos[200003];
int r;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int mod = 1e9+7;
  
  cin >>n;
  r = 1;
  
  for (int i = 0; i < n; i++) {cin >> x[i];}
  for (int i = 0; i < n; i++) {pos[x[i]-1]= i+1;}
  
  //for (int i = 0; i < n; i++ ){cout << pos[i] << " ";} cout << endl;
  
  for (int i = 1; i < n; i++) {if (pos[i] < pos[i-1]) {r+=1;} }  
  
  
  cout << r;
  
  return 0;
}

//JJ

