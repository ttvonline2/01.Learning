#if 1
#define ON_DEBUG 1
#include<bits/stdc++.h>
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

#endif
//**************************** CODING SPACE ****************************//
vvi adj;
int n;
vvi dp;
int root;


int getAns(int u,int e, int c){
    if(dp[u][c] != -1) return dp[u][c];
    if(adj[u].size() == 1 && u != 1) {
        // debug(u);
        return dp[u][0] = dp[u][1] = 0; 
    }
    int res = 0;
    if(c == 1){
        for(auto v: adj[u]){
            if(v == e) continue;
            res += getAns(v,u,0);
        }
    } else { // = 0 --> Khi vao, chua duoc chon
        // prefixsum? 
        int sum = 0;
        for(auto v: adj[u]){
            if(v == e) continue;
            sum += getAns(v,u,0);
        }
        // debug(sum);
        for(auto v: adj[u]){
            if(v == e) continue;
            int t = 1 + (sum - getAns(v,u,0)) + getAns(v,u,1); // connect to u-v;
            res = max(res,t);
        }
    }
    // debug(res);
    return dp[u][c] = res;
}

void input() {
    cin >> n; adj.resize(n+1);
    dp.resize(n+1,vi(2,-1));
    if(n == 1 ){
        cout << "0\n"; return;
    }
    int a, b;
    FOR(i,1,n){
        cin >> a >> b; 
        adj[a].push_back(b);  adj[b].push_back(a);
    }
    int ans = max(getAns(1,0,0), getAns(1,0,1));
    // debugVvi(dp);
    cout << ans;
}

void solve() {
    
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("D:/05.Learning/01.Algorithm/00.Ultility/input.txt", "r", stdin); freopen("D:/05.Learning/01.Algorithm/00.Ultility/output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int tcs = 1;
    while (tcs--) {
        input();
        solve();
    }
    return 0;
}