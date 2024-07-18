//Unweighted graph   the shortest path algorithm

void BFS(int s){
    bool vis[N]{};
    vector<int> dist(N,0);
    queue<int> pq; //node
    pq.push( s);//source
    vis[s]=1;
    dist[s]=0;

    while(sz(pq)){
        int node;
        node= pq.front();
        for(auto u : adj[node]){
            if(vis[u])continue;
            vis[u]=1;
            dist[u]=dist[node]+1;
            pq.push(u);
        }
    }
}