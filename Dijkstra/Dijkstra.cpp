#include <bits/stdc++.h>
using namespace std;

const long long N = 5e5 + 10;
const long long INF = 1e9;

vector<pair<int,int> > g[N];
vector<int> dis(N, INF);

void dijkstra(int source){
    dis[source] = 0;
    priority_queue<pair<int,int>, vector< pair<int, int> >, greater<pair<int, int> > > pq;
    dis[source] = 0;
    pq.push({0, source});
    while(pq.size() >0){

        auto node = pq.top();
        pq.pop();

        int w = node.first;
        int u = node.second;

        if(dis[u] != w_u)continue;

        for(auto child : g[u]){

            int v = child.first;
            int w_v = child.second;


            if(dis[v] > w + w_v){

                dis[v] = w + w_v;
                pq.push({dis[v], v});

            }
        }
    }
}

int main(){
    int n, e;
    cin >> n >> e;
    while(e--){
        int x, y, wt;
        cin >> x >> y >> wt;
        g[x].push_back({y, wt});
    }
    dijkstra(1);
    for(int i = 1; i <= n; i++){
        cout << dis[i] << " ";
    }
    return 0;
}
