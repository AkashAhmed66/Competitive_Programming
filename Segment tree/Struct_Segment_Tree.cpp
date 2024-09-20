#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const long long N = 2e5 + 10;

struct Segment_Tree{

    int seg[N * 4]{}, lazy[N * 4]{};

    void build(int node, int st, int ed, vector<int> &A){
       if(st == ed){
            seg[node] = A[st];
        }else{
            int mid = (st + ed) / 2;
            build(2*node, st, mid, A);
            build(2*node+1, mid+1, ed, A);
            seg[node] = seg[2*node] + seg[2*node+1];
        }
    }

    void update(int node, int st, int ed, int idx, int val, vector<int> &A){
        if(st == ed){
            A[idx] += val;
            seg[node] += val;
        }else{
            int mid = (st + ed) / 2;
            if(st <= idx and idx <= mid){
                update(2*node, st, mid, idx, val, A);
            }else{
                update(2*node+1, mid+1, ed, idx, val, A);
            }

            seg[node] = seg[2*node] + seg[2*node+1];
        }
    }

    int query(int node, int st, int ed, int l, int r){
        if(r < st || ed < l){
            return 0;
        }
        if(l <= st && ed <= r){
            return seg[node];
        }
        int mid = (st + ed) / 2;
        int p1 = query(2*node, st, mid, l, r);
        int p2 = query(2*node+1, mid+1, ed, l, r);
        return (p1 + p2);
    }

    void updateRange(int node, int st, int ed, int l, int r, int val){
        if(lazy[node] != 0){
            seg[node] += (ed - st + 1) * lazy[node];
            if(st != ed){
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if(st > ed || st > r || ed < l) return;
        if(st >= l && ed <= r){
            seg[node] += (ed - st + 1) * val;
            if(st != ed){
                lazy[node*2] += val;
                lazy[node*2+1] += val;
            }
            return;
        }
        int mid = (st + ed) / 2;
        updateRange(node*2, st, mid, l, r, val);
        updateRange(node*2 + 1, mid + 1, ed, l, r, val);
        seg[node] = seg[node*2] + seg[node*2+1];
    }

    int queryRange(int node, int st, int ed, int l, int r){

        if(st > ed || st > r || ed < l) return 0;

        if(lazy[node] != 0){
            seg[node] += (ed - st + 1) * lazy[node];
            if(st != ed){
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
            }
            lazy[node] = 0;
        }

        if(st >= l && ed <= r) return seg[node];

        int mid = (st + ed) / 2;

        int p1 = queryRange(node*2, st, mid, l, r);
        int p2 = queryRange(node*2 + 1, mid + 1, ed, l, r);

        return (p1 + p2);
    }
};
void solve() {

}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    for(int i=1; i<=t; i++){
        //cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}
