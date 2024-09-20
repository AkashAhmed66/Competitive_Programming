#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long N=5e5 + 10;
const long long MOD=1e9 + 7;;
const long long INF=1e18 + 2;

ll fact[N+1];
ll invers[N+1];

ll bigMod(ll a, ll b){
    if(b==0)return 1LL ;
    ll ans=bigMod(a, b/2);
    ans=(ans*ans)%MOD;
    if(b%2==1){
        ans=(ans*a)%MOD;
    }
    return ans;
}

void countFact(){
    ll ans=1;
    fact[0]=1;
    for(int i=1; i<=N; i++){
        ans*=i;
        ans%=MOD;
        fact[i]=ans;
    }
    invers[N]=bigMod(fact[N],MOD-2);
    for(int i=N-1; i>0; i--){
        invers[i]=(invers[i+1]*(i+1))%MOD;
    }
}

ll ncm[33][33];
void nCm(){
    ncm[0][0]=1;
    for(int i=1; i<=30; i++){
        ncm[i][0]=1;
        for(int j=1; j<=30; j++){
            ncm[i][j]=ncm[i-1][j]+ncm[i-1][j-1];
        }
    }
}

ll C(ll n, ll r){
    return (((fact[n]*invers[r])%MOD)*invers[n-r])%MOD;
}
void solve() {
    cout<<C(25,3);
}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    countFact();
    //cin>>t;
    for(int i=1; i<=t; i++){
        //cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}
