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
#define INF LONG_LONG_MAX
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORI(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)

//*** custom using ***//
using vb = vector<bool>; using vvb = vector<vb>;
using vi = vector<int>; using vvi = vector<vi>;
using vc = vector<char>;using vvc = vector<vc>;
using pi = pair<int,int>;
int itemp = 0; string stemp = "";
#endif
//**************************** CODING SPACE ****************************//

void input() {
    int n,m; cin >> n >> m; 
    vi A(n), B(n), dp(n,INF);
    FOR(i,0,n) cin >> A[i];
    FOR(i,0,n) cin >> B[i];
    for(int i = n-1; i >= 0; i --) {
        if(i == n-1){
            dp[i] = min(A[i],B[i]);
            continue;
        }
        dp[i] = min(A[i],B[i]) + dp[i+1];
    }
    int ans = INF;
    // debug(dp);
    FOR(i,0,m){
        if(i == n-1) {
            ans = min(ans, A[i]);
            continue;;
        }
        ans = min(ans, dp[i+1] + A[i]);
    }
    cout << ans << "\n";

}

void solve() {
    
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("D:/05.Learning/01.Algorithm/00.Ultility/input.txt", "r", stdin); freopen("D:/05.Learning/01.Algorithm/00.Ultility/output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int tcs = 1; cin >> tcs;
    while (tcs--) {
        input();
        solve();
    }
    return 0;
}