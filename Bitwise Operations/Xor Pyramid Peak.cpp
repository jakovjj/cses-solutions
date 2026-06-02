#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const ll inf = 1e18;

int n, a[200003][25], cnt, x, up, p, rowcnt, ocnt;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  
  cnt = 0;
  for (int i = 1; i <= n; i++) cin >> a[i][0];
  
  x = 0; up = 1; 
  rowcnt = n;
  while (up+1 <= rowcnt) {x++; up=up*2;} up=up/2;	
	
  while (x) {
  	cnt++;
	ocnt = rowcnt; rowcnt = 0;
	for (int i = up+1; i <= ocnt; i++) a[++rowcnt][cnt] = (a[i][cnt-1]^a[i-up][cnt-1]);
	x = 0; up = 1;
	while (up+1 <= rowcnt) {x++; up=up*2;} up=up/2;
  }
	
  cout << a[1][cnt];
  return 0;
}


