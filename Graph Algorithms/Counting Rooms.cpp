#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int row, col, ct = 0;
char table[1003][1003];

void bfs(int posi, int posj){	
	table[posi][posj] = '0';

	if (posi != 0 && table[posi-1][posj] == '.')  {bfs(posi-1, posj);}
	if (posj != 0 && table[posi][posj-1] == '.')  {bfs(posi, posj-1);}
	if (table[posi+1][posj] == '.')  {bfs(posi+1, posj);}
	if (table[posi][posj+1] == '.') {bfs(posi, posj+1);}
		
	return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> row >> col;
  for(int i = 0; i < row; i++){
  	for(int j = 0; j< col; j++){	  
	  cin >> table[i][j];
  }}
  
  for(int i = 0; i < row; i++){
  	for(int j = 0; j< col; j++){
  		if (table[i][j] == '.') {		  
		  ct++;
		  bfs(i, j);		  
		}
	  }
	}

 	cout << ct;
  return 0;
}

