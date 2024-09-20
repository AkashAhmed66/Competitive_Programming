#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const long long N = 1e5 + 10;

vector<int> g[N];
vector<ll> sz(N), heavy_child(N, -1), color(N), tot(N), cnt(N), ans(N);
ll sum = 0;

void dfs(ll u, ll p){
    sz[u] = 1;
    for(auto v : g[u]){
        if(v == p)continue;
        dfs(v, u);

        sz[u] += sz[v];

        if(heavy_child[u] == -1 || sz[v] > sz[heavy_child[u]]){
            heavy_child[u] = v;
        }
    }
}

void add(ll u, ll p, ll val){
    sum -= cnt[color[u]] * (tot[color[u]] - cnt[color[u]]);
    cnt[color[u]] += val;
    sum += cnt[color[u]] * (tot[color[u]] - cnt[color[u]]);


    for(auto v : g[u]){
        if(v == p) continue;
        add(v, u, val);
    }
}

void dsu(ll u, ll p, ll keep){
    for(auto v : g[u]){
        if(v == p) continue;
        if(heavy_child[u] == v) {
            continue;
        }
        dsu(v, u, 0);
    }

    if(heavy_child[u] != -1){
        dsu(heavy_child[u], u, 1);
    }

    for(auto v : g[u]){
        if(v == p || heavy_child[u] == v) continue;
        add(v, u, 1);
    }


    if(keep == 0){
        add(u, p, -1);
    }
}
void solve() {
    ll n;
    cin >> n;

    for(ll i = 0; i < n; i++){
        cin >> color[i];
    }
    for(ll i = 1; i < n; i++){
        ll u, v;
        cin >> u >> v;

        u--;
        v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, -1);
    dsu(0, -1, 0);

    for(ll i = 1; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    //cin>>t;

    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}
