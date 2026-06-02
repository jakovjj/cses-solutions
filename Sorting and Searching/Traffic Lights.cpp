#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x, n, temp;
int lo, hi;
set<int> l;
multiset<int> r;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> x >> n;
  
  l.insert(x);
  r.insert(x);
  
  for (int i = 0; i < n; i++) {
  	cin >> temp;
  	int c;
  	//cout << "INITIATING...";
  	auto it = l.lower_bound(temp);
  	
  	hi = *it;
  	if (it == l.begin()) {lo=0;}
  	else {lo = *--it;}

  	//cout << "so far so good!";
  	//cout << endl << endl << "MAIN DBG:" << lo << " " << hi;
  	
  	if (lo==0) {
  		c = r.count(hi);
		r.erase(hi);
		while (c != 1) {r.insert(hi); c--;}
		
		r.insert(temp);
		r.insert(hi-temp);
	}
	else {
  		c = r.count(hi-lo);
		r.erase(hi-lo);
		while (c != 1) {r.insert(hi-lo); c--;}

		r.insert(hi-temp);
		r.insert(temp-lo);
	}
	l.insert(temp);
	
	//debug
	/*
  	cout << endl << "DEBUG: " << endl;
  	for (auto d:r) {cout << d << " ";} cout << endl;
  	for (auto d:l) {cout << d << " ";} cout << endl; 
  	*/
  	cout << *--r.end() << " ";
  }
  
  return 0;
}

//JJ

