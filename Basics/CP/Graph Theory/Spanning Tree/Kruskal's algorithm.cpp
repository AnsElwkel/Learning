/**
 * Kruskal's algorithm    O(n + m log m)
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
struct DSU{
    int n ;
    vector<int> parent , group , mx , mn;
    DSU(int _n){
        this->n = _n;
        mx = mn = parent = vector<int>(n+1);
        group = vector<int>(n+1 , 1);
        iota(parent.begin() , parent.end() , 0);
        mx = mn = parent;
    }

    int find(int u){//return leader ... leader node of group must be same value of his parent ( heya w el parent same)
        if(parent[u] == u)return u;
        return find(parent[u]);
    }
    bool same(int u, int v){//to check two node in same group or not
        return find(u) == find(v);
    }

    void merge(int u , int v){//to merge u's group (small group) with v's group
        int lead1 = find(u) , lead2 = find(v);
        if(lead1 == lead2) return;
        if(group[lead1] > group[lead2]) swap(lead1 , lead2);
        parent[lead1] = lead2;
        group[lead2] += group[lead1]; //increase size of group
        mx[lead2] = max(mx[lead2] , mx[lead1]); //max node in component
        mn[lead2] = min(mn[lead2] , mn[lead1]); //min node in component
    }

    //addition function (eg.get size of component , min , max)
    int get_size(int u){
        return group[find(u)];
    }
    int get_max(int u){
        return mx[find(u)];
    }
    int get_min(int u){
        return mn[find(u)];
    }
};

int n , m , k;
vector<pair<int , pair<int, int>>> edge;
int kruskal() {
    sort(all(edge)); // sort edges by weight
    DSU dsu(n);
    int sz = sz(edge) , minWeight = 0;
    for(int i = 0 ; i < sz ; i++) {
        auto [w , ed] = edge[i];
        if(!dsu.same(ed.first , ed.second)){
            minWeight += w ;
            dsu.merge(ed.first , ed.second);
        }
    }

    return minWeight ;
}
