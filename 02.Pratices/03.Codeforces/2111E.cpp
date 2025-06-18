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
#define CR(_x,_n) (_x).clear(); (_x).resize((_n))
using vb = vector<bool>; using vvb = vector<vb>; using vi = vector<int>; using vvi = vector<vi>; using vs = vector<string>; using vpi = vector<pair<int,int>>;
using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int,int>; int itemp = 0; string stemp = ""; using vvpi = vector<vector<pair<int,int>>>;
template <typename T, typename Comp>
using ordered_set_custom = tree<T, null_type, Comp, rb_tree_tag, tree_order_statistics_node_update>; // Comp = less<int>, less_equal<int>, greater<int>, StructComp
#else
#include "D:/01.Learning/01.Algorithms/debug2.h"
#endif
//**************************** CODING SPACE ****************************//
int pairsCount(vector<pair<char, char>> & a, char x1, char y1, char x2, char y2) {
    int first = 0, res = 0;
    for(auto [x,y] : a) {
        if(x == x1 && y == y1) ++first;
        else if(x==x2&& y == y2 && first){ --first; ++res;} 
    }
    return res;
}

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<pair<char,char>> op(q);
    int ba = 0, ca = 0, cb = 0, bc = 0;
    for(int i = 0; i <q ; ++i) {
        cin >> op[i].first >> op[i].second;
        if(op[i] == MP('b','a')) ++ba;
        else if(op[i] == MP('c','a')) ++ca;
        else if(op[i] == MP('c','b')) ++cb;
        else if(op[i] == MP('b','c')) ++bc;
    }
    int pcb = pairsCount(op,'c','b','b','a');
    int pbc = pairsCount(op,'b','c','c','a');
    string res = s;
    for(char& c: res) {
        if(c == 'b') {
            if(ba) {c = 'a'; --ba;}
            else if(pbc && bc && ca) {c = 'a'; --pbc; --bc; --ca;}
        } else if(c == 'c') {
            if(ca) {c = 'a'; --ca;}
            else if(pcb&&cb&& ba) {c = 'a';--pcb; --cb; --ba;}
            else if(cb) { c = 'b'; --cb;}
        }
    }
    cout << res << '\n';
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();} hihihaha; return 0; }