#define ON_DEBUG 0
#if 1
#ifdef ONLINE_JUDGE
#include<bits/stdc++.h>
#else
#include "/Users/vangtruong/Documents/01.Learning/bits/stdc++.h"
#endif
using namespace std;

#if ON_DEBUG
//*** debug(x) ***//
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl
#else
#define debug(x) //*** debug ***//
#endif

template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) {
    os << "{ ";
    for(auto& y : x)os << y << ", ";
    return os << "}";
}

template <class X, class Y>
ostream & operator << (ostream & os, pair <X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")" ;
}

//*** define ***//
#define int long long
#define PB push_back
#define MP make_pair
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORI(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)

//*** custom using ***//
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using pi = pair<int,int>;
using vvp = vector<vector<pi> >;

#endif
//**************************** CODING SPACE ****************************//
int n; vvi adj, allLevel;
vi cnt, goal, origin;
void input() {
    cin >> n; goal.resize(n+1); origin.resize(n+1);
    allLevel.resize(n+1); cnt.resize(n+1,-1);
    adj.resize(n+1);
    FOR(i,0,n-1){
        int a, b; cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    FOR(i,1,n+1) cin >> origin[i];
    FOR(i,1,n+1) cin >> goal[i];
}
void dfs(int u, int lv){
    if(cnt[u] != -1) return;
    cnt[u] = 0; // visisted
    allLevel[lv].push_back(u);
    for(auto x: adj[u]){
        dfs(x, lv+1);
    }
}
void solve() {
    dfs(1,0);
    debug(allLevel);
    vb isVisited(n+1); vi ans;
    vector<pi> count(n+1,MP(0,0)); // <cnt, fw>
    FOR(lv,0,n+1){
        for (auto i: allLevel[lv]){
            count[i].first %= 2; count[i].second %= 2;
            debug(count[i]);
            //update origin[i];
            if (count[i].first == 1) origin[i] = (origin[i] == 0) ? 1 : 0;
            isVisited[i] = true;
            debug(i);
            // check goal
            bool isNeedUpdate = origin[i] == goal[i] ? false : true;
            if(isNeedUpdate) ans.push_back(i);
            for(auto x: adj[i]){
                if(isVisited[x]) continue;
                count[x].first = count[i].second;
                count[x].second = count[i].first;
                if(isNeedUpdate) count[x].second++;
            }
        }

    }
    debug(ans);
    cout << ans.size() << "\n";
    for(auto x: ans) cout << x << "\n";
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/input.txt", "r", stdin); freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int tcs = 1;
    while (tcs--) {
        input();
        solve();
    }
    return 0;
}