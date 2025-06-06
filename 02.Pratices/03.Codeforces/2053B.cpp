#if 1
#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define hihihaha //*** debug ***//
#define debug(x) //*** debug ***//
#define debugv(x) //*** debug ***//
#include<bits/stdc++.h>
#else
#include "D:/01.Learning/01.Algorithms/debug2.h"
#endif
using namespace std;
//*** define ***//
#define int long long
#define INF LONG_LONG_MAX
#define MP make_pair
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORI(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)
using vb = vector<bool>; using vvb = vector<vb>; using vi = vector<int>; using vvi = vector<vi>;
using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int,int>; int itemp = 0; string stemp = "";
#endif
//**************************** CODING SPACE ****************************//

void solve() {
    int n; cin >> n; vvi P(n,vi(2)); map<int,int> mm; vb U(2*n+5);
    FOR(i,0,n){
        cin >> P[i][0] >> P[i][1];
        if(P[i][0] == P[i][1]) {mm[P[i][0]]++; U[P[i][0]] = true;}
    }
    string ans(n,'-');
    // 
    FOR(i,0,n){
        if(P[i][0] == P[i][1]){
            if(mm[P[i][0]] > 1) ans[i] = '0';
            else ans[i] = '1';
        }
    }
    // tinh pre
    vi pre(2*n+5,0);
    FOR(i,1,2*n+5){
        pre[i] = pre[i-1];
        if(U[i]) pre[i]++;
    }
    FOR(i,0,n){
        if(ans[i]!= '-') continue;
        int l  = P[i][0], r = P[i][1];
        if(r-l+1 == (pre[r] - pre[l-1])) ans[i] = '0';
        else ans[i] = '1'; 
    }
    // debug(ans);
    cout << ans <<"\n";

}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();} hihihaha; return 0; }