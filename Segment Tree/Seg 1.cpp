- Size of SegmentTree is power of two
- Updating element in log(n)
- Process query in log(n)

#define ll long long
struct segmentTee{
private:
#define L 2*node+1
#define R 2*node+2
#define mid ((l + r)>>1)
    int sz;
    vector<ll> seg;
    void build(int l , int r , int node , vector<ll>&arr){//build the segTree
        if(l==r){ // leaf
            if(l<arr.size())
                seg[node]=arr[l];
            return;
        }

        build(l , mid , L , arr); // Build left
        build(mid+1 , r , R , arr); // Build right
        seg[node] = seg[L]+seg[R];
    }

    void update(int l, int r, int node, int idx, ll val){ // Update element in segTree
        if(l==r){ // Reach leaf
            seg[node]=val;
            return;
        }

        if(idx <= mid) //Check if node that you want update left or right
            build(l , mid , L , idx , val);
        else
            build(mid+1 , r , R , idx , val);

        seg[node]=seg[L]+seg[R];
    }

    ll query(int l, int r , int node , int lq , int rq){
        if(lq > r || rq < l) return 0;
        if(rq <= r && lq >= l) return seg[node];
        ll left = query(l , mid , L , lq , rq);
        ll right = query(mid + 1 , r , R , lq , rq);
        return left + right;
    }

public:
    segmentTee(vector<int>& arr){
        sz=1;
        int n = arr.size();
        while(sz < n) sz<<1;
        seg=vector<ll>(sz*2);
        build(0 , sz-1 , 0);// node 0 is top carry complete range (0->sz-1)
    }
    void update(int idx , int val){ //Update element (Call in main)
        update(0 , sz-1 , 0 , idx , val);
    }

    ll query(int lq , int rq){ //Ask about sum of range(Call in main)
        return query(0 , sz-1 , 0 , lq , rq);
    }

#undef L
#undef R
#undef mid
};