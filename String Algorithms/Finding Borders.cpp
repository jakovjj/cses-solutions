#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9+7;

string s;
ll n, hashv[1000003], p, q, pot[1000003], h;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;

    p = 13337;
    hashv[0] = s[0]; pot[0] = 1; for (int i = 1; i < (int)s.size(); i++) {hashv[i] = hashv[i-1]*p+s[i]; pot[i] = pot[i-1]*p % mod; hashv[i] %=mod;}

    //for (int i = 0; i < (int)s.size(); i++) cout << hashv[i] << " ";
    //cout << "\n";


    for (int i = 0; i < (int)s.size()-1; i++) {    

        //cout << "start " << hashv[i] << ", end: " << hashv[(int)s.size()-1] - hashv[(int)s.size()-2-i]*pot[i+1] << "\n";

        if ((hashv[(int)s.size()-1] - hashv[(int)s.size()-2-i]*pot[i+1]%mod + mod) % mod  == hashv[i]) {
            cout << i+1 << " ";
        }

    }

    return 0;
}
