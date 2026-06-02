#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const ll inf = 1e18;
int n, grundy[2003];

int solve(int x) {
	if (grundy[x] != -1) return grundy[x];
	set<int> mex;
	for (int i = 1; i < x/2+x%2; i++) mex.insert(solve(i)^solve(x-i));
	
	grundy[x] = 0;
	for (auto i : mex) {if (i != grundy[x]) break; grundy[x]++;}
	return grundy[x];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  memset(grundy, -1, sizeof(grundy));
  grundy[1] = 0; grundy[2] = 0;

  testcases {
  	cin >> n;
  	if (n > 2000) {cout << "first\n"; continue;}
  	solve(n);
  	grundy[n] ? cout << "first\n" : cout << "second\n";
  }

  return 0;
}


