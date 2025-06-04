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
using vb = vector<bool>; using vvb = vector<vb>; using vi = vector<int>; using vvi = vector<vi>;
using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int,int>; int itemp = 0; string stemp = "";
#else
#include "D:/01.Learning/01.Algorithms/debug.h"
#endif
//**************************** CODING SPACE ****************************//

void solve() {
    int n; cin >> n;
    vi A(n);
    for(auto &x : A) cin >> x;
    sort(A.begin(), A.end());
    int cost = 0;
    if(n >= 60) {
        for(auto x: A) cost += (x - 1);
    } else {
        cost = oo;
        for(int i = 1; i < 1e5; i++){
            if(pow(i,n-1) > 1e11) break;
            // tinh cost can thiet cho moi i
            int res = 0;
            for(int j = 0; j < n; j++){
                res += abs(A[j] - pow(i,j));
            }
            debug(i); debug(res);
            cost = min(cost,res);
        }
    }
    cout << cost << "\n";
}

int32_t main() {
    vangtruong; int tcs = 1;
    while (tcs--) {solve();} hihihaha; return 0; }