#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;

int visited[9][9], cnt;

int reachable(int x, int y) {
	if (x < 1 || x > 8 || y < 1 || y > 8 || visited[x][y]) return -1;	
	
	int pcnt = 0;
	if (x+2 <= 8 && y+1 <= 8 && visited[x+2][y+1] == 0) pcnt++;
	if (x-2 >= 1 && y+1 <= 8 && visited[x-2][y+1] == 0) pcnt++;
	if (x+2 <= 8 && y-1 >= 1 && visited[x+2][y-1] == 0) pcnt++;
	if (x-2 >= 1 && y-1 >= 1 && visited[x-2][y-1] == 0) pcnt++;
	
	if (x+1 <= 8 && y+2 <= 8 && visited[x+1][y+2] == 0) pcnt++;
	if (x-1 >= 1 && y+2 <= 8 && visited[x-1][y+2] == 0) pcnt++;
	if (x+1 <= 8 && y-2 >= 1 && visited[x+1][y-2] == 0) pcnt++;
	if (x-1 >= 1 && y-2 >= 1 && visited[x-1][y-2] == 0) pcnt++;
	
	return pcnt;
}

void solve(int x, int y) {
	visited[x][y] = ++cnt;
	//cout << "Solving for " << x << " " << y << ", CNT: " << cnt << endl;
	if (cnt >= 64) return;
	
	vector<pair<int, pii>> v = {};
	
	if (reachable(x+2, y+1) != -1) v.push_back({reachable(x+2, y+1), {x+2, y+1}});
	if (reachable(x-2, y+1) != -1) v.push_back({reachable(x-2, y+1), {x-2, y+1}});
	if (reachable(x+2, y-1) != -1) v.push_back({reachable(x+2, y-1), {x+2, y-1}});
	if (reachable(x-2, y-1) != -1) v.push_back({reachable(x-2, y-1), {x-2, y-1}});
	if (reachable(x+1, y+2) != -1) v.push_back({reachable(x+1, y+2), {x+1, y+2}});
	if (reachable(x-1, y+2) != -1) v.push_back({reachable(x-1, y+2), {x-1, y+2}});
	if (reachable(x+1, y-2) != -1) v.push_back({reachable(x+1, y-2), {x+1, y-2}});
	if (reachable(x-1, y-2) != -1) v.push_back({reachable(x-1, y-2), {x-1, y-2}});
	sort(v.begin(), v.end());
	
	for (auto i : v) {
		solve(i.second.first, i.second.second);
		if (cnt >= 64) return;
	}
	
	cnt--;
	visited[x][y] = 0;
	//cout << "Backtracking from " << x << "," << y << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
	
  int x, y;
  cin >> x >> y;
  swap(x, y);

  solve(x, y);
  
  for (int i = 1; i <= 8; i++) {
	for (int j = 1; j <= 8; j++) cout << visited[i][j] << " ";
	cout << "\n";
  }

  return 0;
}


