#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, r;
int ms; //max union size
int mpointer, pointer;
int unions[200003];
vector<int> compress;

int us[200003]; //union size

int a, b;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> m;
  
  for (int i = 1; i < n+1; i++) {unions[i] = i; us[i] = 1;}
  
  r = n; ms = 1;
  for (int i = 0; i < m; i++) {
  	cin >> a >> b;
  
  	if (a > b) {swap(a, b);}
  	compress.clear();
  	
  	mpointer = b; pointer = a;
  	while (unions[mpointer] != mpointer) {compress.push_back(mpointer); mpointer = unions[mpointer];}
  	while (unions[pointer] != pointer) {compress.push_back(pointer); pointer = unions[pointer];}
  	
  	if (pointer != mpointer) {
  		unions[pointer] = mpointer; 
		us[mpointer] += us[pointer]; us[pointer] = 0;
		for (auto s : compress) {unions[s] = unions[mpointer]; us[mpointer]+=us[pointer]; us[s] = 0;}
		r--;
	}
	else {cout << r << " " << ms << endl; continue;}
  	
  	unions[pointer] = mpointer; 
	us[mpointer] += us[pointer]; us[pointer] = 0;
	
  	for (auto s : compress) {unions[s] = unions[mpointer]; us[mpointer]+=us[pointer]; us[s] = 0;}
  	
  	//cout << "DEBUG: "; for (int i = 1; i < n+1; i++) {cout << us[i] << " ";} cout << endl;
  	ms = max(ms, us[mpointer]);
  	
	cout << r << " " << ms << endl;	
  }
  
  //for (int i = 1; i < n+1; i++) {cout << unions[i] << " ";}
  
  return 0;
}

//JJ

