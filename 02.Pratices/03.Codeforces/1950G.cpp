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
// #define int long long
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
int n;
vector<vector<string> > data_ori;
vvi mat;
vvi dp;
void input() {
    cin >> n; data_ori.clear(); data_ori.resize(n, vector<string>(2, ""));
    mat.clear(); mat.resize(n,vi(n)); //i j
    dp.clear();dp.resize(1 << n, vi(n,0));
    FOR(i,0,n){
        cin >> data_ori[i][0] >> data_ori[i][1];
    }
}

void solve() {
    FOR(i,0,n){
        FOR(j,0,n){
            mat[i][j] = (data_ori[i][0] == data_ori[j][0]) || (data_ori[i][1] == data_ori[j][1]);
        }
    }
    // make the first [mask][i]qa
    int ans = 1;
    FOR(i,0,n) dp[1 << i][i] = 1;
    FOR(mask, 1, 1 << n){
        FOR(i,0,n) { // last i
            if((mask & (1 << i)) == 0) continue; // ket thuc la i, nhung mask k co i --> ignore
            if(dp[mask][i] == false) continue; // khong the 
            debug(mask); debug(i);
            FOR(j,0,n) { // add j
                if((mask & (1 << j)) != 0) continue; // trong mask da co j
                if(i == j) continue;
                if(mat[i][j] == true){
                    dp[mask | (1 << j)][j] = 1;
                    //  bitset<7> v(mask); bitset<7> b(mask | (1<<j)); cout << "mask: " 
                    //     << v << "[" << i <<"] + [j]: " << j << " ==> new mask: " << b << "\n";
                    ans = max(ans, __builtin_popcount(mask | (1 << j)));
                }
            }
            
        }
    }
    cout << n - ans << "\n";

}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/input.txt", "r", stdin); freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int tcs; cin >> tcs;
    while (tcs--) {
        input();
        solve();
    }
    return 0;
}