#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, a, b, r;
vector<int> graph[100003];
vector<int> result;

int visited[100003];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  int distance[100003];
  queue<int> q;
  q.push(1);
  
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
  	cin >> a >> b;
  	graph[a].push_back(b);
  	graph[b].push_back(a);
  }
  
  distance[1] = 0;
  visited[q.front()] = true;
  while (!q.empty()) {
  	//cout << "d" << q.front() << " ";
  	for (auto u : graph[q.front()] ) {
  		if (visited[u] != 0) { continue; }
		visited[u] = q.front();
		distance[u] = distance[q.front()]+1;
		q.push(u);
	  }
	q.pop();
  }
  
  //for (int i = 1; i < n+1; i++) {cout << distance[i] << " ";} cout << endl;
  //for (int i = 1; i < n+1; i++) {cout << visited[i] << " ";}
  
  if (visited[n] != 0) {
  	  r = n; result.push_back(r);
  	while (r!=1) {
  	r = visited[r];
  	result.push_back(r);
    }
  
    cout << distance[n]+1 << endl;
    for (int i = result.size()-1; i >= 0; i--) {cout << result.at(i) << " ";}	
    }
  else {
  	cout << "IMPOSSIBLE";
  }
  
  return 0;
}

//JJ

