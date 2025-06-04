#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define hihihaha //*** debug ***//
#define debug(x) //*** debug ***//
#define DB(...) //*** debug ***//
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define oo 9e18
#define MP make_pair
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define ROR(_i,_b,_a) for(int _i = (_b); _i >= (_b); _i--)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)
using vb = vector<bool>; using vvb = vector<vb>; using vi = vector<int>; using vvi = vector<vi>; using vs = vector<string>;
using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int,int>; int itemp = 0; string stemp = "";
#else
#include "D:/01.Learning/01.Algorithms/debug.h"
#endif
//**************************** CODING SPACE ****************************//

void solve() {
    int N, K, M; cin >> N >> K >> M; vi A(N+1); FOR(i,1,N+1) cin >> A[i];
    DB(A);
    int pos = K;
    FOR(i,0,M){
        int x; cin >> x;
        if(x > 0 ) {
            if(pos <= x) {
                pos = x - pos + 1;
                DB("x,pos: ", x, pos);
            }
        } else {
            int s = -x;
            int l = N - s + 1;
            if(pos >=l ) {
                pos = N - (pos - l);
                debug(pos);
                DB("x,pos: ", x, pos);
            }
        }
    }
    cout << pos << "\n";
}

int32_t main() {
    vangtruong; int tcs = 1;
    while (tcs--) {solve();} hihihaha; return 0; }