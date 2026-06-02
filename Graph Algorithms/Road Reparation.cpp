#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

priority_queue<tuple<int, int, int>, vector< tuple<int, int, int> >, greater<tuple<int, int, int>> > q;
ll n, m, r;
int rp;
ll a, b, c;

vector<int> pc; //path compression

int up1, up2;

int unions[200003];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> m;
  for (int i = 0; i < m; i++) {cin >> a >> b >> c; q.push(make_tuple(c, min(a,b), max(a,b)));}
  for (int i = 1; i < n+1; i++) {unions[i] = i;}
  
  while (!q.empty()) {
  	
  tuple<int, int, int> node = q.top();	
  //cout << endl << get<0>(node) << " " << get<1>(node) << " " << get<2>(node) << endl;
  
  up1 = get<1>(node);
  up2 = get<2>(node);
  pc.clear();
  //up -> union pointer
  while (unions[up1] != up1) {pc.push_back(up1); up1 = unions[up1];}
  for (int i = 0; i < pc.size(); i++) {unions[pc.at(i)] = up1;}
  
  pc.clear();
  while (unions[up2] != up2) {pc.push_back(up2); up2 = unions[up2];}
  for (int i = 0; i < pc.size(); i++) {unions[pc.at(i)] = up2;}
  
  if (up1!=up2) {unions[up2] = up1; r+= get<0>(node);}
  
  q.pop();
  }
  
  rp = 0;
  for (int i = 1; i < n+1; i++) {
  		if (unions[i] == i) {rp++;}
	  }
  
  if (rp > 1) {cout << "IMPOSSIBLE";}
  else {cout << r;}
  
  //for (int i = 1; i < n+1; i++) {cout << unions[i] << " ";}
  
  return 0;
}

//JJ

