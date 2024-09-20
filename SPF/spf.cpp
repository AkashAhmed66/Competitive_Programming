
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
///typedef __int128 lll;

const long long N = 1e6 + 10;
const long long MAX = 1e7 + 10;
const long long MOD = 1e9 + 7;
const long long MODD = 998244353;
const long long INF=1e18 + 10;
const int IINF=1e9 + 10;

int spf[MAX];
vector<int> primes;

void sieve(){
    for(int i=2; i<=MAX; i++){
        if(spf[i]==0){
            spf[i]=i;
            primes.push_back(i);
        }
        for(int j=0; (j<primes.size() && primes[j]<=spf[i] && i*primes[j] < MAX); j++){
            spf[i*primes[j]] = primes[j];
        }
    }
}
void factorize(int n){
    while(n > 1){
        int t = spf[n];
        cout<<t<<" ";
        while(spf[n] == t){
            n/=t;
        }
    }
}
void solve(){
    sieve();
    factorize(105);
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
