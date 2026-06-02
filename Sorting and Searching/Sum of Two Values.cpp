#include <bits/stdc++.h>
 
using namespace std;
#define elif else if
 
long long n, x, r, l;
map <long long, long long> m;
long long a[200003]; 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> n >> x;
  for(long i=0; i<n; i++){cin >> a[i];}
  for (int i = 0; i < n; i++) m[a[i]]=i+1;
 
 for (int i = 0; i < n+1; i++) {
  if(i==n){cout << "IMPOSSIBLE"; break;} 

  if(m[x-a[i]] != i+1 && m[x-a[i]] != 0) { cout << i+1 << " " << m[x-a[i]]; break;}

}

  /*cout << endl;

  for(int i=0; i<g.size(); i++) cout << g[i] << endl;*/
 

  return 0;
}
