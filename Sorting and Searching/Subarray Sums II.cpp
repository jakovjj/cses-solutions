#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

long long n, x, sum;
long long r;
map<long long, long long> m;

int num[200003];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> x;
  m[0]++;
  
  for (int i = 1; i < n+1; i++) {cin >> num[i];}
  for (int i = 1; i < n+1; i++) {
  	sum+=num[i];
  	
  	//cout << "Sum is " << sum << ", looking for map of " << sum-x << endl;
  	//if (m[sum-x] != 0) {cout << "Adding " << m[sum-x] << " to res" << endl;} 
  	
  	r+=m[sum-x];
  	
  	m[sum]++;
  }
  
  cout << r;
  
  return 0;
}

//JJ

