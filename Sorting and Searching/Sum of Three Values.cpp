#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll n, k, tempsum, p1, p2, p3, temp;
pair<ll, ll> d[5003];

bool b;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> k;
  for (int i = 0; i < n; i++) {cin >> temp; d[i] = make_pair(temp, i+1);}
  sort(d, d+n);
  
  //for (int i = 0; i < n; i++) {cout << d[i].first << " ";} cout << endl;
  
  for (p1 = 0; p1 < n; p1++) {
  	if (b == 1) {p1--; break;}
  	p3 = n-1;
  	for (p2 = p1+1; p2 < n; p2++) {
  		
		tempsum = d[p1].first+d[p2].first;
		while (tempsum + d[p3].first > k) {p3--; if(p3 <= p2) {continue;}}
		
		//cout << "DEBUG: " << p1 << " " << p2 << " " << p3 << endl;
		
		if (d[p1].first+d[p2].first+d[p3].first == k && p1 < p3 && p1 != p2 && p2 != p3) {b = 1; break;}
  }}
  
  if (b==0) {cout << "IMPOSSIBLE"; return 0;}
  
  cout << d[p1].second << " " << d[p2].second << " " << d[p3].second;
  //cout << p1 << p2 << p3;
  
  return 0;
}

//JJ

