#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define mpair make_pair
#define MEMSET_MAX 0x7f
#define testcases \
  float t;        \
  cin >> t;       \
  while (t--)

// !!!

ll x, n, sum, r;
priority_queue<ll, vector<ll>, greater<ll>> heap;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> x >> n;
  
  ll a;
  for (int i = 0; i < n; i++) {
  	cin >> a; heap.push(a);
  }
  
  while(heap.size() != 1) {
  	sum = heap.top();
	heap.pop();
	sum+=heap.top();
	heap.pop();
	
	heap.push(sum);
	r+= sum;	
  }
  
  cout << r;
  
  return 0;
}

//JJ

