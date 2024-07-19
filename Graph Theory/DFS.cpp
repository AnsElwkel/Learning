void DFS(int s){ //Recursive algorithm
    if(vis[s]) return;
    vis[s]=1;
    //process
    for(auto i : adj[s]){
        dfs(i);
    }
}

/*
 * Application :
 * 1- Connected component
 * int cnt=0;
 * for(int i=0;i<n;i++)
 * if(!vis[i])cnt++ , dfs(i);
 *
 * 2- Flood fill
 * 3- Topological sort
 */
//Bipartite check
//void DFS(int s , int color = 0){ //Recursive algorithm
//    if(vis[s]) return;
//    vis[s]=1;
//    //process
//    for(auto i : adj[s]){
//        dfs(i , color ^ 1);
//    }
//}