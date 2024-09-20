#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const long long N=5e5 + 10;
const long long MOD=1e9 + 7;
const long long INF=1e18;

bool check(int mid){
    return true;
}
void solve(){
    /// binary search for array
    int x[10]={1,2,3,4,5,6,7,8,9,10};
    int i=0 ,j=9;
    while(i<j){
        int mid=(i+j)/2;
        if(x[mid] < 10){
            i=mid+1;
        }else{
            j=mid;
        }
    }
    cout<<x[j]<<"\n";

    /// min binary search
    int i=0 ,j=9;
    while(i<j){
        int mid=(i+j)/2;
        if(check(mid)){
            j=mid;
        }else{
            i=mid+1;
        }
    }
    cout<<i<<"\n";

    ///max binary search
    i=0,j=9+1;
    while(i+1<j){
        int mid=(i+j)/2;
        if(check(mid)){
            i=mid;
        }else{
            j=mid;
        }
    }
    cout<< i<<"\n";

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
