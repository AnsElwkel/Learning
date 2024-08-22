//Disjoint Union Set
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
