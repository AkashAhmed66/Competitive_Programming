
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const long long N=5e5 + 10;
const long long MOD=1e9 + 7;
const long long INF=1e6 + 2;

vector<int>g[N],vis(N,0),height(N,0),euler,first(N,0);
int tree[N*4],n;

void dfs(int u, int h){
    vis[u]=1;
    height[u]=h;
    first[u]=euler.size();
    euler.push_back(u);
    for(int v : g[u]){
        if(vis[v]==1)continue;
        dfs(v,h+1);
        euler.push_back(u);
    }
}

void build(int node, int s, int e){
    if(s==e){
        tree[node] = euler[s];
        return;
    }
    int mid=(s+e)/2;
    build(2*node, s, mid);
    build(2*node + 1, mid+1, e);
    int left=tree[2*node];
    int right=tree[2*node + 1];

    if(height[left]<height[right]){
        tree[node]=left;
    }else {
        tree[node]=right;
    }
}

int query(int node, int s, int e, int l, int r){
    if(s>r || e<l){
        return -1;
    }
    if(s>=l && e<=r){
        return tree[node];
    }
    int mid = (s+e)/2;
    int left = query(node*2, s, mid, l, r);
    int right = query(node*2 + 1, mid+1, e, l, r);

    if(left == -1)return right;
    if(right == -1)return left;

    if(height[left]<height[right]){
        return left;
    }else {
        return right;
    }
}
int lca(int u, int v){
    int left=first[u];
    int right=first[v];
    if(right<left)swap(left,right);
    return query(1, 0, euler.size()-1, left, right);
}
void clr(int n){
    euler.clear();
    for(int i=0; i<= n+100; i++){
        g[i].clear();
        vis[i]=0;
        height[i]=0;
        first[i]=0;
    }
}
void solve(){
    clr(euler.size());
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        int m;
        cin>>m;
        while(m--){
            int x;
            cin>>x;
            g[i].push_back(x);
        }
    }
    dfs(1,0);
    build(1,0,euler.size()-1);
    int q;
    cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<lca(u,v)<<"\n";
    }

}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    for(int i=1; i<=t; i++){
        cout<<"Case "<<i<<": \n";
        solve();
    }
    return 0;
}
