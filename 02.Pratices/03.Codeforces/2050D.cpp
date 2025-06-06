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
    string s; cin >> s; int n = s.size();
    FOR(i,0,n-1){
        // debug(s);
        int can = s[i]  - '0';
        int pos = i;
        FOR(k,i,i+10){
            if(k >= n) continue;
            if(can < (s[k] -'0') - (k-i)) {
                can = (s[k] -'0') - (k-i); pos = k;
            }
        }
        if(pos == i) continue;
        // swap lan luot tu k 
        for(int k = pos; k >= i+1; k--) s[k] = s[k-1];
        s[i] = can + '0';
        // debug(i); debug(s);
    }
    cout << s << "\n";
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();} hihihaha; return 0; }