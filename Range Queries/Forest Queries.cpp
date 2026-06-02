#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, q;
int ya, xa, yb, xb;
char temp;
int forest[1003][1003];
int rangesum[1003][1003];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> q;
  
  for (int i = 1; i < n+1; i++) {
  	for (int j = 1; j < n+1; j++) {
  		cin >> temp;
  		if (temp == '*') {forest[i][j] = 1;}
	  }
  }
  
  //for (int i = 0; i < n+1; i++) {cout << endl; for (int j = 0; j < n+1; j++) {cout << forest[i][j] << " ";}}
  
  for (int i = 1; i < n+1; i++) {
  	for (int j = 1; j < n+1; j++) {
  		rangesum[i][j] = rangesum[i][j-1] + rangesum[i-1][j] - rangesum[i-1][j-1] + forest[i][j];}}
  		
  //for (int i = 0; i < n+1; i++) {cout << endl; for (int j = 0; j < n+1; j++) {cout << rangesum[i][j] << " ";}}
  
  for (int i = 0; i < q; i++) {
  cin >> ya >> xa >> yb >> xb;
  cout << rangesum[yb][xb] - rangesum[yb][xa-1] - rangesum[ya-1][xb] + rangesum[ya-1][xa-1] << endl;
  
  } 
  
  
  return 0;
}

//JJ

