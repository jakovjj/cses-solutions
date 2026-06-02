#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

long long n, t;
long long a, d, r;

vector<pll> task;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  for (int i = 0; i < n; i++) {cin >> a >> d; task.push_back(make_pair(a, d));}
  sort(task.begin(), task.end());
  
  for (auto k : task) {
  	t+=k.first; r+=k.second-t;
  }
  
  cout << r;
  
  return 0;
}

//JJ

