#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
const ll inf = 1e9;

ll n, x, y;
__int128 l, sum, cnt, res;
string s;
vector<__int128> xv, yv;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  REP(i, n) {
  	cin >> x >> y;
  	xv.push_back(x);
  	yv.push_back(y);
  }
  sort(xv.begin(), xv.end());
  sort(yv.begin(), yv.end());
  res = 0;
  
  l = xv[0]; sum = 0; cnt = n;
  for (auto i : xv) sum += i-l;
  for (auto i : xv) {
	sum -= (i-l)*cnt;
 	res += sum; l = i;
 	cnt--;
  }
  
  l = yv[0]; sum = 0; cnt = n;
  for (auto i : yv) sum += i-l;
  for (auto i : yv) {
	sum -= (i-l)*cnt;
 	res += sum; l = i;
 	cnt--;
  }

  if (res == 0) {cout << "0"; return 0;}

  while (res) {
  	s+=(char)((res%10)+'0');
  	res/=10;
  } reverse(s.begin(), s.end());

  cout << s;
  return 0;
}
