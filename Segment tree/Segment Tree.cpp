#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long N=2e5 + 10;


vector<int> tree(4*N),A(4*N);
vector<int> lazy(4*N);

void build(int node, int start, int end){
   if(start == end){
        tree[node] = A[start];
    }else{
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
void update(int node, int start, int end, int idx, int val){
    if(start == end){
        A[idx] += val;
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
int query(int node, int start, int end, int l, int r){
    if(r < start || end < l){
        return 0;
    }
    if(l <= start && end <= r){
        return tree[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}
void updateRange(int node, int start, int end, int l, int r, int val){
    if(lazy[node] != 0){

        tree[node] += (end - start + 1) * lazy[node];
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > end || start > r || end < l) return;
    if(start >= l && end <= r){
        tree[node] += (end - start + 1) * val;
        if(start != end){
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);
    updateRange(node*2 + 1, mid + 1, end, l, r, val);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int queryRange(int node, int start, int end, int l, int r){

    if(start > end || start > r || end < l) return 0;

    if(lazy[node] != 0){
        tree[node] += (end - start + 1) * lazy[node];
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(start >= l && end <= r) return tree[node];

    int mid = (start + end) / 2;

    int p1 = queryRange(node*2, start, mid, l, r);
    int p2 = queryRange(node*2 + 1, mid + 1, end, l, r);

    return (p1 + p2);
}
void solve() {

    int n,q;
    cin>>n>>q;
    for(int i=0; i<=4*n; i++){
       tree[i]=lazy[i]= A[i]=0;
    }

    int x[n+5];

    for(int i=1; i<=n; i++){
        cin>>x[i];
    }
    build(1,1,n);

    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int l,r;
            cin>>l>>r;
            updateRange(1, 1, n, l, r, 1);
        }else{
            int p;
            cin>>p;
            ll op=queryRange(1, 1, n, p, p);
            int c=op;
            while(op--){
                if(x[p]<10){
                    break;
                }
                int sum=0;
                while(x[p]>0){
                    sum+=(x[p]%10);
                    x[p]/=10;
                }
                x[p]=sum;
            }
            updateRange(1, 1, n, p, p, -c);
            cout<<x[p]<<"\n";
        }
    }
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
