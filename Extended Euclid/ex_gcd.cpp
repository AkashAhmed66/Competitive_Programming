
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
///typedef __int128 lll;

const long long N = 2e5 + 50;
const long long MOD = 1e9 + 7;
const long long MODD = 998244353;
const long long INF=1e18 + 10;
const int IINF=1e9 + 10;
/// ax + by = c
/// c % gcd(a,b) == 0
/// ax % b == c
int extended_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
void solve(){

}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    for(int i=1; i<=t; i++){
        //cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}
