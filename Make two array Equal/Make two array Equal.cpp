
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const long long N=2e5 + 10;
const long long MOD=1e9 + 7;
const long long INF=1e6 + 2;

vector<int>cmpr_arr(N);
bool cmp(int a, int b){
    return cmpr_arr[a]<cmpr_arr[b];
}
void solve(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        cmpr_arr[x]=i;
    }
    vector<int>y(n);
    for(int i=0; i<n; i++)cin>>y[i];
    sort(y.begin(), y.end(), cmp);
    for(int i=0; i<n; i++){
        cout<<y[i]<<" ";
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
