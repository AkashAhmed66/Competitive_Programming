#include "bits/stdc++.h"
using namespace std;

const int MAX = 5e5 + 5;
vector<long long> MOD = {127657753, 987654319};
vector<array<long long, 2>> pwr(MAX), ipwr(MAX);
array<long long, 2> bs = {137, 277};

long long bigMod(long long base, long long power, int m) {
  long long res = 1;
  while (power) {
    if (power & 1LL) {
      (res *= base) %= MOD[m];
    }
    (base *= base) %= MOD[m];
    power /= 2;
  }
  return res;
}

void Pre_Calculate() {
  pwr[0][0] = pwr[0][1] = 1;
  for (int i = 1; i < MAX; i++) {
    (pwr[i][0] = pwr[i - 1][0] * bs[0]) %= MOD[0];
    (pwr[i][1] = pwr[i - 1][1] * bs[1]) %= MOD[1];
  }
  ipwr[0][0] = ipwr[0][1] = 1;
  long long ip1 = bigMod(bs[0], MOD[0] - 2, 0);
  long long ip2 = bigMod(bs[1], MOD[1] - 2, 1);
  for (int i = 1; i < MAX; i++) {
    ipwr[i][0] = (ipwr[i - 1][0] * ip1) % MOD[0];
    ipwr[i][1] = (ipwr[i - 1][1] * ip2) % MOD[1];
  }
}

struct Hashing {
  int n;
  string s;
  vector<array<long long, 2>> hs;
  Hashing (string t) {
    n = t.size();
    s = t;
    hs.resize(n + 1);
    for (int i = 0; i < n; i++) {
      (hs[i + 1][0] = hs[i][0] + (pwr[i][0] * s[i]) % MOD[0]) %= MOD[0];
      (hs[i + 1][1] = hs[i][1] + (pwr[i][1] * s[i]) % MOD[1]) %= MOD[1];
    }
  }
  array<long long, 2> get_hash(int l, int r) {
    if (l > r) return {0, 0};
    long long res1 = ((hs[r][0] - hs[l - 1][0]) + MOD[0]) % MOD[0];
    long long res2 = ((hs[r][1] - hs[l - 1][1]) + MOD[1]) % MOD[1];
    (res1 *= ipwr[l - 1][0]) %= MOD[0];
    (res2 *= ipwr[l - 1][1]) %= MOD[1];
    return {res1, res2};
  }
  auto merge(array<long long, 2> left, array<long long, 2> right, int left_sz) {
    for (int i = 0; i < 2; i++) {
      (right[i] *= pwr[left_sz][i]) %= MOD[i];
      (left[i] += right[i]) %= MOD[i];
    }
    return left;
  };
};

void solve() {
  //create hash
  Hashing hsh(s);
  //get hash
  hsh.get_hash(1, s.size());
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  Pre_Calculate();
  cin >> t;
  for(int i = 1; i <= t; i++){
    solve();
  }
  return 0;
}
