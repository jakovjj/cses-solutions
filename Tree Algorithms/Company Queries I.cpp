#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define mpair make_pair
#define MEMSET_MAX 0x7f
#define testcases \
  int t;        \
  cin >> t;       \
  while (t--)

// !!!

int n, tree[200003][20], x, k, q;
vector<int> children[200003];
queue<int> pq;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> q;
  for (int i = 2; i <= n; i++) {cin >> tree[i][0]; children[tree[i][0]].push_back(i);}
  
  pq.push(1);
  while (!pq.empty()) {
  	for (auto i : children[pq.front()]) {pq.push(i);}
  	
  	for (int i = 1; i <= 18; i++) {
  		tree[pq.front()][i] = tree[tree[pq.front()][i-1]][i-1];}
  	
  	pq.pop();
  }
  
  /*
  for (int i = 1; i <= n; i++) {
  	cout << i << endl;
  	for (int j = 0; j <= 5; j++) {
  		cout << "2^"<<j <<"th parent is " << tree[i][j] << endl;	
	}
  }
  */
  
  for (int i = 0; i < q; i++) {
  	cin >> x >> k;
  	
  	while (k!=0) {
  		int jumper = 1; int pot = 0;
		while (jumper <= k) {jumper*=2; pot++;}
		jumper/=2; pot--;
		
		x = tree[x][pot];
		k-=jumper;
	}
  	
  	if (x==0) {cout << -1 << "\n"; continue;}
  	cout << x << "\n"; 
  	
  }
  
  return 0;
}

//JJ

