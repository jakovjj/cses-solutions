#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9+7;
const int inf = 2147483647;

int n;
stack<pii> solve;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  int x[n+3];
  
  solve.push(make_pair(0, 0));
  //first -> value, second -> pos
  for (int i = 1; i < n+1; i++) {
  	cin >> x[i];
  
  	//cout << "DEBUG: " << x[i] << endl;
	while (solve.top().first >= x[i]) {
		//cout << " | Popping " << solve.top().first << " " << solve.top().second << endl; 
		solve.pop();
	}
	cout << solve.top().second << " ";
  
  	solve.push(make_pair(x[i], i));
  }
  
  return 0;
}

//JJ

