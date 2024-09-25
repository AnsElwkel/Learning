#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define __ELWKEL__ ios_base::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr);
#define testCase int t;cin>>t;while(t--)
#define ll long long
#define ull unsigned long long
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())
#define sz(v) ((int)((v).size()))
#define INF 1000000000
#define INFLL 1000000000000000000
using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N = 1, MAX = 1e5 + 6, MOD = 1073741824;
const double EPS = 1e-8, PI = 2 * acos(0.0);
const int N = 1e5 + 5;
int n , a[N] , dp[101][3];

/*
 * given array ,,, want segment contain max sum , min , max and in this segment exist some op , wa hacaza
 * represent each indx 000000000000
 * 0 -> lsa maft7tesh segment
 * 1 -> fat7t segment wa ha5od
 * 2 -> 2falt el segment
 *000001111222
 * x1<-xxxxxyyyyxxx -> x2
 * x1 -> x1 or x1 -> y or (x1 -> x2 (empty segment))
 * y -> y or y -> x2
 * x2 -> x2
 */

// int f(int idx = 0, int type = 0) {
//     int &ret = dp[idx][type];
//     if(type == 0) {
//         ret = max(ret , f(idx + 1 , 0)); // lesa zy mana
//         ret = max(ret , f(idx , 1)); // ana 2ba y
//         // ret = max(ret , f(idx , 2)); // ana 2ba x2 // hena ana lma adkhol el foqy hyrooh ye garab ,,, ya3mny mlhash lazma
//     }
//     if(type == 1) {
//         ret = max(ret , f(idx + 1, 1) + a[idx]);
//         ret = max(ret , f(idx, 2) + a[idx]);
//     }
//     if(type == 2) {
//         ret = max(ret , f(idx + 1 , 2));
//     }
// }
int f(int i = 0 , int type = 0) {


}


void solve() {
    memset(dp , -1 , sizeof dp);
    cin >> n;
    for(int i=0;i<n;i++) {

    }

}

int32_t main() {
    //freopen("input", "rt", stdin);
    __ELWKEL__

    // testCase
    solve();
}
