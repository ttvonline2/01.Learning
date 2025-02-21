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

void solve() {
    int n,m,k; cin >> n >> m >> k;
    vi M(m), Q(k);
    FOR(i,0,m) cin >> M[i];
    FOR(i,0,k) cin >> Q[i];
    if(k == n){ string s(m,'1'); cout  << s << "\n"; return;}
    if(k < n-1){ string s(m,'0'); cout  << s << "\n"; return;}
    string s(m,'0'); // tim phan tu thieu trong Q. tim v trong m, neu co v chuyen thanh '1' 
    int v = n;
    FOR(i,0,k) { if(Q[i] != i+1) { v = i +1; break;}}
    debugv(M);
    FOR(i,0,m) {if(M[i] == v){s[i] = '1';}}
    cout << s << "\n";

}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();}return 0; }