#include <bits/stdc++.h>

using namespace std;

long long n, q;
int t1, t2;
long long l[200005];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> q ;
  for (int i = 1; i < n+1; i++) {cin >> l[i];}
  for (int i = 1; i < n+1; i++) {l[i] = l[i] + l[i-1];}
  for (int i = 0; i < q; i++) {
  	cin >> t1 >> t2;
  	cout << l[t2] - l[t1-1] << endl;;
  }
  
  return 0;
}


