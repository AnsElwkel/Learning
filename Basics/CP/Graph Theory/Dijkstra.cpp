//When there are weighted graphs
//Is a shortest path algorithm

void dijkstra(int s){
    bool vis[N]{};
    vector<int> dist(N,INF);
    priority_queue<pair<int , int>> pq; // weight node
    pq.push({0 , s});//source
    vis[s]=1;

    dist[s]=0;
    while(sz(pq)){
        int node , weight;
        tie(weight , node) = pq.top();
        weight*=-1;// if we need this
        for(auto [u , w] : adj[node]){
            if(vis[u])continue;
            vis[u]=1;

            if(dist[node]+w<dist[u])
                dist[u]=dist[node]+w;
            pq.push({-dist[u], u});
        }
    }
}