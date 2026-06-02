#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q, a, b, len;

int m[200003][20];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for (int i = 0; i < n; i++) {cin >> m[i][0];}
  for (int e = 1; e < 18; e++) {for (int i = 0; i + (1<<e)-1 < n; i++) {m[i][e] = min(m[i][e-1], m[i+(1<<(e-1))][e-1]);}}
  for (int i = 0; i < q; i++) {cin >> a >> b;
  	a--; b--; len = b-a+1; int e = 0;
  	while (1<<(e+1) <= len) {e++;} cout << min(m[a][e], m[b-(1<<e)+1][e]) << endl;
  }
  
  return 0;
}

//JJ

