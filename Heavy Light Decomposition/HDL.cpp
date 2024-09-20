#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
///typedef __int128 lll;

const long long N = 1e6 + 40;
const long long MOD = 1e9 + 7;
const long long MODD = 998244353;
const long long INF=1e18 + 10;
const int IINF=1e9 + 10;

vector<ll> g[N],parent(N),heavy(N, -1),depth(N),head(N),euler,pos(N),x(N);

ll dfs(int u, int p){

    ll size=1, mx_size=0;

    for(int v : g[u]){

        if(v == p)continue;

        parent[v] = u;
        depth[v] = depth[u]+1;

        ll v_size = dfs(v, u);

        if(v_size > mx_size){
            mx_size = v_size;
            heavy[u] = v;
        }

        size += v_size;
    }

    return size;
}
void decompose(int u, int p, int h){

    head[u]=h;
    pos[u]=euler.size();
    euler.push_back(x[u]);

    if(heavy[u] != -1){
        decompose(heavy[u], u, h);
    }

    for(int v : g[u]){
        if(v == p || v == heavy[u])continue;
        decompose(v, u, v);
    }
}
vector<ll> tree(5*N);

void build(int node, int start, int end){
   if(start == end){
        tree[node] = euler[start];
    }else{
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
void update(int node, int start, int end, int idx, ll val){
    if(start == end){
        euler[idx] += val;
        tree[node] += val;
    }else{
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid){
            update(2*node, start, mid, idx, val);
        }else{
            update(2*node+1, mid+1, end, idx, val);
        }

        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
ll query(int node, int start, int end, int l, int r){
    if(r < start || end < l){
        return 0;
    }
    if(l <= start && end <= r){
        return tree[node];
    }
    int mid = (start + end) / 2;
    ll p1 = query(2*node, start, mid, l, r);
    ll p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}

ll HLD_Query(int a, int b){
    ll ans=0;
    for( ; head[a] != head[b]; b=parent[head[b]]){
        if(depth[head[a]] > depth[head[b]]){
            swap(a, b);
        }
        ans+=query(1, 0, euler.size()-1, pos[head[b]], pos[b]);
    }
    if(depth[a] > depth[b]){
        swap(a, b);
    }
    ans+=query(1, 0, euler.size()-1, pos[a], pos[b]);
    return ans;
}
void solve(){
    ll n,q;
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>x[i];
    }
    for(int i=2; i<=n; i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    decompose(1, 0, 1);
    build(1, 0, euler.size()-1);

    while(q--){
        int type;
        cin>>type;
        if(type == 1){
            ll node,val;
            cin>>node>>val;
            update(1, 0, euler.size()-1, pos[node], val-euler[pos[node]]);
        }else{
            int node;
            cin>>node;
            cout<<HLD_Query(1, node)<<"\n";
        }
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
