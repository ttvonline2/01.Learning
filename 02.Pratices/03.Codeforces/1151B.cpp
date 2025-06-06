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

#endif
//**************************** CODING SPACE ****************************//
int n, m;
vvi dp,arr;
int getPos(int r, int& mask, int pos) {
    int value = arr[r-1][pos-1];
    int preMask = value^mask;
    debug(r); debug(value); debug(pos); debug(preMask);
    mask = preMask;
    return dp[r-1][preMask];
}
void input() {
    cin >> n >> m;
    dp.resize(n+1,vi(1024,0));
    arr.resize(n,vi(m));
    FOR(r,0,n){
        FOR(c,0,m){
            int a; cin >> a; arr[r][c] = a;
            if(r==0){
                dp[r+1][a] = c+1;
            } else {
                FOR(i,0,1024){
                    if(dp[r][i] != 0) {
                        if(dp[r+1][i^a] == 0){
                            dp[r+1][i^a] = c+1;
                        }
                    }
                }
            }
        }
    }
    stack<int> res;
    int mask;
    FOR(i,1,1024) {
        if(dp[n][i] != 0){
            cout << "TAK\n";
            res.push(dp[n][i]);
            mask = i;
            for(int k = n; k >1 ; k--){
                int pos = getPos(k,mask,dp[k][mask]);
                res.push(pos);
            }
            while(!res.empty()){
                cout << res.top() <<" ";
                res.pop();
            }
            return;
        }
    }
    cout << "NIE";
}

void solve() {
    
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