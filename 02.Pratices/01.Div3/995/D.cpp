#if 1
#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define debug(x) //*** debug ***//
#define debugv(x) //*** debug ***//
#include<bits/stdc++.h>
#else
#include "D:/01.Learning/01.Algorithms/debug2.h"
#define debug(x) //*** debug ***//
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
//  A[k - b] >= target is the condition
// neu khong thoa thi 
int BinarySearch_Smallest_k(vector<int>& A, int target, int st , int en) {
    int _n = (en - st + 1ll);
    int _k =  en;
    for (int b = _n / 2; b >= 1; b /= 2) while (_k - b >= st && A[_k - b] >= target) _k -= b;
    return A[_k] >= target ? _k : -1ll;
}

int binarySearch_Largest_k(vector<int>& A, int target, int st = -1, int en = -1) {
    int _n = en - st + 1;
    int _k = st;
    for (int b = _n / 2; b >= 1; b /= 2) while (_k + b <= en && A[_k + b] <= target) _k += b;
    return _k;
}

void solve() {
    int n, x, y; cin >> n >> x >> y;
    int sum = 0;
    vi A(n); FOR(i,0,n) {cin >> A[i]; sum += A[i]; }
    sort(A.begin(), A.end());
    int ans = 0;
    debug(A); debug(sum);
    FOR(i,0,n-1) {
        int target2 = sum - x - A[i], target1 = sum-y - A[i];
        debug(target1); debug(target2);
        int l = BinarySearch_Smallest_k(A, target1, i+1, n-1);
        if(l == -1 || A[l] > target2) continue;
        int r = binarySearch_Largest_k(A,target2,i+1,n-1);
        debug(i); debug(l); debug(r); 
        ans += r-l+1; 
    }
    debug(ans);
    cout << ans << "\n";
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();}return 0; }