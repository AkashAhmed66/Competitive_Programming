#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long N=5e5 + 10;
const long long MOD=1e9 + 7;;
const long long MODD = 998244353;
const long long INF=1e18 + 10;
const long long IINF=1e9 + 10;

int par[26]{},sz[26]{};

void Build(){
    for(int i=0; i<26; i++){
        par[i]=i;
        sz[i]=1;
    }
}

int Find(int x){
    if(par[x]==x)return x;
    else return par[x]=Find(par[x]);
}

void Union(int x, int y){
    x=Find(x);
    y=Find(y);
    if(x != y){
        if(sz[x]<sz[y]){
            swap(x,y);
        }
        par[y]=x;
        sz[x]+=sz[y];
    }
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> go(26, -1),come(26,-1);
    Build();
    for(int i=0; i<s.size(); i++){
        int x=s[i]-'a';
        if(go[x] != -1){
            cout<<(char)('a'+go[x]);
            continue;
        }
        for(int j=0; j<26; j++){
            if(come[j] != -1)continue;
            if(Find(x)==Find(j) && sz[Find(x)]<26)continue;
            Union(x,j);
            go[x]=j;
            come[j]=x;
            cout<<(char)('a'+j);
            break;
        }
    }
    cout<<"\n";
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
