#include <iostream>
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

/// Usage of ordered_set
/// order_of_key (k) : Number of items strictly smaller than k .
/// find_by_order(k) : K-th element in a set (counting from zero).

using namespace std;
using namespace __gnu_pbds;

template <typename num_t>
using ordered_set = tree<num_t,null_type, less<num_t>,rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;

const long long N = 2e5 + 10;
const long long inf = 1e6 + 10;

void solve(){
    int n;
    cin >> n;

    int x[n];

    for(int i = 0; i < n; i++){
        cin >> x[i];
    }

    ordered_set<array<int, 2> > st;
    map<ll, int> mp1, mp2;

    int t = 1;

    vector<int> pref(n), suff(n);

    for(int i = n - 1; i >= 0; i--){
        mp2[x[i]]++;
        suff[i] = mp2[x[i]];
        st.insert({suff[i], t++});
    }

    for(int i = 0; i < n; i++){
        mp1[x[i]]++;
        pref[i] = mp1[x[i]];    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        int cnt = suff[i];

        st.erase(st.lower_bound({cnt, 0}));

        int t = st.order_of_key({pref[i], 0});

        ans += t;
    }

    cout << ans << "\n";
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
