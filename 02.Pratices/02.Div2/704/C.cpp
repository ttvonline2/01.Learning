#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define hihihaha //*** debug ***//
#define debug(x) //*** debug ***//
#define DB(...) //*** debug ***//
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define oo 9e18
#define MP make_pair
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define ROR(_i,_b,_a) for(int _i = (_b); _i >= (_b); _i--)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)
using vb = vector<bool>; using vvb = vector<vb>; using vi = vector<int>; using vvi = vector<vi>;
using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int,int>; int itemp = 0; string stemp = "";
#else
#include "D:/01.Learning/01.Algorithms/debug.h"
#endif
//**************************** CODING SPACE ****************************//

int getNeeded(vi& A){
    int res = 0;
    for(int j = 0; j < A.size(); j++){
        res = max(A[j]-(j-1), res);
    }
    return res;
}
void solve() {
    int n; cin >> n;
    vvi A(n,vi(0));
    for(int i = 0; i < n; i ++){
        int k, v; cin >> k;
        for(int j = 0; j < k ; j ++){
            cin >> v;
            A[i].push_back(v);
        }
    }
    
    // tao need
    vector<pi> need(n,MP(0,0));
    FOR(i,0,n) {
        int a = getNeeded(A[i]);
        need[i] = MP(a,i);
    }
    sort(need.begin(), need.end());
    int res = need[0].first;
    int cur = res + A[need[0].second].size();
    for(int i = 1 ; i < n ; i ++){
        if(cur >= need[i].first){ // can go
            cur += A[need[i].second].size();
        } else {
            res += need[i].first - cur; cur = need[i].first + A[need[i].second].size();
        }
    }
    cout << res << "\n";
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();} hihihaha; return 0; }