
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const long long N=2e5 + 10;
const long long MOD = 1e9 + 7;
const long long MODD = 998244353;
const long long INF=2e18 + 10;
const int IINF=1e9 + 10;

int grundy[10005];
bool vis[10005];

int calGrundy(int n){

    if(n<=2)return 0;

    if(grundy[n] != -1)return grundy[n];

    memset(vis, false, sizeof(vis));

    int mid=n/2;
    if(n%2==0)mid--;

    for(int i=1;i<=mid;i++)
    {
        vis[calGrundy(i)^calGrundy(n-i)]=true;;
    }

    int ans=0;
    while(vis[ans]==true)ans++;

    return grundy[n]=ans;

}

void solve(){
    int n;
    cin>>n;
    int Xor=0;
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        Xor^=calGrundy(t);
    }
    if(Xor != 0){
        cout<<"Alice\n";
    }else{
        cout<<"Bob\n";
    }

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;

    memset(grundy, -1, sizeof(grundy));
    for(int i=0; i<=10000; i++)calGrundy(i);

    cin>>t;
    for(int i=1; i<=t; i++){
        cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}
