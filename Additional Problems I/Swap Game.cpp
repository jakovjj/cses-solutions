#include <bits/stdc++.h>
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
#define ll long long

ll m, c, pw[13];
bool w;
unordered_map<ll, ll> mp;
queue<pair<ll, ll>> q;

ll swp(ll a, ll l, ll r) {
	return a-(a/pw[l-1]-a/pw[l]*10)*pw[l-1]-(a/pw[r-1]-a/pw[r]*10)*pw[r-1]+(a/pw[l-1]-a/pw[l]*10)*pw[r-1]+(a/pw[r-1]-a/pw[r]*10)*pw[l-1];	
}

void solve(ll x, ll cnt) {
	if (mp[x]) return;
	mp[x] = cnt;
	if (x == 123456789) {w = 1; return;}
	
	x = swp(x, 9, 8); q.push({x, cnt+1}); x = swp(x, 9, 8);
	x = swp(x, 8, 7); q.push({x, cnt+1}); x = swp(x, 8, 7);
	x = swp(x, 6, 5); q.push({x, cnt+1}); x = swp(x, 6, 5);
	x = swp(x, 5, 4); q.push({x, cnt+1}); x = swp(x, 5, 4);
	x = swp(x, 3, 2); q.push({x, cnt+1}); x = swp(x, 3, 2);
	x = swp(x, 2, 1); q.push({x, cnt+1}); x = swp(x, 2, 1);
	
	x = swp(x, 9, 6); q.push({x, cnt+1}); x = swp(x, 9, 6);
	x = swp(x, 6, 3); q.push({x, cnt+1}); x = swp(x, 6, 3);
	x = swp(x, 8, 5); q.push({x, cnt+1}); x = swp(x, 8, 5);
	x = swp(x, 5, 2); q.push({x, cnt+1}); x = swp(x, 5, 2);
	x = swp(x, 7, 4); q.push({x, cnt+1}); x = swp(x, 7, 4);
	x = swp(x, 4, 1); q.push({x, cnt+1}); x = swp(x, 4, 1);
	
	return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  w = 0;
  pw[0] = 1; pw[1] = 10; for (int i = 2; i <= 10; i++) pw[i] = pw[i-1]*10;	
  for (int i = 1; i <= 3; i++) for (int j = 1; j <= 3; j++) {cin >> c; m+=c*pw[9-(j+(i-1)*3)];}
  
  q.push({m, 1});
  
  while (!q.empty()) {
  	if (w) break;
  	//cout << q.front().first << endl;
  	solve(q.front().first, q.front().second);
  	q.pop();
  }
  
  cout << mp[123456789]-1 << "\n";
  return 0;
}

