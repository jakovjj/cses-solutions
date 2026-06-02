#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
const ll inf = 1e18;

ll n, a, b, s1, s2, ans, op1, op2;
multiset<pll> s1s, s2s;
multiset<pair<ll, pll>> s1take;

pll temp1, temp2, temp3, temp4;
pair<ll, pll> tempop;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> a >> b >> n;
  for (int i = 1; i <= n; i++) {
  	cin >> s1 >> s2;
  	s1s.insert({s1, s2});
  	s2s.insert({s2, s1});
  }
  
  for (int i = 1; i <= a; i++) {
  	temp1 = (*s1s.rbegin());
  	temp2 = {temp1.second, temp1.first};
  	
  	s1s.erase(s1s.find(temp1));
  	s2s.erase(s2s.find(temp2));
  	
  	s1take.insert({temp1.second-temp1.first, temp1});
  	
  	ans += temp1.first;
  }
  
  for (int i = 1; i <= b; i++) {
  	temp2 = (*s2s.rbegin());
  	temp1 = {temp2.second, temp2.first};
  	op1 = temp2.first;
  	
  	if (!s1take.empty()) {
	  	tempop = *s1take.rbegin();
	  	temp3 = (*s1s.rbegin());
	  	temp4 = {temp3.second, temp3.first};
	  	op2 = tempop.second.second-tempop.second.first+temp3.first;
	} else op2 = -inf;
  	
  	if (op1 > op2) { //take new
  		s1s.erase(s1s.find(temp1));
  		s2s.erase(s2s.find(temp2));
  		ans += op1;
	}
	else { //replace
		s1take.erase(s1take.find(tempop));
		s1take.insert({temp3.second-temp3.first, temp3});
		
		s1s.erase(s1s.find(temp3));
  		s2s.erase(s2s.find(temp4));
		
		ans += op2;
	}
  }
  
  cout << ans;

  return 0;
}


