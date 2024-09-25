struct segmentTee{
private:
#define L (2*(node)+1)
#define R (2*(node)+2)
#define mid ((l + r)>>1)
    struct Node{
        ll mn , cnt ;
        Node(){}
        Node(int val , int _cnt) : mn(val) , cnt(_cnt){}
    };

    Node merge(Node& a , Node& b){
        if(a.mn == b.mn)
            return Node(a.mn , a.cnt + b.cnt);
        else return a.mn < b.mn ? a : b;
    }

    int sz;
    vector<Node> seg;

    void build(int l , int r , int node , vector<ll>&arr){//build the segTree
        if(l==r){ // leaf
            if(l<arr.size())
                seg[node]=Node(arr[l], 1);
            return;
        }

        build(l , mid , L , arr); // Build left
        build(mid+1 , r , R , arr); // Build right
        seg[node] = merge(seg[L] , seg[R]);
    }

    void update(int l, int r, int node, int idx, ll val){ // Update element in segTree
        if(l==r){ // Reach leaf
            seg[node]=Node(val,1);
            return;
        }

        if(idx <= mid) //Check if node that you want update left or right
            update(l , mid , L , idx , val);
        else
            update(mid+1 , r , R , idx , val);

        seg[node]=merge(seg[L],seg[R]);
    }

    Node query(int l, int r , int node , int lq , int rq){
        if(lq > r || rq < l) return Node(INFLL ,1);
        if(r <= rq && l >= lq ) return seg[node];
        Node left = query(l , mid , L , lq , rq);
        Node right = query(mid + 1 , r , R , lq , rq);
        return merge(left , right);
    }

public:
    segmentTee(vector<ll>& arr){
        sz=1;
        int n = arr.size();
        while(sz < n) sz*=2;
        seg=vector<Node>(sz*2 , Node(INFLL , 1));
        build(0 , sz-1 , 0 ,arr);// node 0 is top carry complete range (0->sz-1)
    }
    void update(int idx , int val){ //Update element (Call in main)
        update(0 , sz-1 , 0 , idx , val);
    }

    pair<ll , ll >  query(int lq , int rq){ //Ask about sum of range(Call in main)
        Node ret = query(0 , sz-1 , 0 , lq , rq);
        return {ret.mn, ret.cnt};
    }

#undef L
#undef R
#undef mid
};
