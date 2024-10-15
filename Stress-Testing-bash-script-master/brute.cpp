#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, q;
    cin >> n >> q;
    int x[n], mx = -1;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        mx = max(mx, x[i]);
    }

    while(q--){
        int u, v;
        cin >> u >> v;
        if(mx < u){
            cout << "No\n";
            return;
        }
        int i = 0;
        for(; i < n; i++){
            if(x[i] >= u){
                break;
            }
        }
        if(v == u){
            cout << "Yes\n";
        }else if(v > u){
            for(; i < n; i++){
                if(x[i] >= v){
                    cout << "Yes";
                    return;
                }
            }
            cout << "No\n";
        }else{
            for(; i < n; i++){
                if(x[i] <= v){
                    cout << "Yes";
                    return;
                }
            }
            cout << "No\n";
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
