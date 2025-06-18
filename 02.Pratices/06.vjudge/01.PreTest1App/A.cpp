#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define hihihaha //*** debug ***//
#define debug(...) //*** debug ***//
#define DB(...) //*** debug ***//
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;
#define int long long
#define oo 4e18
#define MP make_pair
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define ROR(_i,_b,_a) for(int _i = (_b); _i >= (_b); _i--)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)
#define all(x) (x).begin(), (x).end()
using vb = vector<bool>; using vvb = vector<vb>; using vi = vector<int>; using vvi = vector<vi>; using vs = vector<string>; using vpi = vector<pair<int,int>>;
using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int,int>; int itemp = 0; string stemp = ""; using vvpi = vector<vector<pair<int,int>>>;
template <typename T, typename Comp>
using ordered_set_custom = tree<T, null_type, Comp, rb_tree_tag, tree_order_statistics_node_update>; // Comp = less<int>, less_equal<int>, greater<int>, StructComp
#else
#include "D:/01.Learning/01.Algorithms/debug2.h"
#endif
//**************************** CODING SPACE ****************************//
vvi ans; int N, M;
void getAns(int startVal,int pos, vi& res) {
    if(pos >= N) return;
    if(pos < N-1 && startVal >= M) return;
    if(pos < N && pos != -1) res[pos] = startVal;
    if(pos == N-1 && startVal <= M) {ans.push_back(res); return;}
    // fill next
    FOR(i,0,M+1) {
        getAns(startVal+10+ i,pos+1,res);
    }
    res[pos] = 0;
}

void solve() {
    cin >> N >> M; vi res(N,0);
    FOR(i,1,M+1) {
        getAns(i,0,res);
    }
    DB(ans);
    cout << ans.size() << "\n";
    for(auto v: ans) {
        for(auto x: v) cout << x << " ";
        cout << "\n";
    }
}

int32_t main() {
    vangtruong; int tcs = 1; 
    while (tcs--) {solve();} hihihaha; return 0; }