#if 1
#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define hihihaha //*** debug ***//
#define debug(x) //*** debug ***//
#define debugVvi(x) //*** debug ***//
#else
#include "D:/01.Learning/01.Algorithms/debug.h"
#endif
#include<bits/stdc++.h>
using namespace std;
//*** define ***//
#define int long long
#define INF LONG_LONG_MAX
#define MP make_pair
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define ROR(_i,_a,_b) for(int _i = (_a); _i >= (_b); _i--)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)
using vb = vector<bool>; using vvb = vector<vb>; using vi = vector<int>; using vvi = vector<vi>;
using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int,int>; int itemp = 0; string stemp = "";
#endif
//**************************** CODING SPACE ****************************//

void solve() {
    string s; cin >> s; int n = s.size(); set<int> A,B;
    FOR(i,0,n-1) {
        if(s[i] == 'A' && s[i+1] == 'B') A.insert(i);
    }
    ROR(i,n-1,1) {
        if(s[i] == 'A' && s[i-1] == 'B') B.insert(i);
    }
    bool ans = false; debug(A); debug(B);
    if(A.size() == 0 || B.size() == 0) ans = false;
    else {
        if(abs(A-B) > 2) ans = true;
    }
    ans ? cout << "YES\n" : cout <<  "NO\n";
}

int32_t main() {
    vangtruong; int tcs = 1; 
    while (tcs--) {solve();} hihihaha; return 0; }