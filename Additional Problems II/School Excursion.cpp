#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mpair make_pair
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const int inf = 2147483647;

int un[100003], unsz[100003], n, m, a, b, x;
bitset<100003> res;
bool v[100003]; 

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {un[i] = i; unsz[i] = 1;}
  res[0] = 1;
  
  for (int i = 1; i <= m; i++) {
  	cin >> a >> b;
  	
  	while (un[a] != a) a = un[a];
  	while (un[b] != b) b = un[b];
	if (a < b) swap(a, b);
	
	unsz[a] += unsz[b];
  	un[b] = a; 
  }
  
  for (int i = 1; i <= n; i++) {
  	x = i;
  	while (un[x] != x) x = un[x];
  	//cout << un[x] << " ("  << unsz[x] << ") ";
  	
  	if (!v[un[x]]) {
  		res |= (res<<unsz[x]);
  		v[un[x]] = 1;
	}
  	
  } //cout << "\n";
  
  for (int i = 1; i <= n; i++) cout << res[i];

  return 0;
}

