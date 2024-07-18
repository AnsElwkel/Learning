void DFS(int s){ //Recursive algorithm
    if(vis[s]) return;
    vis[s]=1;
    //process
    for(auto i : adj[s]){
        dfs(i);
    }
}