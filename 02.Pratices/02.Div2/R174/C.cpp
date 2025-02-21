#if 1
#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define debug(x) //*** debug ***//
#define debugv(x) //*** debug ***//
#include<bits/stdc++.h>
#else
#include "D:/05.Learning/01.Algorithm/01.Algorithms/debug.h"
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
const int MOD = 998244353;
 
const int MAXN = 200000 + 5;

int pow2[MAXN], revPow[MAXN];
 
int modMul(int a, int b) { return (a % MOD) * (b % MOD) % MOD; }
 
void precomputePowers() {
    pow2[0] = 1ll;
    for (int i = 1; i < MAXN; i++) pow2[i] = modMul(pow2[i - 1], 2ll);
    // inv2 = 2^{-1} mod MOD = 499122177
    int inv2 = 499122177;
    revPow[0] = 1ll;
    for (int i = 1; i < MAXN; i++) {
        revPow[i] = modMul(revPow[i - 1], inv2);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0,S = 0, cnt1 = 0, p2 = 0;
    FOR (i,0,n) {
        if (a[i] == 1) {
            S = (S + revPow[p2]) % MOD;
            cnt1++;
        }
        else if (a[i] == 2) {
            p2++;
        }
        else if (a[i] == 3) {
            int term = modMul(pow2[p2], S);
            term = (term - cnt1) % MOD;
            if (term < 0) term += MOD;
            ans = (ans + term) % MOD;
        }
    }
    cout << ans % MOD << "\n";
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    precomputePowers();
    while (tcs--) {solve();}return 0; }