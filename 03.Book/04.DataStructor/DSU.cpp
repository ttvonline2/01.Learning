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
int N, M;
vvi edge;
vi link, cnt;
int find(int x) {
    while (x != link[x]) x = link[x];
    return x;
}
bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (cnt[a] < cnt[b]) swap(a, b);
    cnt[a] += cnt[b];
    link[b] = a;
}
void solve() {
    cin >> N >> M; edge.clear(); CR(link,N+1); cnt.clear(); cnt.resize(N+1,1);
    int u,v,w; int res = 0;
    FOR(i,0,M) {
        cin >> u >> v >> w; edge.push_back({w,u,v});
    }
    FOR(i,1,N+1) {link[i]=i;}
    sort(all(edge),[](vi& a, vi&b) {
        return a[0] < b[0];
    });
    for(auto e: edge) {
        int u = e[1], v = e[2];
        if(same(u,v)) continue;
        unite(u,v); res+=e[0];
    }
    DB(link); DB(cnt);
    cout << res << "\n";
}

int32_t main() {
    vangtruong; int tcs = 1; 
    while (tcs--) {solve();} hihihaha; return 0; }


/*
4 5
1 2 10
2 3 15
1 3 5
4 2 2
4 3 40


output: 17
*/