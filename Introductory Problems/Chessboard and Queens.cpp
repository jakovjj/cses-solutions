#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define mpair make_pair
#define MEMSET_MAX 0x7f
#define testcases \
  float t;        \
  cin >> t;       \
  while (t--)

// !!!

int queens[9], r;
bool failed;
char chessboard[9][9];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  for (int i = 1; i <= 8; i++) {
  for (int j = 1; j <= 8; j++) {cin >> chessboard[i][j];}}
  
  for (int i = 0; i <= 7; i++) queens[i] = i+1;
  while (next_permutation(queens, queens+8)) {
  	failed = 0;
  	
  	for (int i = 1; i <= 8; i++) {
  		for (int j = 1; j <= 8; j++) { if(chessboard[i][j] == 'x') chessboard[i][j] = '.'; }
	  };
  	
  	for (int i = 0; i <= 7; i++) {
  		if(chessboard[i+1][queens[i]] == '*') {failed = 1; break;}
		chessboard[i+1][queens[i]] = 'x';
		  }
  	if (failed == 1) {continue;}
  	
  	for (int i = 0; i <= 6; i++) {
  		//checking diagonals for each row 
		for (int k = queens[i]-1; k >= 1; k--) {
			if(chessboard[i+(queens[i]-k)+1][k] == 'x') {failed = 1; break;}
		} 
		if (failed == 1) {break;}
		for (int k = queens[i]+1; k <= 8; k++) {
			if(chessboard[i+(k-queens[i])+1][k] == 'x') {failed = 1; break;}
		} 
		if (failed == 1) {break;}
	  }
	  
	  
  	if (failed == 1) {continue;}
  	
  	//for (int i = 0; i < 8; i++) {cout << queens[i] << " ";} cout << endl;
  	
  	r++;
  }
  
  cout << r;
  
  return 0;
}

//JJ

