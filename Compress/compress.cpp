#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void compress(vector<int> &a) {
    auto b = a;
    sort(b.begin(), b.end());

    b.erase(unique(b.begin(), b.end()), b.end());

    for (auto &ai : a) {
        ai = lower_bound(b.begin(), b.end(), ai) - b.begin();
    }
}

void solve(){
    int n;
    cin >> n;

    vector<int> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }

    compress(x);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++){
        //cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}
