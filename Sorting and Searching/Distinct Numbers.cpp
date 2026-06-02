#include <bits/stdc++.h>

using namespace std;


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  long long n;
  cin >> n;
  
  int brojcek;
  int printer = n;
  vector<int> numbers;
  
  for (int i = 0; i < n; i++) {
  	cin >> brojcek;
  	numbers.push_back(brojcek);
  }
  
  sort(numbers.begin(), numbers.end());
  
  int prev = 0;
  for (int i = 0; i < n; i ++) {
  	if (numbers[i] == prev) printer = printer - 1;
  	prev = numbers[i];
  }
  
  cout  << printer;
  
  return 0;
}


