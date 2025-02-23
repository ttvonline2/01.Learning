#if 1
#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define hihihaha //*** debug ***//
#define debug(x) //*** debug ***//
#define debugv(x) //*** debug ***//
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
string getRes(string& s, int i, int n){
    int gap = s.size() - n;
    string res = s; string c = s.substr(i,n);
    for(int j = 0; j < c.size(); j++){
        c[j] != res[j+gap] ? res[j+gap] = '1' : res[j+gap] = '0';
    }
    return res;
}
void solve() {
    string s; cin >> s; int n = s.size();
    // tim vi tri dau tien co gia tri 0;
    int k = 0;
    FOR(i,0,n){
        if(s[i] == '0') {k = i; break;}
    }
    if(k ==0) {cout << 1 << " " << n << " 1 1\n"; return;}
    int nsize = n - k;
    string v = s; int ans = 0;
    FOR(i,0,n){
        if(i+nsize >= n) break;
        string h = getRes(s,i,nsize);
        if(h > v) {
            v = h; ans = i;
        }
    }
    cout << 1 << " " << n << " " << ans +1 << " " << ans + nsize << "\n";
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();} hihihaha; return 0; }