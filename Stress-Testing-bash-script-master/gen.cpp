#include <bits/stdc++.h>

using namespace std;

#define int long long
#define accuracy chrono::steady_clock::now().time_since_epoch().count()
#define rep(i,a,n) for (int i = a; i <= n; ++i)

const int N = 1e6 + 4;

int32_t permutation[N];

mt19937 rng(accuracy);

int rand(int l, int r){
  uniform_int_distribution<int> ludo(l, r);
  return ludo(rng);
}

signed main() {
  srand(accuracy);
  int n = rand(1, 1000), k = 1;
  cout << n << " " << k << "\n";
  for(int i = 0; i < n; i++){
    cout << rand(0, 1000) << " ";
  }
  cout << "\n";
  int u = rand(0, 1000), v = rand(0, 1000);
  cout << u << " " << v << "\n";
}

