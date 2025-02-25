#if 1
#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define hihihaha //*** debug ***//
#define debug(x) //*** debug ***//
#define debugv(x) //*** debug ***//
#include<bits/stdc++.h>
#else
#include "D:/01.Algorithm/01.Algorithms/debug.h"
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
    int n, k; cin >> n >> k;
    bitset<32> s(k);
    int pos = 0;
    for(int i = 0; i < 32 ; i ++){
        if(s[i] == 0) {
            pos = i; break;
        }
    }
    int m = pow(2ll,pos);
    vi ans; int v = 0;
    FOR(i, 0, n) {
        if(i == n-1){
            if((v | i) < k){ans.push_back(k); break;}
        }
        if (i < m) {ans.push_back(i); v |= i;}
        else break;
    }
    if (ans.size() < n) {
        ans.push_back(k);
        while (ans.size() < n) {
            ans.push_back(0);
        }
    }
    
    for(auto x: ans) cout << x << " ";
    cout << "\n";
    // cout << s.to_string() << "\n";


}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();} hihihaha; return 0; }