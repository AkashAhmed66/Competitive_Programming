#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
///typedef __int128 lll;

const long long N=2e5 + 50;
const long long MOD = 1e9 + 7;
const long long MODD = 998244353;
const long long INF=1e18 + 10;
const int IINF=1e9 + 10;

int sparse[N][20],LOG[N];
int n,b[N];

void Build(){
    for(int i = 0; i < n; i++){
        sparse[i][0] =  b[i];
        LOG[i]=__lg(i);
    }
    LOG[n]=__lg(n);
    for(int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; (i + (1 << j) - 1) < n; i++) {
            sparse[i][j] = max(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int Query(int l, int r){

    int sz = (r - l + 1);
    int j=LOG[sz];
    ll mn = max(sparse[l][j], sparse[r - (1 << j) + 1][j]);
    return mn;
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
