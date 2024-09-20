#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
///typedef __int128 lll;

const long long N = 2e5 + 10;
const long long MOD = 1e9 + 7;
const long long MODD = 998244353;
const long long INF=1e18 + 10;
const int IINF=1e9 + 10;

vector<int>g[N];
int up[N][29];

void binary_lifting(int u, int p){
    up[u][0]=p;
    for(int i=1; i<20; i++){
        if(up[u][i-1] != -1){
            up[u][i]=up[up[u][i-1]][i-1];
        }else{
            up[u][i]=-1;
        }
    }
    for(int v : g[u]){
        if(v == p)continue;
        binary_lifting(v, u);
    }
}

int query(int u, int k){
    if(u == -1 || k==0){
        return u;
    }
    for(int i=19; i>=0; i--){
        if(k >= (1<<i)){
            return query(up[u][i], k-(1<<i));
        }
    }
}
void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=2; i<=n; i++){
        int u;
        cin>>u;
        g[u].push_back(i);
        g[i].push_back(u);
    }
    binary_lifting(1, -1);
    while(q--){
        int node, k;
        cin>>node>>k;
        cout<<query(node, k)<<"\n";
    }
    cout<<"\n";

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
