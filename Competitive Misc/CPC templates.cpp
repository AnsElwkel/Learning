#include <bits/stdc++.h>
#include <unordered_map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ull unsigned long long
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())
#define sz(v) ((int)((v).size()))
#define INF 1000000000
#define INFLL 1000000000000000000
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int MAX =1003, MOD = 5;

ll fastPow(ll base , ll power , ll mod = LLONG_MAX){
    if(base == 0) return 0;
    ll ret = 1;
    while(power > 0){
        if(power & 1) ret = ((ret % mod) * (base % mod)) % mod;
        base= ((base % mod) * (base % mod)) % mod;
        power = (power >> 1LL);
    }

    return ret % mod;
}

ll GCD(ll a , ll b){ return( a == 0 ? b :  GCD(b % a , a) ) ; }
ll LCM(ll a,ll b){ return (a * b) / GCD(a , b); }
ll multi(ll a, ll b , ll mod = LLONG_MAX){ return ((a%mod)*(b%mod))%mod; }
ll add(ll a, ll b , ll mod = LLONG_MAX)  { return ((a%mod)+(b%mod))%mod; }
ll sub(ll a, ll b , ll mod = LLONG_MAX)  { return ((a%mod)-(b%mod) + mod)%mod; }
ll inv(ll a, ll mod){return fastPow(a , mod - 2 , mod) ;}//IFF mod is prime

//Pre nCr , nPr
/*
int fact[MAX+1] , invFact[MAX+1];
void pre(){
    fact[0] = 1;
    int i = 1;
    for(;i <= MAX; i++) fact[i] = multi(fact[i-1] , i , MOD);
    --i;
    invFact[i] = inv(fact[i] , MOD);
    --i;
    for(;i>-1;--i) invFact[i]=multi(invFact[i+1] , i+1 , MOD);
}
ll nPr(ll n , ll r){
    if(r > n || n < 0 || r < 0) return 0;//invalid cases
    return multi(fact[n] , invFact[n-r] ,MOD);

}
ll nCr(ll n , ll r){
    if(r > n || n < 0 || r < 0) return 0;//invalid cases
    return multi(nPr(n , r),invFact[r] , MOD);
}
*/

//Seive
/*
 * vector<bool> prime (n + 1, true);
void sieve(int n)
{
    prime[0] = prime[1] = false;
    for (int i = 2; i <= n; i++)
        for (int j = i * i; j <= n && prime[i] && i * 1ll * i <= n; j += i)
            prime[j] = false;
}
 */

//SPF
/*
vector<int>spf (MAX) ;
void preSPF () {
    iota(all(spf) , 0);
    for(int i = 2; i * i <= MAX ; i++){
        if(spf[i] == i)
            for(int j = i*i ; j*j <= MAX ; j+=i)
                spf[j] = min(spf[j] , i);
    }
}
*/


//Solve Ax + By = C
/*
bool findAnySolution(int a, int b, int c, int &x, int &y, int &g) {
    g = eGCD(abs(a), abs(b), x, y);
    if (c % g)
        return 0;
    x *= c / g;
    y *= c / g;
    if (a < 0)
        x *= -1;
    if (b < 0)
        y *= -1;
    return 1;
}
void shiftSolution(int &x, int &y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}
int findAllSolutions(int a, int b, int c, int mnX, int mxX, int mnY, int mxY) {
    int x, y, g;
    if (!findAnySolution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;
    int signA = a > 0 ? 1 : -1;
    int signB = b > 0 ? 1 : -1;
    shiftSolution(x, y, a, b, (mnX - x) / b);
    bf.md 2024-07-22
    66 / 150
    if (x < mnX)
        shiftSolution(x, y, a, b, signB);
    if (x > mxX)
        return 0;
    int lx1 = x;
    shiftSolution(x, y, a, b, (mxX - x) / b);
    if (x > mxX)
        shiftSolution(x, y, a, b, -signB);
    int rx1 = x;
    shiftSolution(x, y, a, b, -(mnY - y) / a);
    if (y < mnY)
        shiftSolution(x, y, a, b, -signA);
    if (y > mxY)
        return 0;
    int lx2 = x;
    shiftSolution(x, y, a, b, -(mxY - y) / a);
    if (y > mxY)
        shiftSolution(x, y, a, b, signA);
    int rx2 = x;
    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);
    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}
*/

//Long Division
/*
string longDivision(string num, ll divisor){
    string ans;
    ll idx = 0;
    ll temp = num[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (num[++idx] - '0');
    while (num.size() > idx) {
        ans += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + num[++idx] -
               '0';
    }
    if (ans.length() == 0)
        return "0";
    return ans;
}
*/

/* Segment Tree */
//- Size of SegmentTree is power of two
//- Updating element in log(n)
//- Process query in log(n)
//1-sum query
/*
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
 */

void solve(){

}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr);
    int t ;
//    cin >> t;
    while(t--){
        solve();
    }
}