#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define mpair make_pair
#define MEMSET_MAX 0x7f
#define testcases \
  int t;        \
  cin >> t;       \
  while (t--)

// !!!

int n, graph[200003], r[200003], visited[200003];
stack<int> path;
stack<int> cycle;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  memset(r, -1, sizeof(r));
  cin >> n;
  for (int i = 1; i < n+1; i++) {cin >> graph[i];}
  
  for (int i = 1; i < n+1; i++) {
  	
  	if (visited[i] == 1) continue;
  	
  	//cout << "searching with node " << i << "\n";
  	
  	int node = i;
  	while (visited[node] == 0) {
  		path.push(node);
  		cycle.push(node);
  		
  		//cout << "pushing node " << node << "\n";
  		
  		visited[node] = 1;
  		
  		node = graph[node];
	}
  	
  	//cout << "search ended at node " << node << "\n";
  	
  	int cycle_length;
  	if (r[node] == -1) {
  		cycle_length = 1;
  		while (cycle.top() != node) {cycle.pop(); cycle_length++;}
		while (!cycle.empty()) {cycle.pop();}
		
		bool b = 0;
		
		while (!path.empty()) {
			r[path.top()] = cycle_length;
			if(path.top() == node) {b = 1;}
			if (b==1) {cycle_length++;}
			path.pop();
		}
	}
	else {
		cycle_length = r[node]+1;
		while (!cycle.empty()) {cycle.pop();}
		while (!path.empty()) {
			r[path.top()] = cycle_length;
			cycle_length++;
			path.pop();
		}
	}
  }
  
  for (int i = 1; i < n+1; i++) {cout << r[i] << " ";}
  
  return 0;
}

//JJ

