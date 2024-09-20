#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long N=5e5 + 10;
const long long MOD=1e9 + 7;;
const long long INF=1e18 + 2;
ll a,b,t,ta,tb;
ll q;
vector<pair<ll, ll> >pr;
ll f(ll mid){
    ll x=mid;
    ll y=t-x;
    ll tta=a+(x/ta);
    ll ttb=b+(y/tb);
    ll ans=0;
    for(int i=0; i<q; i++){
        if(pr[i].first<=tta && pr[i].second<=ttb)ans++;
    }
    return ans;
}
/// max
ll ternary_search(ll l=0, ll r=t) {
    while (r - l >= 3) {
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
        ll f1 = f(m1);      //evaluates the function at m1
        ll f2 = f(m2);      //evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    ll ans=0;
    while(l<=r){
        ans=max(ans,f(l));
        l++;
    }
    return ans;
}
void solve() {
    cin>>a>>b>>t>>ta>>tb;
    cin>>q;
    for(int i=0; i<q; i++){
        ll a,b;
        cin>>a>>b;
        pr.push_back({a,b});
    }
    cout<<ternary_search()<<"\n";
}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    for(int i=1; i<=t; i++){
        //cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}
