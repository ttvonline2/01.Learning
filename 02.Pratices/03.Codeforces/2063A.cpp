#if 1
#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define hihihaha //*** debug ***//
#define debug(x) //*** debug ***//
#define debugv(x) //*** debug ***//
#include<bits/stdc++.h>

#else
#include "D:/05.Learning/01.Algorithm/01.Algorithms/debug.h"
#endif
#include <climits>
using namespace std;
//*** define ***//
#define int long long
#define oo LLONG_MAX
#define MP make_pair
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)
using vb = vector<bool>; using vvb = vector<vb>; using vi = vector<int>; using vvi = vector<vi>;
using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int,int>; int itemp = 0; string stemp = "";
#endif
//**************************** CODING SPACE ****************************//

void solve() {
    int l,r, ans = oo; cin >> l >> r;
    if(l == r && l == 1) ans = 1;
    else if(l == r and l != 1) ans = 0;
    else ans =  r - l;
    cout << ans << "\n";
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();} hihihaha; return 0; }