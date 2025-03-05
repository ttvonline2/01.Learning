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
#define FORI(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)
using vb = vector<bool>; using vvb = vector<vb>; using vi = vector<int>; using vvi = vector<vi>;
using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int,int>; int itemp = 0; string stemp = "";
#endif
//**************************** CODING SPACE ****************************//
const int ABC = 26;
int getAns(vi& c, vi& l, int n){
    int a = *max_element(c.begin(), c.end());
    int b = *max_element(l.begin(), l.end());
    // debug(a); debug(b);
    return n - a - b;
}
vi getMerge(vi& a, vi& b){
    vi c = a;
    FOR(i,0,ABC) c[i] += b[i];
    return c;
}
void solve() {
    int n; cin >> n; string s; cin >> s; 
    if(n == 1) {cout << "1\n"; return;}
    if(n == 2) {cout << "0\n"; return;}
    vvi Pc(n+2,vi(ABC)), Pl(n+2,vi(ABC)), Sc(n+2,vi(ABC)), Sl(n+2,vi(ABC));
    FOR(i,1,n+1){
        FOR(j,0,ABC) {Pl[i][j] = Pl[i-1][j]; Pc[i][j] = Pc[i-1][j];}
        if(i%2 == 1) Pl[i][s[i-1] - 'a']++;
        else Pc[i][s[i-1]-'a']++;
    }
    for(int i = n; i >= 1; i--){
        FOR(j,0,ABC) {Sl[i][j] = Sl[i+1][j]; Sc[i][j] = Sc[i+1][j];}
        if(i%2 == 1) Sl[i][s[i-1]-'a']++;
        else Sc[i][s[i-1]-'a']++;
    }
    /// 
    int ans = 0;
    if(n%2 == 0) {
        ans = getAns(Pc[n],Pl[n], n);
    } else {
        // debugv(Pc);
        // try remove
        ans = INT_MAX;
        FOR(i,1,n+1){
            vi c = getMerge(Pc[i-1],Sl[i+1]);
            vi l = getMerge(Pl[i-1],Sc[i+1]);
            ans = min(ans, getAns(c,l,n-1));
        }
        ans++;
    }
    cout << ans << "\n";
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();} hihihaha; return 0; }