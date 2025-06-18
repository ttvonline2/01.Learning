#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define hihihaha //*** debug ***//
#define debug(...) //*** debug ***//
#define DB(...) //*** debug ***//
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;
#define int long long
#define oo 4e18
#define MP make_pair
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define ROR(_i,_b,_a) for(int _i = (_b); _i >= (_b); _i--)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)
#define all(x) (x).begin(), (x).end()
#define CR(_x,_n) (_x).clear(); (_x).resize((_n))
using vb = vector<bool>; using vvb = vector<vb>; using vi = vector<int>; using vvi = vector<vi>; using vs = vector<string>; using vpi = vector<pair<int,int>>;
using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int,int>; int itemp = 0; string stemp = ""; using vvpi = vector<vector<pair<int,int>>>;
template <typename T, typename Comp>
using ordered_set_custom = tree<T, null_type, Comp, rb_tree_tag, tree_order_statistics_node_update>; // Comp = less<int>, less_equal<int>, greater<int>, StructComp
#else
#include "D:/01.Learning/01.Algorithms/debug2.h"
#endif
//**************************** CODING SPACE ****************************//
const int MAXN = 1'000'000;
int spf[MAXN + 1];
void sieve() {
    for (int i = 2; i <= MAXN; ++i) if (!spf[i])
        for (int j = i; j <= MAXN; j += i) if (!spf[j]) spf[j] = i;
}
long long kgl;
long long maxDiv(long long n) {
    vector<pair<int,int>> f;
    long long m = n;
    while (m > 1) {
        int p = spf[m], c = 0;
        while (m % p == 0) { m /= p; ++c; }
        f.push_back({p, c});
    }
    long long best = 1;
    function<void(int,long long)> dfs = [&](int idx, long long cur) {
        if (cur > kgl) return;
        best = max(best, cur);
        if (idx == (int)f.size()) return;
        long long val = 1;
        for (int i = 0; i <= f[idx].second; ++i) {
            dfs(idx + 1, cur * val);
            val *= f[idx].first;
            if (val > kgl) break;
        }
    };
    dfs(0, 1);
    return best;
}

long long steps(long long n) {
    if (n == 1) return 0;
    if (kgl == 1) return -1;
    long long cnt = 0;
    while (n > 1) {
        if (n <= kgl) { ++cnt; break; }
        long long d = maxDiv(n);
        if (d == 1) return -1;
        n /= d;
        ++cnt;
    }
    return cnt;
}

void solve() {
        long long x, y, k; cin >> x >> y >> k;
        kgl = k;
        long long g = std::gcd(x, y);
        long long s = x / g, r = y / g;
        long long a = steps(s), b = steps(r);
        if (a == -1 || b == -1) cout << -1 << '\n';
        else cout << a + b << '\n';
}

int32_t main() {
    vangtruong;
    sieve();
    int tcs = 1; cin >> tcs;
    while (tcs--) {solve();} hihihaha; return 0; }