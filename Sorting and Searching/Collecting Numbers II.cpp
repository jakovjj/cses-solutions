#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int n, m, x[200003], pos[200003];
int r, a, b;
 
set<pair<int, int>> ch;
vector<pair<int, int>> c1;
vector<pair<int, int>> c2;
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int mod = 1e9+7;
  
  cin >> n >> m;
  r = 1;
  
  for (int i = 0; i < n; i++) {cin >> x[i];}
  for (int i = 0; i < n; i++) {pos[x[i]-1]= i+1;}
  for (int i = 1; i < n; i++) {if (pos[i] < pos[i-1]) {r+=1;} }  
  
  
  //SWAPS
  for (int i = 0; i < m; i++) {
  	cin >> a >> b;
  	ch.clear();
  	c1.clear();
  	c2.clear();
  	
  	swap(x[a-1], x[b-1]);
  	if (x[a-1]-1 > 0) {ch.insert(make_pair(x[a-1]-1, x[a-1]));}
  	if (x[a-1]+1 <= n) {ch.insert(make_pair(x[a-1], x[a-1]+1));}
  	if (x[b-1]-1 > 0) {ch.insert(make_pair(x[b-1]-1, x[b-1]));}
  	if (x[b-1]+1 <= n) {ch.insert(make_pair(x[b-1], x[b-1]+1));}
  	
  	for (auto s : ch) {c1.push_back(make_pair(pos[s.first-1], pos[s.second-1])); }
  	swap(pos[x[a-1]-1], pos[x[b-1]-1]);
  	for (auto s : ch) {c2.push_back(make_pair(pos[s.first-1], pos[s.second-1]));}
  	
  	/*
  	cout << endl << "debug" << endl;
  	for (auto s : ch) {cout << "<"<< s.first << " " << s.second << "> ";} cout << endl;
  	for (auto s : c1) {cout << "<"<< s.first << " " << s.second << "> ";} cout << endl;
  	cout << endl; cout << "POSITION LIST: "; for (int i = 0; i < n; i++ ){cout << pos[i] << " ";} cout << endl;
  	*/
  	
  	for (int i = 0; i < c1.size(); i++) {
  		if (c1.at(i).first == c2.at(i).first) {
  			if (c1.at(i).second > c1.at(i).first && c2.at(i).second < c1.at(i).first) {r+=1;}
			else if (c1.at(i).second < c1.at(i).first && c2.at(i).second > c1.at(i).first) {r-=1;}	
		}
		else if (c1.at(i).second == c2.at(i).second) {
  			if (c1.at(i).first > c1.at(i).second && c2.at(i).first < c1.at(i).second) {r-=1;}
			else if (c1.at(i).first < c1.at(i).second && c2.at(i).first > c1.at(i).second) {r+=1;}	
		}
		else {
			if (c1.at(i).first > c1.at(i).second) {r-=1;} else {r+=1;}
		}
	}
	
  	cout << r << endl;
  }
  
  return 0;
}


