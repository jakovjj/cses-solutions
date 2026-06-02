#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int a, b, c;
priority_queue< pair <ll, int>, vector<pair<ll, int>>, greater<pair<ll, int> > > q; //pair -> distance od start nodea, node 
vector< pair<ll, int> > graph[200004]; //pair -> distanca, pointer nodea
bool visited[200004];
ll dist[200004];
ll inf = 99999999999999;

void dijkstra(int node, ll distance) {
	if (visited[node] == 1) {return;}
	visited[node] = 1;
	//cout << endl << "Looping dijkstra for " << node << endl;
	for (int i = 0; i < graph[node].size(); i++) {
		if (visited[graph[node].at(i).second] == 0) {
			//cout << "Running check for " << node << " to " << graph[node].at(i).second << " with distance " << graph[node].at(i).first << "; Current distance to node 1 is " << distance << " and to node 2 is " << dist[graph[node].at(i).second] << endl;
			dist[graph[node].at(i).second] = min(dist[graph[node].at(i).second], distance+graph[node].at(i).first);
			//cout << "Distance for " << graph[node].at(i).second << " is now " << dist[graph[node].at(i).second] << endl;
			q.push(make_pair(dist[graph[node].at(i).second], graph[node].at(i).second));
		}
	}
		
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> m;
  q.push(make_pair(0, 1));
  
  //graph input
  for (int i = 0; i < m; i++) {
  	cin >> a >> b >> c;
  	graph[a].push_back(make_pair(c, b));}
  	
  //start dist
  for (int i = 0; i < n+1; i++) {dist[i] = inf;} dist[1] = 0;
  
  // loop + results
  while (!q.empty()) {dijkstra(q.top().second, q.top().first); q.pop();}
  for (int i = 1; i < n+1; i++) {cout << dist[i] << " ";}
  
  return 0;
}

//JJ

