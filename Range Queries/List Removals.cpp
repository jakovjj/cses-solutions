#include <bits/stdc++.h>

using namespace std;

int n, amt, p;
int hotels[800003];
int numvalue[800003];
int segtree[800003];

void build(int l, int r, int index) {
	if (l==r) {segtree[index]=1; numvalue[index] = amt; amt++; return;}
	
	int mid = l+(r-l)/2;
	build(l, mid, index*2);
	build(mid+1, r, index*2+1);
	
	segtree[index] = segtree[index*2]+segtree[index*2+1];
}

void query(int l, int r, int index, int val) {
	
	//cout << "Looking at segment " << l << ":" << r << ", value " << val << endl;
	//cout << "Left Child: " << segtree[index*2] << " | Right Child:  " << segtree[index*2+1] << endl;
	
	
	if (l==r) {
		
	segtree[index] = 0;
	//cout << numvalue[index] << " ";
	cout << hotels[numvalue[index]] << " "; 
	
	return;}
	
	int mid = l+(r-l)/2;
	if (  segtree[index*2] >= val ) {
		query(l, mid, index*2, val);
	}
	else {
		query(mid+1, r, index*2+1, val-segtree[index*2]);
	}
	
	segtree[index] = segtree[index*2]+segtree[index*2+1];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  amt = 1;
  build(1, n, 1);
  for (int i = 1; i < n+1; i++) {cin >> hotels[i];}
  for (int i = 0; i < n; i++) {
  	cin >> p;
  	query(1, n, 1, p);
  }
  
  
  return 0;
}

