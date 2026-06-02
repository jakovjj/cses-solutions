#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, a, b, temp;
vector<pii> ranges;
map<pii, int> locator;

int contained[200003];
int contains[200003];

int inf = 2147000000;

bool mainsort(pii a, pii b) {
	if (b.first > a.first) {return 1;}
	else if (b.first == a.first) {
		if (b.second < a.second) {return 1;}
		else {return 0;}
	}
	else {return 0;}
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  
  for (int i = 0; i < n; i++) {
  	cin >> a >> b; ranges.push_back(make_pair(a, b));
	  locator[make_pair(a, b)] = i;
	  }

  sort(ranges.begin(), ranges.end(), mainsort);
  //for (auto k : ranges) {cout << k.first << " " << k.second << endl;}
  
  for (int i = 0; i < n; i++) {
  	//cout << ranges[i].first << " " << ranges[i].second << "(" << locator[make_pair(ranges[i].first, ranges[i].second)] << ", " << temp << ")    ";
  	if (temp >= ranges[i].second) {
  		contained[locator[make_pair(ranges[i].first, ranges[i].second)]] = 1;
	  }
	else {temp = ranges[i].second;}
  }
  
  temp = inf;
  for (int i = n-1; i >= 0; i--) {
  	if (temp <= ranges[i].second) {
  		contains[locator[make_pair(ranges[i].first, ranges[i].second)]] = 1;
	  }
	else {temp = ranges[i].second;}
  } 
  
  
  //results
  for (int i = 0; i < n; i++) {
  	cout << contains[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
  	cout << contained[i] << " ";
  }
  
  return 0;
}

//JJ

