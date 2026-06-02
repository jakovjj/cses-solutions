#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
char s[50];
int res;
int counter;
int visited[9][9];
 
void solve(int x, int y, int t) {
	
	if (t == 49 && x == 1 && y == 7) {res++; return;}
	if (x < 1 || x > 7 || y < 1 || y > 7) return;
	if (visited[x][y] == 1) return;
	if (visited[x+1][y] == visited[x-1][y] && visited[x][y+1] == visited[x][y-1]) return;
	if (t != 49 && x == 1 && y == 7) return;
	if (t == 49 && (x != 1 || y != 7)) return;
	
	//corners
	if (visited[x-1][y-1] == 1 && visited[x-1][y] == 0 && visited[x][y-1] == 0) return;
	if (visited[x+1][y+1] == 1 && visited[x+1][y] == 0 && visited[x][y+1] == 0) return; 
	if (visited[x-1][y+1] == 1 && visited[x-1][y] == 0 && visited[x][y+1] == 0) return; 
	if (visited[x+1][y-1] == 1 && visited[x+1][y] == 0 && visited[x][y-1] == 0) return;

	visited[x][y] = 1; 
	
	if (s[t] == '?') {
	    solve(x, y+1, t+1); solve(x, y-1, t+1); solve(x-1, y, t+1); solve(x+1, y, t+1);}
	    
	else if (s[t] == 'R') {solve(x+1, y, t+1);}
	else if (s[t] == 'L') {solve(x-1, y, t+1);}
	else if (s[t] == 'D') {solve(x, y+1, t+1);}
	else if (s[t] == 'U') {solve(x, y-1, t+1);}
	
	visited[x][y] = 0;
	
	return;
	
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  res = 0;
  for (int i = 1; i <= 48; i++) {cin >> s[i];}
  for (int i = 0; i <= 8; i++) {visited[0][i] = 1; visited[i][0] = 1; visited[8][i] = 1; visited[i][8] = 1;}
  
  solve(1, 1, 1);
  cout << res;
  
  return 0;
}
 
//JJ
