#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, q;
ll a, b, c;

ll dist[503][503];
ll inf = 99999999999999;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> m >> q;
  
  for (int i = 0; i < n+1; i++) {for (int j = 0; j < n+1; j++) {
  if (i == j) {continue;}
  dist[i][j]=inf;}}
  
  //graph input
  for (int i = 0; i < m; i++) {
  	cin >> a >> b >> c;
  	
  	dist[a][b] = min(dist[a][b], c);
  	dist[b][a] = min(dist[b][a], c);}
  	
  
  // loop + results
  
  for (int k = 0; k < n+1; k++) {
  	for (int i = 0; i < n+1; i++) {
  		for (int j = 0; j < n+1; j++) {
  			
  			dist[i][j] = min(dist[i][j], dist[k][j]+dist[i][k]);
  				
		  }	
	  }
  }
  
  for (int i = 0; i < q; i++) {
  	cin >> a >> b;
  	
  	if (dist[a][b] == inf) {cout << "-1" << endl;}
  	else {cout << dist[a][b] << endl;
  }}
  
  //debug
  /*
  for (int i = 0; i < n+1; i++) {
  	cout << endl;
  	for (int j = 0; j < n+1; j++) {
  		cout << dist[i][j] << " ";
	  }
  }
  */
  
  return 0;
}

//JJ

