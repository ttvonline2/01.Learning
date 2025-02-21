#if 1
#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define debug(x) //*** debug ***//
#define debugv(x) //*** debug ***//
#include<bits/stdc++.h>
#else
#include "D:/05.Learning/01.Algorithm/01.Algorithms/debug.h"
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
vi A,PreAm, PreDuong; // PreAm tinh tu n --> i;// pre duong tu 1 --> i
int n;

void solve() {
    cin >> n;
    A.clear(); A.resize(n+1); 
    PreAm.clear(); PreAm.resize(n+2,0); PreDuong.clear(); PreDuong.resize(n+2,0); 
    FOR(i,1,n+1) cin >> A[i];
    PreDuong[1] = max(0ll,A[1]);
    FOR(i,2,n+1) {
        if(A[i] > 0){
            PreDuong[i] = PreDuong[i-1] + A[i];
        } else{
            PreDuong[i] = PreDuong[i-1];
        }
    }
    PreAm[n] = max(0ll,-A[n]);
    for(int i =n; i >= 1; i--) {
        if(A[i] < 0){
            PreAm[i] = PreAm[i+1] - A[i];
        } else{
            PreAm[i] = PreAm[i+1];
        }
    }
    int ans = 0;
    debug(PreAm); debug(PreDuong);
    FOR(i,1,n+1) ans = max(ans, (PreAm[i] + PreDuong[i]));
    cout << ans  << "\n";
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();}return 0; }