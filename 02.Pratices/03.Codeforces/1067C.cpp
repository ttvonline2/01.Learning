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

const vi D = {9, 99, 999, 9999, 99999,999999,9999999,99999999,999999999};
bool isFound7(int n){
    string s = to_string(n);
    return s.find('7') != -1 ? true : false;
}
int getAns(int n, int d){
    int res = 0;
    FOR(i,0,9){
        if(isFound7(n)) return res;
        res++;
        n += D[d];
    }
}
void solve() {
    int n; cin >>  n;
    int ans = 9;
    FOR(i,0,9) {
        ans = min(ans, getAns(n,i));
    }
    cout << ans << "\n";
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();}return 0; }