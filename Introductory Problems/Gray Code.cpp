#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, l, t, addl, co;
vector<int> bt;
vector<int> temp;

string binary(int num) {
	
	string s = "";
	
	for (int i = 1<<(n-1); i > 0; i/=2) {
  	if ((num&i) != 0) {s+="1";} else {s+="0";}
  	}
	
	return s;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  
  t = 0;
  cout << binary(t) << endl;
  co = 1;
  for (int i = 0; i < n; i++) {co*=2;}
  //cout << "co" << co;
  
  for (int i = 1; i < co; i=i*2) {
  		t+=i;
		cout << binary(t) << endl;
		temp.push_back(i);
		
  		for (int s = bt.size()-1; s >= 0; s--) {
		  	t += bt.at(s)*(-1);
		  	cout << binary(t) << endl;
  			temp.push_back(bt.at(s)*(-1));
		}
		
		for (auto s : temp) {
			bt.push_back(s);
		} 
		temp.clear();
  }
  
  
  return 0;
}

//JJ

