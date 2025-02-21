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
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for(auto c : s){
        if(c == '1' && ans % 2 == 0){
            ans++; continue;
        }
        if(c == '0' && ans % 2 == 1){
            ans++; continue;
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();}return 0; }