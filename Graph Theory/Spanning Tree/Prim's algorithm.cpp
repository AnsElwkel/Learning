/**
* Prim's algorithm    O(n + m log m)
 * to find minimum and maximum spanning tree
 * spanning tree that structure from any undirected weighted connected graph
 * that contain exact nodes and n-1 edges that sum of weights minimal
 * sample :
    6  8
    5 6 2
    1 2 3
    3 6 3
    1 5 5
    2 3 5
    2 5 6
    4 6 7
    3 4 9
 * output:
 *   20
 */
int n , m;
vector<vector<pair<int , int>>> adj; // to  weight
bool vis[N];
int prim(int s) {
    priority_queue<pair<int, int>> pq; // weight to
    vis[s] = 1;
    for(auto i : adj[s]) {
        if(!vis[i.first]) pq.push({-i.second, -i.first});
    }
    int MSTcost = 0;
    while(!pq.empty()) {
        auto [w , u] = pq.top();
        u *= -1 , w *= -1;
        pq.pop();

        if(!vis[u]) {
            MSTcost += w;
            vis[u] = 1 ;
            for(auto i : adj[u]) {
                if(!vis[i.first]) {
                    pq.push({-i.second, -i.first});
                }
            }
        }
    }
    return MSTcost;
}

void solve() {
    cin >> n >> m ;
    adj.assign(n + 1 , vector<pair<int , int>>());
    for(int i = 0 ; i < m ; i++) {
        int u , v , w ;
        cin >> u >> v >> w ;
        adj[u].push_back({v , w});
        adj[v].push_back({u , w});
    }
    cout << prim(1) << "\n";
}
