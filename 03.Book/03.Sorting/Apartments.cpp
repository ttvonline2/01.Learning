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
#define all(x) (x).begin(), (x).end()
using vb = vector<bool>; using vvb = vector<vb>; using vi = vector<int>; using vvi = vector<vi>; using vs = vector<string>; using vpi = vector<pair<int,int>>;
using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int,int>; int itemp = 0; string stemp = ""; using vvpi = vector<vector<pair<int,int>>>;
#else
#include "D:/01.Learning/01.Algorithms/debug2.h"
#endif
//**************************** CODING SPACE ****************************//

void solve() {
    int n,m,k; cin >> n >> m >> k;
    vi A(n), B(m); for(auto&x: A) cin >> x;
    for(auto&x: B) cin >> x;
    sort(all(A)); sort(all(B));
    int pa = 0, pb = 0, res = 0;
    while(pa < A.size() && pb < B.size()) {
        if(A[pa] < B[pb] - k) pa++;
        else if (A[pa] > B[pb] + k) pb++;
        else {res++; pa++; pb++;};
    }
    cout << res << "\n";
}

int32_t main() {
    vangtruong; int tcs = 1;
    while (tcs--) {solve();} hihihaha; return 0; }