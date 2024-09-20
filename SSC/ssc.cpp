#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const long long N=2e5 + 10;

vector<int> adj[N], adj_rev[N];
vector<bool> used;
vector<int> order, component;
map<long long, long long> mp;
set<int> st;
int cost[N];

void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v]){
        if (!used[u]){
            dfs1(u);
        }
    }
    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);
    mp[cost[v-1]]++;
    st.insert(cost[v-1]);
    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

void solve(){
    int n;
    cin>>n;

    for(int i=0; i<n; i++)cin>>cost[i];

    int e;
    cin>>e;

    while(e--) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    used.assign(n+5, false);

    for (int i = 1; i <= n; i++){
        if (!used[i]){
            dfs1(i);
        }
    }

    used.assign(n+5, false);
    reverse(order.begin(), order.end());

    long long way=1, ans=0;
    for (auto v : order){
        if (!used[v]) {
            dfs2 (v);
            ans+=(*st.begin());
            way*=mp[*st.begin()];
            way%=MOD;
            mp.clear();
            st.clear();
            component.clear();
        }
    }
    cout<<ans<<" "<<way<<"\n";
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
