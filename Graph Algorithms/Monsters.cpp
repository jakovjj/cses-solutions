#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int inf = (1<<30);

int n, m, shortest_end, monster[1003][1003], player[1003][1003];
queue<pair<pii, int>> monsterq, playerq;
char dir[1003][1003], maze[1003][1003];
pii best_end;
string backstring;
 
void backtrack(int x, int y) {
	if (dir[x][y] == 'C') return;
	backstring+=dir[x][y];
	
	if (dir[x][y] == 'L') backtrack(x, y+1);
	else if (dir[x][y] == 'R') backtrack(x, y-1);
	else if (dir[x][y] == 'U') backtrack(x+1, y);
	else if (dir[x][y] == 'D') backtrack(x-1, y);
	
	return;
}
 
void playerbfs(int x, int y, int s) {
	if(maze[x][y] != '.' && maze[x][y] != 'A') return;
	if(player[x][y] != inf) return;
	
	player[x][y] = s;
	playerq.push({{x+1, y}, s+1});
	if (!dir[x+1][y]) dir[x+1][y] = 'D';
	
	playerq.push({{x-1, y}, s+1});
	if (!dir[x-1][y]) dir[x-1][y] = 'U';
	
	playerq.push({{x, y+1}, s+1});
	if (!dir[x][y+1]) dir[x][y+1] = 'R';
	
	playerq.push({{x, y-1}, s+1});
	if (!dir[x][y-1]) dir[x][y-1] = 'L';
 
	return;
}
 
void monsterbfs(int x, int y, int s) {
	if(maze[x][y] != '.' && maze[x][y] != 'M') return;
	if(monster[x][y] != inf) return;
	
	monster[x][y] = s;
	monsterq.push({{x+1, y}, s+1});
	monsterq.push({{x-1, y}, s+1});
	monsterq.push({{x, y+1}, s+1});
	monsterq.push({{x, y-1}, s+1});
	
	return;
}
 
int main()
{  
  cin >> n >> m;
  for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
  	cin >> maze[i][j];
  	monster[i][j] = inf; player[i][j] = inf;
  	if (maze[i][j] == 'M') monsterq.push({{i, j}, 0});
  	if (maze[i][j] == 'A') {dir[i][j] = 'C'; playerq.push({{i, j}, 0});}
  }
  
  while (!playerq.empty()) {playerbfs(playerq.front().first.first, playerq.front().first.second, playerq.front().second); playerq.pop();}
  while (!monsterq.empty()) {monsterbfs(monsterq.front().first.first, monsterq.front().first.second, monsterq.front().second); monsterq.pop();}
  	
  best_end = {0, 0};
  shortest_end = inf;
  
  for (int i = 1; i <= n; i++) {
  	if (player[i][1] < monster[i][1] && player[i][1] < shortest_end) {best_end = {i, 1}; shortest_end = player[i][1];};
  	if (player[i][m] < monster[i][m] && player[i][m] < shortest_end) {best_end = {i, m}; shortest_end = player[i][m];};
  	if (player[1][i] < monster[1][i] && player[1][i] < shortest_end) {best_end = {1, i}; shortest_end = player[1][i];};
  	if (player[n][i] < monster[n][i] && player[n][i] < shortest_end) {best_end = {n, i}; shortest_end = player[n][i];};
  }
  
  if (shortest_end == inf) {cout << "NO"; return 0;}
  backtrack(best_end.first, best_end.second); reverse(backstring.begin(), backstring.end());
  cout << "YES\n" << shortest_end << "\n" << backstring;
  
  return 0;
}
