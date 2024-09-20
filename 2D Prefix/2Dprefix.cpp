#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const long long N = 1e3 + 10;
int n, m, k;

vector<vector<int> > rot(vector<vector<int> > &matrix){
    vector<vector<int> > ans(m + 2, vector<int> (n + 2, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            ans[j][n - i + 1] = matrix[i][j];
        }
    }
    swap(n, m);
    return ans;
}

ll f(vector<vector<int> > &matrix){
    vector<vector<int> > pref(n + 2, vector<int> (m + 2, 0));
    vector<vector<int> > colsum(n + 2, vector<int> (m + 2, 0));
    vector<vector<int> > diagonalsum(n + 2, vector<int> (m + 2, 0));


    for(int i = n; i >= 1; i--){
        for(int j = m; j >= 0; j--){
            pref[i][j] = pref[i][j + 1] + pref[i + 1][j] - pref[i + 1][j + 1] + matrix[i][j];
        }
    }
    for(int i = n; i >= 1; i--){
        for(int j = m; j >= 1; j--){
            colsum[i][j] = matrix[i][j] + colsum[i + 1][j];
        }
    }
    for(int i = m; i >= 1; i--){
        diagonalsum[1][i] = diagonalsum[1][i + 1] + colsum[1][i];
    }
    for(int i = 2; i <= n + 1; i++){
        for(int j = m; j >= 1; j--){
            diagonalsum[i][j] = diagonalsum[i - 1][j + 1] + colsum[i][j];
        }
    }

    int mx = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int r = min(m + 1, j + k);
            int d = min(n + 1, i + k);
            int box = pref[i][j] - pref[i][r] - pref[d][j] + pref[d][r];

            int cut = k - (d - i);
            int rightdown = diagonalsum[d][min(j + cut, m + 1)] - diagonalsum[i][r] - pref[d][min(m + 1, j + cut)] + pref[d][r];

            mx = max(mx, box - rightdown);
        }
    }

    return mx;
}
void solve() {
    cin >> n >> m >> k;
    k++;

    vector<vector<int> > matrix(n + 2, vector<int> (m + 2, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char c;
            cin >> c;

            if(c == '#') matrix[i][j] = 1;
            else matrix[i][j] = 0;
        }
    }

    ll ans =  f(matrix);
    matrix = rot(matrix);
    ans = max(ans, f(matrix));
    matrix = rot(matrix);
    ans = max(ans, f(matrix));
    matrix = rot(matrix);
    ans = max(ans, f(matrix));

    cout << ans << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    cin>>t;

    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}
