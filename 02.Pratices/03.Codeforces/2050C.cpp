#if 1
#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define debug(x) //*** debug ***//
#define debugVvi(x) //*** debug ***//
#include<bits/stdc++.h>
#else
#include "/Users/vangtruong/Documents/01.Learning/01.Algorithms/debug.h"
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
    string s; cin >> s;
    int v = 0;
    int A2 = 0, A3 = 0;
    for(auto c: s){
        v += (c - '0');
        if(c == '2') A2++;
        if(c == '3') A3++;
    }
    v = v% 9;
    // debug(v); debug(A2); debug(A3);
    vi C(9); C[0] = 1;
    FOR(i,0,min(11ll,A3+1)){
        int x = 6*i;
        FOR(j,0,min(11ll,A2+1)){
            int y = x+2*j; y%=9;
            C[y] = 1;
        }
    }
    // debug(C);
    C[(9 - v)%9 ] == 1 ? cout << "YES\n" :  cout << "NO\n";

}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();}return 0; }