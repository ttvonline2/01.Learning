#if 1
#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define hihihaha //*** debug ***//
#define debug(x) //*** debug ***//
#define debugv(x) //*** debug ***//
#include<bits/stdc++.h>
#else
#include "D:/01.Algorithm/01.Algorithms/debug.h"
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
const int MAXN = 100005;

int n; vi A, dp;
int getAns(int i){
    if(i <= 0) return 0;
    if(dp[i] != -1) return dp[i];
    int res = getAns(i-2) + A[i];
    res = max(res,getAns(i-3) + A[i]);
    res = max(res, getAns(i-1));
    dp[i] = res;
    return res;
}
void solve() {
    cin >> n; A.clear(); A.resize(MAXN); dp.clear(); dp.resize(MAXN,-1);
    int res = 0;
    FOR(i,0,n) {  int x; cin >> x; A[x] += x; res = max(res,x);}
    cout << getAns(res) << "\n";
    // debug(dp);
}

int32_t main() {
    vangtruong; int tcs = 1; 
    while (tcs--) {solve();} hihihaha; return 0; }