#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll n,q,x,a,b,o;
ll s[200010],st[800020];
 
void ct(ll l, ll h, ll p){
    if (l==h){
        st[p]=s[l];return;
    }
    ll m=(l+h)/2;
    ct(l,m,p*2+1);
    ct(m+1,h,p*2+2);
    st[p]=st[p*2+1]+st[p*2+2];
    return;
}
 
ll rq(ll l, ll h, ll p, ll qa, ll qb){
    if (qa>h || qb<l){
        return 0;
    }
    if (qa<=l && h<=qb){
        return st[p];
    }
    ll m=(l+h)/2;
    return rq(l,m,p*2+1,qa,qb)+rq(m+1,h,p*2+2,qa,qb);
}
 
ll upd(ll x, ll y, ll l, ll h, ll p){
    if (l==h && l==x){s[l]=y;st[p]=y;return st[p];}
    if (x<l || x>h){return st[p];}
    ll m=(l+h)/2;
    ll lf=upd(x,y,l,m,2*p+1);
    ll rt=upd(x,y,m+1,h,2*p+2);
    st[p]=lf+rt;
    return st[p];
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 
    cin >> n >> q;
    for (ll i=0; i<n; i++){
        cin >> x;s[i]=x;
    }
    ct(0,n-1,0);
    for (ll i=0; i<q; i++){
        cin >> o >> a >> b;
        if (o==1){
            upd(a-1,b,0,n-1,0);
        }
        else{
            cout << rq(0,n-1,0,a-1,b-1) << endl;
        }
    }
 
    return 0;
}
