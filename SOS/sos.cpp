#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

const long long MAX = 1e5;

const ll MLOG = 20;
const ll MAXN = (1<<MLOG);


void subset(vector<ll> &dp){ /// number of subsets of i
	for(ll bit = 0; bit < MLOG; bit++){
        for(ll i = 0; i<MAXN; i++){
            if(i&(1<<bit)){
                dp[i]+=dp[i^(1<<bit)];
            }
        }
	}
}
void remove_subs(vector<ll> &dp){ /// removing subsets
	for(ll bit = 0; bit < MLOG; bit++){
        for(ll i = MAXN-1; i>=0; i--){
            if(i&(1<<bit)){
                dp[i]-=dp[i^(1<<bit)];
            }
        }
	}

}
void superset(vector<ll> &dp){ /// number of super set of i
	for(ll bit = 0; bit < MLOG; bit++){
        for(ll i = MAXN-1; i>=0; i--){
            if(i&(1<<bit)){
                dp[i^(1<<bit)]+=dp[i];
            }
        }
	}
}
void remove_supers(vector<ll> &dp){ /// removing supersets
	for(ll bit = 0; bit < MLOG; bit++){
        for(ll i = 0; i<MAXN; i++){
            if(i&(1<<bit)){
                dp[i^(1<<bit)]-=dp[i];
            }
        }
	}
}
void all_subset(){ /// O(3^n)
    for(int i = 1; i < (1 << n); i++) {
      for(int j = i; j > 0; j = ((j - 1) & i)) {
          f[i] = min(f[i], f[i ^ j] + f[j]);
      }
    }
}
void solve(){
    ll n;
    cin>>n;
    vector<ll> freq1(MAXN, 0), freq2(MAXN, 0);
    ll x[n];
    for(ll i=0; i<n; i++){
        cin>>x[i];
        freq1[x[i]]++;
        freq2[x[i]]++;
    }
    subset(freq1);
    superset(freq2);
    for(ll i=0; i<n; i++){
        ll t = x[i];

        ll ans1 = freq1[t];
        ll ans2 = freq2[t];
        ll ans3 = n - freq1[(MAXN - 1) ^ t];

        cout<<ans1<<" "<<ans2<<" "<<ans3<<"\n";
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
