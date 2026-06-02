#include <bits/stdc++.h>
using namespace std;
 
int n, x;
int h[1008];
int s[1008];
int m[1008][100008];
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> x;
  
  for (int i = 0; i < n; i++ ) { cin >> h[i];} 
  for (int i = 0; i < n; i++ ) { cin >> s[i];} 
  
  for (int i = 1; i < n+1; i++) {
  	for (int j = 1; j < x+2; j++) {
  		
  	if (j > h[i-1] && m[i-1][j-h[i-1]]+s[i-1] > m[i-1][j]) {m[i][j] = m[i-1][j-h[i-1]]+s[i-1];}
  	else {m[i][j] = m[i-1][j];}
	}}
  
  cout << m[n][x+1];
  
  // DEBUG
  //for (int i = 0; i < n+1; i++) {
  //	cout << endl;
  //	for (int j = 1; j < x+2; j++) {cout << m[i][j] << " ";}}
  
  return 0;
}
 
//JJ


