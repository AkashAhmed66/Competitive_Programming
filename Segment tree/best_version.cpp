#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long N=2e5 + 10;
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

    void propagate(int u, int st, int ed, int val){
        /// update u values during propagation (lazy)
        tree[u].mn += val;
        tree[u].mx += val;
        int v = u * 2, w = v + 1;
        if(st != ed){
            lazy[v] = val;
            lazy[w] = val;
        }
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

    void updateRange(int u, int st, int ed, int l, int r, int val){
        if(lazy[u] != -1){
            propagate(u, st, ed, lazy[u]);
            lazy[u] = -1;
        }

        if(st > ed || st > r || ed < l) return;

        if(st >= l && ed <= r){
            propagate(u, st, ed, val);
            return;
        }

        int mid = (st + ed) / 2;
        int v = u * 2, w = v + 1;

        updateRange(v, st, mid, l, r, val);
        updateRange(w, mid + 1, ed, l, r, val);

        tree[u] = Merge(tree[v], tree[w]);
    }

    Node queryRange(int u, int st, int ed, int l, int r){
        if(st > ed || st > r || ed < l) {
            return Node();
        }

        if(lazy[u] != -1){
            propagate(u, st, ed, lazy[u]);
            lazy[u] = -1;
        }

        if(st >= l && ed <= r) return tree[u];

        int mid = (st + ed) / 2;
        int v = u * 2, w = v + 1;

        Node p1 = queryRange(v, st, mid, l, r);
        Node p2 = queryRange(w, mid + 1, ed, l, r);

        return Merge(p1, p2);
    }
    void update(int u, int st, int ed, int idx, int val){
        if(st == ed){
            /// change updated value accordingly (point)
            A[idx] = val;
            tree[u].mn = val;
            tree[u].mx = val;
            tree[u].sum = val;
        }else{
            int mid = (st + ed) / 2;
            int v = u * 2, w = v + 1;

            if(st <= idx and idx <= mid){
                update(v, st, mid, idx, val);
            }else{
                update(w, mid+1, ed, idx, val);
            }

            tree[u] = Merge(tree[v], tree[w]);

        }
    }
    Node query(int u, int st, int ed, int l, int r){
        if(r < st || ed < l){
            return Node();
        }
        if(l <= st && ed <= r){
            return tree[u];
        }
        int mid = (st + ed) / 2;
        int v = u * 2, w = v + 1;
        Node p1 = query(v, st, mid, l, r);
        Node p2 = query(w, mid+1, ed, l, r);
        return Merge(p1, p2);
    }
};
void solve() {
    int n, q;
    cin >> n >> q;

    segment_tree seg(n);
    for(int i = 0; i < n; i++){
        cin >> seg.A[i];
    }
    seg.build(1, 0, n - 1);

    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int idx, v;
            cin >> idx >> v;
            seg.update(1, 0, n - 1, idx, v);
        }else{
            int l, r;
            cin >> l >> r;

            cout << seg.query(1, 0, n - 1, l, r - 1).sum << "\n";
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
