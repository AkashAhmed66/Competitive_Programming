#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const int N = 5e5 + 5, T = 2;
vector<ll> mod = {127657753, 987654319};
array<ll, T> base = {137, 277};
vector<array<ll, T>> bpwr(N), ibpwr(N);

ll bigMod(ll b, ll p, ll m){
    if(p == 0)return 1LL ;
    ll ans = bigMod(b, p/2, m);
    ans = (ans * ans) % mod[m];
    if(p % 2 == 1){
        ans = (ans * b) % mod[m];
    }
    return ans;
}

void Pre_Calculate() {
  for(int i = 0; i < T; i++){
    bpwr[0][i] = 1;
  }
  for (int i = 1; i < N; i++) {
    for(int j = 0; j < T; j++){
      (bpwr[i][j] = bpwr[i - 1][j] * base[j]) %= mod[j];
    }
  }
  ll ip[T]{};
  for(int i = 0; i < T; i++){
    ibpwr[0][i] = 1;
    ip[i] = bigMod(base[i], mod[i] - 2, i);
  }
  for (int i = 1; i < N; i++) {
    for(int j = 0; j < T; j++){
        ibpwr[i][j] = (ibpwr[i - 1][j] * ip[j]) % mod[j];
    }
  }
}

struct Hashing {
  int n;
  string s;
  vector<array<ll, T>> hs;
  Hashing (string t) {
    n = t.size();
    s = t;
    hs.resize(n + 1);
    for (int i = 0; i < n; i++) {
      for(int j = 0; j < T; j++){
        (hs[i + 1][j] = hs[i][j] + (bpwr[i][j] * s[i]) % mod[j]) %= mod[j];
      }
    }
  }
  array<ll, T> get_hash(int l, int r) {
    if (l > r) return {0, 0};
    array<ll, T> res;
    for(int i = 0; i < T; i++){
      res[i] = ((hs[r][i] - hs[l - 1][i]) + mod[i]) % mod[i];
      (res[i] *= ibpwr[l - 1][i]) %= mod[i];
    }
    return res;
  }
  auto Merge(array<ll, T> l, array<ll, T> r, int l_sz) {
    for (int i = 0; i < T; i++) {
      (r[i] *= bpwr[l_sz][i]) %= mod[i];
      (l[i] += r[i]) %= mod[i];
    }
    return l;
  };
};

void solve() {
  string s;
  cin >> s;
  //create hash
  Hashing hsh(s);
  //get hash
  hsh.get_hash(1, s.size());
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  Pre_Calculate();
  //cin >> t;
  for(int i = 1; i <= t; i++){
    solve();
  }
  return 0;
}
