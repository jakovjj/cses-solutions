#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const ll inf = 1e18;

ll n, x, y;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> x >> y;
  
  //za svaku potenciju broja dva podijeli niz u segmente te
  //velicine, te radi inverzije nad njima postupno
  //npr. 0 1 2 3 4 5 6 7 -> 1 0 3 2 5 4 7 6 (inverzije brojeva po jedan)
  //slijedi 2 3 0 1 6 7 4 5 (ekvivalent jedne inverzije na vecem stupnju
  //nakon koje ide 3 2 1 0 7 6 5 4... sve te inverzije se mogu opisati
  //putem integera... prvo je bilo 000, pa 001, 010, 011...
  
  //prilikom xoranja x i y iste inverzije se ponistavaju, a drugacije
  //primjene.
  
  //jakovljeva lemma: prvi broj u redu xora x i y je rjesenje
   
  //oduzmi 1 jer je 1-indeksirano... :P
  
  cout << ((x-1)^(y-1));

  return 0;
}


