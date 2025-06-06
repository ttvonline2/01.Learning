#define ON_DEBUG 0
#if 1
#ifdef ONLINE_JUDGE
#include<bits/stdc++.h>
#else
#include "D:/01.Learning/01.Algorithms/debug2.h"
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
int n, q; // 38
vector<string> Forest;
vvi dp;
void input() {
    cin >> n >> q;
    Forest.resize(n);
    FOR(i,0,n) cin >> Forest[i]; 
}

void solve() {
    // caculate dp
    dp.resize(n+1,vi(n+1));
    FOR(r,1,n+1){
        FOR(c,1,n+1){
            dp[r][c] = dp[r-1][c] + dp[r][c-1] - dp[r-1][c-1];
            if(Forest[r-1][c-1] == '*') dp[r][c]++;
        }
    }
    debug(dp);
    FOR(i,0,q){
        int x1,x2,y1,y2; cin >> y1 >> x1 >> y2 >> x2;
        int px3 = x1-1, py3 = y2, px4 = x2, py4 = y1-1, px5 = x1-1, py5 = y1-1;
        cout << dp[y2][x2] - dp[py3][px3] - dp[py4][px4] + dp[py5][px5] << "\n";
    }
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