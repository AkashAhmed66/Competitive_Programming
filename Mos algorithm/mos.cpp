
#include<bits/stdc++.h>
using namespace std;
const long long N = 3e6 + 10;

int SQRT;
int x[N],query_ans[N],freq[N];

struct Q{
	int L,R,i;
}query[N];


bool cmp(Q a, Q b) {
	if (a.L/SQRT != b.L/SQRT) return a.L < b.L;
	return a.R < b.R;
}

int ans=0;
void add(int pos) {
	freq[x[pos]]++;
	if(freq[x[pos]]==1)
	ans++;
}

void remove(int pos) {
	freq[x[pos]]--;
	if(freq[x[pos]]==0)
	ans--;
}
/// one base indexing
void mos_algorithm(int q) {
	sort(query+1, query+1+q, cmp);
	int currentL = 0, currentR = 0, L, R;
	add(0);

	for(int i=1; i<=q; i++){
		L=query[i].L;
		R=query[i].R;

		while(currentL < L){
            remove(currentL++);
		}

		while(currentL > L){
            add(--currentL);
		}

		while(currentR < R){
            add(++currentR);
		}

		while(currentR > R){
            remove(currentR--);
		}

		query_ans[query[i].i]=ans;
	}
}

int main() {
    int n;
	cin >> n;
	SQRT = floor(sqrt(n));

	for(int i = 1; i <= n; i++) {
		cin >> x[i];
	}
    int q;
    cin>>q;

	for(int i = 1; i <= q; i++) {
        int l,r;
        cin>>l>>r;
		query[i].L = l;
		query[i].R = r;
		query[i].i = i;
	}

	mos_algorithm(q);

	for(int i=1; i<=q; i++){
        cout << query_ans[i] << "\n";
	}
	return 0;
}
