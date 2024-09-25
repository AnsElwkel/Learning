#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
// Example on coordinate compression

// add here summary and notes from any chatbot about this technique
#define ll long long
class coordinateCompression{
    vector<ll> init;
    void compress(){
        sort(init.begin() ,init.end());
        init.erase(unique(init.begin() , init.end()) , init.end());
    }
public:
    coordinateCompression(const vector<ll>& arr){
        this->init = arr;
        compress();
    }

    ll index(ll val){
        return lower_bound(init.begin() , init.end() , val) - init.begin();
    }

    ll operator[] (int idx){
        return init[idx];
    }
};
//Problem name : Restaurant Customer on CF ... from sheet mahmoud ayman :)
int main(){
    int n; cin >> n;
    ll a[n] , b[n] ;
    vector<ll> v;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i] >> b[i];
        v.push_back(a[i]) , v.push_back(b[i]);
    }
    coordinateCompression co(v);
    //	sort(v.begin() , v.end());
    //	v.erase(unique(v.begin() , v.end()) , v.end());

    for(int i = 0 ; i < n;i++){
        a[i] = co.index(a[i]);
        b[i] = co.index(b[i]);

        //		a[i] = lower_bound(v.begin() , v.end() , a[i]) - v.begin();
        //		b[i] = lower_bound(v.begin() , v.end() , b[i]) - v.begin();
    }

    int N = 2e5 + 3;
    int part[N]{} ;
    for(int i = 0 ; i < n; i++){
        part[a[i]]++ , part[b[i] + 1]--;
    }
    for(int i = 1; i < n;i++)
        part[i] += part[i - 1];
    int ans = 0;
    for(auto i : part) ans = std::max(ans , i);
    cout << ans << el;
    //	for(int i = 0 ;i < n*2; i++)
    //		cout << co[i] << ' ';
}

/*
 3
 5 8
 2 4
 3 9
*/
