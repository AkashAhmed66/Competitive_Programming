#include <bits/stdc++.h>

using namespace std;

const long long N = 1e5 + 100;

vector<int>g[N], tout(N), tin(N), dis(N);
int up[N][29], timer = 0;

void binary_lifting(int u, int p){
    tin[u] = ++timer;
    up[u][0]=p;
    for(int i=1; i <= 20; i++){
        up[u][i]=up[up[u][i-1]][i-1];
    }
    for(int v : g[u]){
        if(v == p)continue;
        dis[v] = dis[u] + 1;
        binary_lifting(v, u);
    }
    tout[u] = ++timer;
}

int kth_ancestor(int u, int k){
    if(u == 0 || k==0){
        return u;
    }
    for(int i=20; i>=0; i--){
        if(k >= (1<<i)){
            return kth_ancestor(up[u][i], k-(1<<i));
        }
    }
    return u;
}

bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = 20; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v)){
            u = up[u][i];
        }
    }
    return up[u][0];
}
void solution(){
    binary_lifting(1, 1); /// call(root, root)
}
int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solution();
    }
    return 0;
}
