#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
    /// define the node and initialize (must)
    ll mn, mx, sum;
    Node(){
        mn = 1e9, mx = 0, sum = 0;
    }
};
struct segment_tree{

    vector<Node> tree;
    vector<ll> lazy, A;

    segment_tree(int n){
        tree.resize(4 * n);
        lazy.resize(4 * n, -1);
        A.resize(4 * n, 0);
    }

    Node Merge(Node l, Node r){
        Node ans = Node();
        /// merge the left and right node (must)
        ans.mn = min(l.mn, r.mn);
        ans.mx = max(l.mx, r.mx);
        ans.sum = l.sum + r.sum;
        return ans;
    }
    void build(int u, int st, int ed){
       if(st == ed){
            /// initialize with the leaf values (must)
            tree[u].mn = A[st];
            tree[u].mx = A[st];
            tree[u].sum = A[st];
        }else{
            int mid = (st + ed) / 2;
            int v = u * 2, w = v + 1;

            build(v, st, mid);
            build(w, mid+1, ed);

            tree[u] = Merge(tree[v], tree[w]);
        }
    }
    int mx_query(int u, int st, int ed, int val){
        if(st == ed){
            return st;
        }
        int mid = (st + ed) / 2;
        int v = u * 2, w = v + 1;
        if(tree[v].mx >= val){
            mx_query(v, st, mid, val);
        }else{
            mx_query(w, mid + 1, ed, val);
        }
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    int x[n], mx[n], mn[n];
    segment_tree seg(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        seg.A[i] = x[i];
    }
    seg.build(1, 0, n - 1);
    mx[n - 1] = mn[n - 1] = x[n - 1];
    for(int i = n - 2; i >= 0; i--){
        mx[i] = max(mx[i + 1], x[i]);
        mn[i] = min(mn[i + 1], x[i]);
    }

    while(q--){
        int u, v;
        cin >> u >> v;
        if(mx[0] < u){
            cout << "No\n";
            continue;
        }
        if(u == v) {
            cout << "Yes\n";
            continue;
        }
        int idx = seg.mx_query(1, 0, n - 1, u);
        if(v > u){
            if(mx[idx] >= v){
                cout << "Yes\n";
            }else{
                cout << "No\n";
            }
        }else{
            if(mn[idx] <= v){
                cout << "Yes\n";
            }else{
                cout << "No\n";
            }
        }
    }

}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
//    freopen("milk.in", "r", stdin);
    int t=1;
    //cin>>t;
    for(int i=1; i<=t; i++){
        //cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}
