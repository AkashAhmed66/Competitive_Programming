#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const long long N=5e5 + 10;
const long long MOD=1e9 + 7;
const long long INF=1e6 + 2;
class Trie{
public :
    class Node{
    public:
        bool end;
        Node* next[26];
        Node(){
            end=false;
            for(int i=0; i<26; i++){
                next[i]= NULL;
            }
        }
    };
    Node* trie;
    Trie(){
        trie = new Node();
    }
    void insert(string s){
        int i=0;
        Node* it = trie;
        while(i<s.size()){
            if(it->next[s[i]-'a'] == NULL){
                it->next[s[i]-'a'] = new Node();
            }
            it = it->next[s[i]-'a'];
            i++;
        }
        it->end=true;
    }
    bool search(string s){
        int i=0;
        Node* it = trie;
        while(i<s.size()){
            if(it->next[s[i]-'a'] == NULL){
                return false;
            }
            it = it->next[s[i]-'a'];
            i++;
        }
        if(it->end == true) return true;
        else return false;
    }

};
void solve(){
    Trie *trie = new Trie();

    trie->insert("akash");
    trie->insert("akram");

    if(trie->search("akram")){
        cout<<"found\n";
    }else {
        cout<<"not found\n";
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
