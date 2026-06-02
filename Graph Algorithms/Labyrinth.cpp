#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int n, m, r;
vector<string> labyrinth;
string temp, temp2;
 
string path;
 
queue< tuple<int, int, string> > q;
 
string past[1003][1003];
 
bool b;
 
bool visited[1003][1003];
int a_y, a_x, b_y, b_x, temp_y, temp_x;
 
void bfs(int y, int x, string dir) {
	if (b == 1 || visited[y][x] == 1) {return;}
	
	visited[y][x] = 1;
	past[y][x] = dir;
	
	if (labyrinth.at(y)[x] == 'B') {b = 1; b_y = y; b_x = x;}
	
	if (labyrinth.at(y-1)[x] != '#' && visited[y-1][x] == 0) {q.push(make_tuple(y-1, x, "U"));}
	if (labyrinth.at(y+1)[x] != '#' && visited[y+1][x] == 0) {q.push(make_tuple(y+1, x, "D"));}
	if (labyrinth.at(y)[x-1] != '#' && visited[y][x-1] == 0) {q.push(make_tuple(y, x-1, "L"));}
	if (labyrinth.at(y)[x+1] != '#' && visited[y][x+1] == 0) {q.push(make_tuple(y, x+1, "R"));}
	
	return;
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  
  //labyrinth setup
  cin >> n >> m; temp = '#';
  for (int i = 0; i < m+1; i++) {temp = temp+'#';}
  temp2=temp; 
  labyrinth.push_back(temp2);
  
  b = 0;
  
  for (int i = 0; i < n; i++) {
  	cin >> temp;
  	
  	for (int j = 0; j < m; j++) {if (temp[j] == 'A') {a_y=i+1; a_x = j+1; break;}}
  	
  	labyrinth.push_back('#'+temp+'#');}
  labyrinth.push_back(temp2);
  
  //push bfs
  q.push(make_tuple(a_y, a_x, "G"));
  
  while (!q.empty()) {
    bfs(get<0>(q.front()), get<1>(q.front()), get<2>(q.front()));
	q.pop();
  }
  
  //track back
  if (b == 1) {
  temp_y = b_y; temp_x = b_x;
  path = "";
		while (past[temp_y][temp_x] != "G") {
			path+=past[temp_y][temp_x];
			if (past[temp_y][temp_x] == "U") {temp_y+=1;}
			else if (past[temp_y][temp_x] == "D") {temp_y-=1;}
			else if (past[temp_y][temp_x] == "L") {temp_x+=1;}
			else if (past[temp_y][temp_x] == "R") {temp_x-=1;}
		}
  }
  
  
  
  //debug
  if (b==1) {
	  cout << "YES" << endl;
	  cout << path.length() << endl;
	  reverse(path.begin(), path.end()); 
	  cout<<path;
   }
  
  else {cout << "NO";}
 
  
  
  return 0;
}
 
//JJ

