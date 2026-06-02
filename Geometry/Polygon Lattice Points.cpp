#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9+7; const int inf = 2147483647;

struct point{
	ll x;
	ll y;
};

ll gcd (ll x, ll y) {
	if (x == 0) return y;
	return gcd(y%x, x);
}

ll n;
long double a, b;
point arr[100003];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  
  b = n;
  for (int i = 0; i < n; i++) cin >> arr[i].x >> arr[i].y;
  for (int i = 0; i < n; i++) {
  	a += arr[i].x * arr[(i+1)%n].y - arr[(i+1)%n].x * arr[i].y;
  	b += gcd(abs(arr[i].x-arr[(i+1)%n].x), abs(arr[i].y-arr[(i+1)%n].y))-1;
  }
  
  a = abs(a)/2;
  cout << fixed << setprecision(0) << a-b/2+1 << " " << b << "\n";

  return 0;
}

