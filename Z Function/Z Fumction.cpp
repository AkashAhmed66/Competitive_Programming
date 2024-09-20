#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const long long N=5e5 + 10;
const long long MOD=1e8;
const long long INF=1e18 + 2;
vector<int> z_function(string s){
    int n=s.size();
    vector<int>pre(n);
    for(int i=1; i<n; i++){
        int j=pre[i-1];
        while(j>0 && s[i] != s[j]){
            j=pre[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pre[i]=j;
    }
    return pre;
}
void solve(){
    string s;
    cin>>s;
    vector<int>pre=z_function(s);
    int n=s.size(),x=0;
    for(int i=1;i<n;i++){
        cout<<pre[i]<<" ";
    }
    cout<<"\n";

    for(int i=1;i<n-1;i++){
        if(pre[i]==pre[n-1] || pre[i]==pre[pre[n-1]-1])x=max(x,pre[i]);
    }
    if(x){
        cout<<s.substr(0,x)<<"\n";
    }else{
        cout<<"Just a legend\n";
    }

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
