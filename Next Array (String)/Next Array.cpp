#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long N=5e5 + 10;
const long long MOD=1e9 + 7;;
const long long INF=1e18 + 2;

void solve() {
    int n;
    cin>>n;
    string s[n];
    int lenght_max_string=101;
    int nxt[n][lenght_max_string][26];
    for(int i=0; i<n; i++){
        cin>>s[i];
        string t=s[i];
        int sz=t.size();
        t=" "+t;
        // 0 is not representing any position just the starting point;
        for(int j=sz+1; j>=1; j--){
            if(j==sz+1){
                for(int c=0; c<26; c++){
                    nxt[i][j-1][c]=-1;
                }
            }else{
                for(int c=0; c<26; c++){
                    nxt[i][j-1][c]=nxt[i][j][c];
                }
                int nw=t[j]-'a';
                nxt[i][j-1][nw]=j;
            }
        }
    }
    ll ans[26][26][26];
    memset(ans, -1, sizeof ans);
    for(int c1=0; c1<26; c1++){
        for(int c2=0; c2<26; c2++){
            for(int c3=0; c3<26; c3++){
                for(int i=0; i<n; i++){
                    int cur=0;
                    if(nxt[i][cur][c1] != -1){
                        cur=nxt[i][cur][c1];
                        if(nxt[i][cur][c2] != -1){
                            cur=nxt[i][cur][c2];
                            if(nxt[i][cur][c3] != -1){
                                cur=nxt[i][cur][c3];
                                ans[c1][c2][c3]=i;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    int q;
    cin>>q;
    while(q--){
        string p;
        cin>>p;
        ll a=p[0]-'A';
        ll b=p[1]-'A';
        ll c=p[2]-'A';
        if(ans[a][b][c] == -1){
            cout<<"Not found\n";
        }else{
            cout<<s[ans[a][b][c] ]<<"\n";
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
