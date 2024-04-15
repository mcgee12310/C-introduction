#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MaxN = 3000000;
const ll INF = 300000;

int n, m, s, t;
bool mark[MaxN];
ll dist[MaxN];
vector<pair<int, int>> adj[MaxN];

void Dijkstra(int s){
    fill(dist + 1, dist + n + 1, INF);
    dist[s] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll,int>>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(mark[u]) continue;
        mark[u] = true;
        for(auto e : adj[u]){
            int v = e.first;
            ll w = e.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < m ; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    cin >> s >> t;
    Dijkstra(s);
    
    if(dist[t] == INF) cout << -1 << endl;
    else cout << dist[t] << endl;

    return 0;
}
