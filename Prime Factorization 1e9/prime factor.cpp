#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const long long N=5e5 + 10;
const long long MOD=1e9 + 7;
const long long INF=1e12;

/// Prime factorization for 1e9

const long long SQRT=4e4;
vector<long long>prime;

void sieve(){
    vector<long long>iscomp(SQRT+1, 0);
    for(long long i=2; i<=SQRT; i++){
        if(iscomp[i]==1)continue;
        iscomp[i]=1;
        prime.push_back(i);
        for(long long j=i*2; j<=SQRT; j+=i){
            iscomp[j]=1;
        }
    }
}
void solve(){
    int n;
    cin>>n;
    int x[n];
    for(int i=0; i<n; i++)cin>>x[i];
    map<long long, long long>mp;
    for(int i=0; i<n; i++){
        int t=x[i];
        for(int p : prime){
            if(p*p>t)break;
            if(t%p==0){
                while(t%p==0){
                    t/=p;
                }
            }
        }
        if(t > 1){

        }
    }
}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    sieve();
    for(int i=1; i<=t; i++){
        //cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}
