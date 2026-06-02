#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(int i = 1; i <= (n); i++)

vector<int> basis;
int n, res;

void add(int x) {
	for (auto i : basis) x = min(x, x^i);
	if (x) basis.push_back(x);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n; int x;
  REP(i, n) {cin >> x; add(x);}
  
  res = 0;
  for (auto i : basis) res = max(res, res^i);
  cout << res;

  return 0;
}

