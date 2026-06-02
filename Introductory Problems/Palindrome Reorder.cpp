#include <bits/stdc++.h>
using namespace std;
int y,maxi,mini,c,cn,np,S;
int L[200];
string s,x,f,g;
int main(){
	cin>>x;
	for (int i=0; i<x.size(); i++) L[x[i]]++;
	
	s = ""; g = ""; f = "";
	
	for (int i='A'; i<='Z'; i++){
		if (L[i]%2) {np=i; cn++;}
		if (cn>1) {cout<<"NO SOLUTION"; return 0;}
	}
	
	if (np!=0) {
		while (L[np]>0) {g.push_back(char(np)); L[np]--;}
	}
	
	for (int i='A'; i<='Z'; i++) {
		if (L[i]) {S=L[i]/2; while (L[i]>S){s.push_back(char(i));L[i]--;}}
	}
	for (int i='Z'; i>='A'; i--) {
		if (L[i]) {while (L[i]>0){f.push_back(char(i));L[i]--;}}
	}
	
	cout<<s<<g<<f;
	return 0;
}
