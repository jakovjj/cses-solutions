#include <bits/stdc++.h>

using namespace std;


int main()
{
  int n = 0; cin >> n; int array[n-1];
  for (int i = 0; i<n-1; i++) { cin >> array[i]; }
  
  if (n==2 && array[0]==2) { cout << 1; }
  else {
    sort(array, array+sizeof(array)/sizeof(array[0]));
      for (int i = 0; i<n;i++) {
  	    if (array[i]+1 != array[i+1]) {
  		  cout << array[i]+1;
  		  break;
	    }
    }
  }
  
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  return 0;
}


