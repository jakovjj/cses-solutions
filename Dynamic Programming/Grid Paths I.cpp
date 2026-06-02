#include <bits/stdc++.h>

using namespace std;

long long n; 
long long m = 1000000007;

string temp;

string mapa[1003];
long long posjet[1003][1003];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  for (long long i = 0; i < n; i++) {
  	cin >> temp;
  	mapa[i] = temp;
  }
  
  posjet[0][0] = 1;
  
  //pocetni posjeti
  for (long long i = 0; i < n; i++) {
  	if (mapa[0][i] == '*') {posjet[0][i] = 0; break;}
  	posjet[0][i] = 1;
  }
  for (long long i = 0; i < n; i++) {
  	if (mapa[i][0] == '*') {posjet[i][0] = 0; break;}
  	posjet[i][0] = 1;
  }
  // 


  for (long long i = 1; i < n; i++) {
  	for (long long j = 1; j < n; j++) {		
  		posjet[i][j] = posjet[i-1][j]+posjet[i][j-1];
  		if(posjet[i][j] >= m) {posjet[i][j] -= m;}
  		if (mapa[i][j] == '*') {posjet[i][j] = 0;}
	  }
  }
  
  //debug
  //for (long long i = 0; i < n; i++) {
  //	cout << mapa[i] << "\n";
  //}
  //for (long long i = 0; i < n; i++) {
  //	cout << "\n";
  //	for (long long j = 0; j < n; j++) {
  //		cout << posjet[i][j] << " ";
  //	  }
  //}
  //
  
  cout << posjet[n-1][n-1];
  
  return 0;
}

