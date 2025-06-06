#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define hihihaha //*** debug ***//
#define debug(x) //*** debug ***//
#define DB(...) //*** debug ***//
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;
#define int long long
#define oo 9e18
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

void solve() {
    int n,m; cin >> n >> m;
    vi C(n); for(auto&x: C) cin >> x;
    ordered_set_custom<int,less_equal<int>> A; for(auto x: C) A.insert(x);
    debug(A);
    FOR(i,0,m){
        int a; cin >> a;
        // tim ve nho hon a = a --> a++
        a++;
        int pos = A.order_of_key(a); debug(pos);
        if(pos == 0) cout << "-1\n";
        else {
            auto it = A.find_by_order(pos-1);
            cout << *it << "\n";
            A.erase(it);
            debug(A);
        }
        // A.erase()
    }
}

int32_t main() {
    vangtruong; int tcs = 1;
    while (tcs--) {solve();} hihihaha; return 0; }