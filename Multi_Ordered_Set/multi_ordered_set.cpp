#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define multi_ordered_set tree<long long, null_type,less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set tree<long long, null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update>

/// Usage of ordered_set and multi_ordered_set
/// order_of_key (k) : Number of items strictly smaller than k .
/// find_by_order(k) : K-th element in a set (counting from zero).
/// acts like multi set with ordered_set properties

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

const long long N=2e5 + 10;
const long long MOD=1e9 + 7;;
const long long MODD = 998244353;
const long long INF=1e18 + 10;
const long long IINF=1e9 + 10;

bool Exist(multi_ordered_set &mst, ll key){
    if(mst.upper_bound(key) == mst.end())return 0;
    return (*(mst.upper_bound(key)) == key);
}

void Erase(multi_ordered_set &mst, ll key){
    if(Exist(mst, key)){
        mst.erase(mst.upper_bound(key));
    }
}

void solve(){
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
