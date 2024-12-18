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
        node= pq.front(); pq.pop();
        for(auto u : adj[node]){
            if(vis[u])continue;
            vis[u]=1;
            dist[u]=dist[node]+1;
            pq.push(u);
        }
    }
}

/*
 * Application
 * 1- check Bipartite
 */
void BFS(int s){
//    bool vis[N]{};
    vector<int> color(N,INF);
    queue<int> pq;pq.push(s);//source
    color[s]=0;
    bool isBipartite = 1;
    while(sz(pq) and isBipartite){
        int node = pq.front();
        for(auto u : adj[node]){
            if(color[u] == INF){
                color[u] = 1-color[node];
                pq.push(u);
            }else if(color[u]==color[node]){
                isBipartite=0;
                break;
            }
        }
    }
}
