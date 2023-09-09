#if 1
#define LOCAL 1
#include <bits/stdc++.h>
using namespace std;

//*** debug(x) ***//
#define debug(x)             \
    cout << "[" << #x << "]" \
         << " : " << (x) << endl

#if LOCAL
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os,
                                  Container const& x) {
    os << "{ ";
    for (auto& y : x) os << y << ", ";
    return os << "}";
}

template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T>
void check_here(T x) {
    cout << "------------- " << x << " -------------" << endl;
}
#endif

//*** define ***//

#define pb push_back
#define FOR(_i, _a, _b) for (int _i = (_a); _i < (_b); _i++)
#define FORI(_i, _a, _b) for (int _i = (_a); _i <= (_b); _i++)
#define FORE(it, x) for (auto it = x.begin(); it != x.end(); ++it)

//*** custom using ***//
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

#endif
//**************************** CODING SPACE ****************************//

int F, W, L, N,n;
vi Z, X, Y;
vector<vector<pair<int, int> > > G;
vector<vector<int> > dp;
vector<bool> visited;
int min_cost;
int disFromZaToZb(int a, int b) {
    if (Z[a] <= Z[b]) {
        return 2 * (Z[b] - Z[a]);
    } else {
        return (Z[a] - Z[b]);
    }
}

int disFromAtoBSameZ(int xa, int ya, int xb, int yb) {
    return (abs(xa - xb) + abs(ya - yb));
}
int minDisFromEmpAtoEmpB(int a, int b) {
    if(Z[a] == Z[b]){
        return disFromAtoBSameZ(X[a], Y[a], X[b], Y[b]);
    }
    vi dis(4);
    // using E1
    dis[0] = disFromAtoBSameZ(1, 1, X[a], Y[a]) +
             disFromAtoBSameZ(1, 1, X[b], Y[b]) + disFromZaToZb(a, b);
    // using E2
    dis[1] = disFromAtoBSameZ(W, 1, X[a], Y[a]) +
             disFromAtoBSameZ(W, 1, X[b], Y[b]) + disFromZaToZb(a, b);
    // using E3
    dis[2] = disFromAtoBSameZ(1, L, X[a], Y[a]) +
             disFromAtoBSameZ(1, L, X[b], Y[b]) + disFromZaToZb(a, b);
    // using E4
    dis[3] = disFromAtoBSameZ(W, L, X[a], Y[a]) +
             disFromAtoBSameZ(W, L, X[b], Y[b]) + disFromZaToZb(a, b);
    sort(dis.begin(), dis.end());
    return dis[0];
}


void makeAdjG() {
    FOR(i, 0, N) {
        FOR(j, 0, N) {
            if(i==j) continue;
            int dis = minDisFromEmpAtoEmpB(i, j);
            G[i].push_back(make_pair(j, dis));
        }
    }
}
void dfs(int u,int n, int cost){
    visited[u] = true;
    n++;
    if(n == N){
        //cout << "end: " << cost << "\n";
        min_cost = min(min_cost,cost);
        return;
    }
    for(auto x: G[u]){
        if(visited[x.first]) continue;
        dfs(x.first,n,cost + x.second);
        visited[x.first] = false;
    }
    
}

void solve() {
    makeAdjG();
    // FOR(i,0,N){
    //     for(auto x: G[i]){
    //         cout << "From: " << i << " -> " << x.first << " : " << x.second
    //         << "\n";
    //     }
    // }
    dfs(0,0,0);
}
int32_t main() {
#if LOCAL
    freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/input.txt",
            "r", stdin);
    freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/output.txt",
            "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    while (T--) {
        cin >> F >> W >> L >> N;
        N++;
        min_cost = INT_MAX;
        Z.clear();
        X.clear();
        Y.clear();
        G.clear();
        dp.clear();
        G.resize(N);
        visited.clear();
        visited.resize(N);
        Z.resize(N);
        X.resize(N);
        Y.resize(N);
        FOR(i, 0, N) { cin >> Z[i] >> X[i] >> Y[i]; }
        solve();
        cout << min_cost << "\n" ;
    }

    return 0;
}