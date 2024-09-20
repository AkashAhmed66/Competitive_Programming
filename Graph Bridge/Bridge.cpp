
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const long long N=5e5 + 10;
const long long MOD=1e9 + 7;
const long long INF=1e6 + 2;
vector<int>g[N],vis(N,0),in(N,0),low(N,0);
int timer=0;
void dfs(int u, int p){
    vis[u]=1;
    low[u]=in[u]=timer;
    timer++;
    for(int v : g[u]){
        if(v==p)continue;
        if(vis[v]==1){
            low[u]=min(low[u],in[v]);
        }else{
            dfs(v,u);
            if(in[u]<low[v]){
                cout<<u<<" "<<v<<" bridge\n";
            }
            low[u]=min(low[u],low[v]);
        }
    }
}
void solve(){
    int n,e;
    cin>>n;
    e=n-1;
    while(e--){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,-1);

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
