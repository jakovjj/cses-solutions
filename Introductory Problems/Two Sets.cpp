#include <bits/stdc++.h>

using namespace std;

long long n, sum;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  
  sum = (1+n)*(n/2);
  if (n%2==1) {sum+=(n/2)+1;}
  if (sum%2==1) {cout << "NO"; return 0;}
  
  if (n%2==0) {
  	cout << "YES";
	cout << endl << n/2 << endl;
	for (int i = 1; i < (n/2)+1; i++) {if (i%2==1) {cout << i << " " << n+1-i << " ";}}
	cout << endl << n/2 << endl;
	for (int i = 1; i < (n/2)+1; i++) {if (i%2==0) {cout << i << " " << n+1-i << " ";}}
  }
  
  if (n%2==1) {
  	cout << "YES";
	cout << endl << n/2+1 << endl;
	for (int i = 1; i < (n/2)+1; i++) {if (i%2==1) {cout << i << " " << n-i << " ";}}
	cout << endl << n/2 << endl;
	for (int i = 1; i < (n/2)+1; i++) {if (i%2==0) {cout << i << " " << n-i << " ";}}
	cout << n;
  }
  
  return 0;
}


