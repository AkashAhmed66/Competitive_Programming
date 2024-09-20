#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const long long N=5e5 + 10;
const long long MOD=1e9 + 7;
const long long INF=1e18 + 2;

int base=31;
// mod = 1e9 + 7, 1e9 + 9
// base = 31, 29

vector<long long> compute_hash(string s){
    int n=s.size();
    vector<long long> hsh(n);
    for(int i=0; i<n; i++){
        if(i)hsh[i]=hsh[i-1];
        hsh[i]*=base;
        hsh[i]%=MOD;
        hsh[i]+=(s[i]-'a'+1);
        hsh[i]%=MOD;
    }
    return hsh;
}
long long bigmod(int a, int b){
    if(b==0)return 1;
    long long res=bigmod(a,b/2);
    res%=MOD;
    res*=res;
    res%=MOD;
    if(b%2==1){
        res*=(a%MOD);
        res%MOD;
    }
    return res;
}
vector<long long> compute_reverse_hash(string s){
    int n=s.size();
    vector<long long> hsh(n);
    for(int i=n-1; i>=0; i--){
        long long p=bigmod(base,(n-1)-i);
        p%=MOD;
        p*=(s[i]-'a'+1);
        p%=MOD;
        if(i<n-1)hsh[i]+=hsh[i+1];
        hsh[i]%=MOD;
        hsh[i]+=p;
        hsh[i]%=MOD;
    }
    return hsh;
}
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<long long>hsh=compute_hash(s);
    vector<long long>rhsh=compute_reverse_hash(s);


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
