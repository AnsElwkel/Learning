/****************Floyed Warshall Algorithm****************
* memory -> O(n^2) , time -> O(n^3)
 *   it finds shortest
     paths between all node pairs of the graph in a single run.

 *   The algorithm maintains a matrix that contains distances between the nodes. The
     initial matrix is directly constructed based on the adjacency matrix of the graph.
     Then, the algorithm consists of consecutive rounds, and on each round, it selects a
     new node that can act as an intermediate node in paths from now on, and reduces
     distances using this node.
 */

int dist[N][N] ;
int adjMatrix[N][N]; // value is weight

void floyed() {
    for(int i = 0;i < N ; i ++) {// 0 - based
        for(int j = 0; j < N ; j++) {
            if(i == j) dist[i][j] = 0;
            else if(adjMatrix[i][j]) dist[i][j] = adjMatrix[i][j];
            else dist[i][j] = INF;
        }
    }

    //Find shortest path between all pairs of nodes
    for(int k = 0 ; k < N ; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N ; j++)
                dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
}
void push(int a , int b , int w) {
    --a,--b;
    adjMatrix[a][b] = w;
    adjMatrix[b][a] = w;
}
void solve() {
    push(2   , 3 ,2);
    push(4   , 3 ,7);
    push(4   , 3 ,7);
    push(4   , 5 ,2);
    push(4   , 1 ,9);
    push(4   , 1 ,9);
    push(5   , 1 ,1);
    push(2   , 1 ,5);
    floyed();
    for(int i = 0; i < N ; i++) {
        for(int j = 0; j < N ; j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }
}