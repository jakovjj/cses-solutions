#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
string w;
int r;
set<string> results;
 
void permute(string temp, int a, int b) {
	if (a == b) {results.insert(temp); return;}
	
	for (int i = a; i < b; i++) {
		swap(temp[a], temp[i]); //abc -> bac ; abc -> cba
		permute(temp, a+1, b); //rekurzija
		swap(temp[a], temp[i]); //vrati nazad za sljedecu permutaciju
	}
} 
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> w;  
  permute(w, 0, w.size());
  
  cout << results.size() << endl;
  for (auto s : results) {cout << s << endl;} 
  
  return 0;
}
 
//JJ

