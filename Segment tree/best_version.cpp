#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long N=2e5 + 10;
string s;
struct Node{
    /// define the node and initialize (must)
    short cur;
    vector<int> chr;
    Node(){
        chr.resize(26, 0);
        cur = -1;
    }
};
struct segment_tree{

    vector<Node> tree;
    vector<short> lazy;

    segment_tree(int n){
        tree.resize(4 * n);
        lazy.resize(4 * n, -1);
    }

    Node Merge(Node l, Node r){
        Node ans = Node();
        /// merge the left and right node (must)
        ans.cur = max(l.cur, r.cur);
        for(int i = 0; i < 26; i++){
            ans.chr[i] = l.chr[i] + r.chr[i];
        }
        return ans;
    }

    void propagate(int node, int start, int endd, int val){
        /// update node values during propagation (lazy)
        tree[node].cur = val;
        for(int i = 0; i < 26; i++) tree[node].chr[i] = 0;
        tree[node].chr[val] += (endd - start + 1);
        if(start != endd){
            lazy[node*2] = val;
            lazy[node*2+1] = val;
        }
    }

    void build(int node, int start, int endd){
       if(start == endd){
            /// initialize with the leaf values (must)
            tree[node].cur = s[start] - 'a';
            tree[node].chr[s[start] - 'a']++;
        }else{
            int mid = (start + endd) / 2;

            build(2*node, start, mid);
            build(2*node+1, mid+1, endd);

            tree[node] = Merge(tree[2*node], tree[2*node+1]);
        }
    }

    void updateRange(int node, int start, int endd, int l, int r, int val){
        if(lazy[node] != -1){
            propagate(node, start, endd, lazy[node]);
            lazy[node] = -1;
        }

        if(start > endd || start > r || endd < l) return;

        if(start >= l && endd <= r){
            propagate(node, start, endd, val);
            return;
        }

        int mid = (start + endd) / 2;

        updateRange(node*2, start, mid, l, r, val);
        updateRange(node*2 + 1, mid + 1, endd, l, r, val);

        tree[node] = Merge(tree[node*2], tree[node*2+1]);
    }

    Node queryRange(int node, int start, int endd, int l, int r){
        if(start > endd || start > r || endd < l) {
            return Node();
        }

        if(lazy[node] != -1){
            propagate(node, start, endd, lazy[node]);
            lazy[node] = -1;
        }

        if(start >= l && endd <= r) return tree[node];

        int mid = (start + endd) / 2;

        Node p1 = queryRange(node*2, start, mid, l, r);
        Node p2 = queryRange(node*2 + 1, mid + 1, endd, l, r);

        return Merge(p1, p2);
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    cin >> s;
    segment_tree seg(n + 1);
    seg.build(1, 0, n - 1);

    while(q--){
        int l, r, k;
        cin >> l >> r >> k;
        auto nod = seg.queryRange(1, 0, n - 1, l - 1, r - 1);
        if(k == 1){
            int lst = l - 1;
            for(int i = 0; i < 26; i++){
                if(nod.chr[i]){
                    seg.updateRange(1, 0, n - 1, lst, lst + nod.chr[i] - 1, i);
                }
                lst += nod.chr[i];
            }
        }else{
            int lst = l - 1;
            for(int i = 25; i >= 0; i--){
                if(nod.chr[i]){
                    seg.updateRange(1, 0, n - 1, lst, lst + nod.chr[i] - 1, i);
                }
                lst += nod.chr[i];
            }
        }
    }
    for(int i = 0; i < n; i++){
        auto nod = seg.queryRange(1, 0, n - 1, i, i);
        cout << char(nod.cur + 'a');
    }
    cout << "\n";
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
