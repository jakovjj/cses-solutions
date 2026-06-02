#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define mpair make_pair
#define MEMSET_MAX 0x7f
#define testcases \
 
int n, m, a, segtree[800003];
 
void hotelcheck(int l, int r, int index, int group) {	
	if (l==r && segtree[index] >= group) {segtree[index]-=group; cout << l << endl; return;}
	else if (l==r && segtree[index] < group) {cout << 0 << endl; return;}
	
	int mid = l+(r-l)/2;
	
	if (segtree[index*2] >= group) {hotelcheck(l, mid, index*2, group);}
	else if (segtree[index*2+1] >= group) {hotelcheck(mid+1, r, index*2+1, group);}
	else {cout << 0 << endl; return;}
	
	segtree[index] = max(segtree[index*2], segtree[index*2+1]);
}
 
void build(int l, int r, int index) {
	
	if(l==r) {cin >> segtree[index]; return;}
	
	int mid = l+(r-l)/2;
	
	build(l, mid, index*2);
	build(mid+1, r, index*2+1);
	
	segtree[index] = max(segtree[index*2], segtree[index*2+1]);
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> m;
  build(1, n, 1);
  
  for (int i = 0; i < m; i++) {
  	cin >> a;
  	hotelcheck(1, n, 1, a);
  }
  
  return 0;
}
 
//JJ

