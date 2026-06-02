#include <bits/stdc++.h>
using namespace std;
 
string s1, s2;
int temp1, temp2, temp3;
int r;
long long tablica[5003][5003];
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> s1;
  cin >> s2;
  tablica[0][0] = 0;
  
  for (int i = 1; i < s1.size()+1; i++) {tablica[i][0] = tablica[i-1][0]+1;}
  for (int j = 1; j < s2.size()+1; j++) {tablica[0][j] = tablica[0][j-1]+1;}
  
  for (int i = 1; i < s1.size()+1; i++) {
  	for (int j = 1; j < s2.size()+1; j++) {
  		
  		temp1 = tablica[i-1][j];
  		temp2 = tablica[i][j-1];
  		temp3 = tablica[i-1][j-1];
		
		r = min(temp1, temp2); 
		r = min(r, temp3);
		tablica[i][j] = r;
		tablica[i][j] += 1;
		
		//cout << s1[i-1];
		if(s1[i-1] == s2[j-1]) {tablica[i][j] = tablica[i-1][j-1];}
  }}
  
  //debug
  //for (int i = 0; i < s1.size()+1; i++) {cout << endl; for (int j = 0; j < s2.size()+1; j++) {cout << tablica[i][j] << " ";} } cout << endl; 
  
  cout << tablica[s1.size()][s2.size()];
  
  return 0;
}


