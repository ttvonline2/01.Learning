#if 1
#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define debug(x) //*** debug ***//
#define debugVi(x) //*** debug ***//
#define debugVvi(x) //*** debug ***//
#else
#include "D:/01.Learning/01.Algorithms/debug2.h"
#endif
#include<bits/stdc++.h>
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
    int n;  cin >> n;
    vi A(n); FOR(i,0,n) cin >> A[i];
    if(n&1) {
        for(int i = 1; i < n-1; i+=2) if(A[i] > A[i+1]) swap(A[i],A[i+1]);
    } else {
        for(int i = 0; i < n-1; i+=2) if(A[i] > A[i+1]) swap(A[i],A[i+1]);
    }
    debug(A);
    FOR(i,1,n){
        if(A[i] < A[i-1]) {
            cout << "NO\n"; return;
        }
    }
    cout  << "YES\n"; 
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();}return 0; }