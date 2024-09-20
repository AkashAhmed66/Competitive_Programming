
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const long long N = 2e5 + 10;
const long long inf = 1e17 + 10;


int merge(int arr[], int temp[], int left, int mid, int right)
{
    int inv_count = 0;

    int i = left;
    int j = mid;
    int k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];

            inv_count = inv_count + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i=left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left)
    {
        mid = (right + left)/2;

        inv_count  = _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid+1, right);

        inv_count += merge(arr, temp, left, mid+1, right);
    }

    return inv_count;
}

int countSwaps(int arr[], int n)
{
    int temp[n];
    return _mergeSort(arr, temp, 0, n - 1);
}

void solve(){
    int n;
    cin >> n;

    int a[n], b[n], t1[n], t2[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        t2[i] = a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        t1[i] = b[i];
    }
    sort(t1, t1 + n);
    sort(t2, t2 + n);
    for(int i = 0; i < n; i++){
        if(t1[i] != t2[i]){
            cout << "NO\n";
            return;
        }
    }

    int movea = countSwaps(a, n);
    int moveb = countSwaps(b, n);

    if(abs(movea - moveb) % 2 == 0){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}
