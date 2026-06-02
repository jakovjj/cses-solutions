#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, r, temp;
int a, b, c;

int ans[200003];
priority_queue< pii, vector<pii>, greater<pii> > hotel;
vector<tuple<int, int, int>> room;

bool allocate(tuple<int, int, int> x, tuple<int, int, int> y) {
	if (get<0>(y) > get<0>(x)) {return 1;}
	else if (get<0>(y) == get<0>(x)) {
		if (get<1>(y) > get<1>(x)) return 1;
		else return 0;
	} else return 0;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  
  for (int i = 0; i < n; i++) {
  	cin >> a >> b;
  	room.push_back(make_tuple(a, b, i+1));
  }
  
  sort(room.begin(), room.end(), allocate);
  //for (auto s : room) {cout << get<0>(s) << " " << get<1>(s) << " " << get<2>(s) << endl;}
  
  hotel.push(make_pair(2147000000, 0));
  
  r = 0;
  for (auto s : room) {
  	if (hotel.top().first < get<0>(s)) {
  		
  		int temp = hotel.top().second;
  		
  		hotel.pop();
  		hotel.push(make_pair(get<1>(s), temp));
  		
  		ans[get<2>(s)] = temp;
	  }
	else {
		r++;
		hotel.push(make_pair(get<1>(s), r));
		ans[get<2>(s)] = r;
	}
  }
  
  cout << r << endl;
  for (int i = 1; i < n+1; i++) {cout << ans[i] << " ";}  
  
  return 0;
}

//JJ

