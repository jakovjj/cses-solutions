#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

long long n, m, a, b, r;
vector<pll> movies;

multiset<long long> members;

bool mainsort(pii a, pii b) {return (a.second < b.second);}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
  	cin >> a >> b;
  	movies.push_back(make_pair(a, b));
  }
   
  sort(movies.begin(), movies.end(), mainsort);
  
  members.insert(-1);
  for (int i = 0; i < m; i++) {members.insert(0);}
  
  for (auto& k : movies) {
  	//cout << "checking movie " << k.first << " " << k.second << endl;
  	
  	auto it = members.upper_bound(k.first);
  	it--;
  	
  	//cout << " > best member is " << *it << endl;
  	if (*it != -1) {
  		r++;
  		//cout << " > result is now " << r << endl;
  		members.erase(it);
  		members.insert(k.second);
	  }
  }
  
  cout << r;
  
  return 0;
}

//JJ

