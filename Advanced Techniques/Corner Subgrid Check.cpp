#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = a; i <= (b); i++)

int n, k, a[3003][3003];
char c;
bool v[27][3003][3003], w[27];
vector<int> r[27];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  REP(i, n) REP(j, n) {cin >> c; a[i][j] = c-'A'+1;}
  
  REP(i, n) {
  	REP(j, n) {
  		if (w[a[i][j]]) continue;
  		for (auto l : r[a[i][j]]) {
  			if (v[a[i][j]][l][j]) {w[a[i][j]] = 1; break;}
  			v[a[i][j]][l][j] = 1;
		}
		r[a[i][j]].push_back(j);
	}
	REP(j, k) r[j].clear();
  } 

  REP(i, k) {
  	if (w[i]) cout << "YES\n";
  	else cout << "NO\n";
  }

  return 0;
}


