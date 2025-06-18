#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define hihihaha //*** debug ***//
#define debug(...) //*** debug ***//
#define DB(...) //*** debug ***//
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define oo 4e18
#define MP make_pair
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define ROR(_i,_b,_a) for(int _i = (_b); _i >= (_b); _i--)
#define all(x) (x).begin(), (x).end()
using vb = vector<bool>; using vvb = vector<vb>; using vi = vector<int>; using vvi = vector<vi>; using vs = vector<string>; using vpi = vector<pair<int, int>>;
using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int, int>; int itemp = 0; string stemp = ""; using vvpi = vector<vector<pair<int, int>>>;
#else
#include "D:/01.Learning/01.Algorithms/debug2.h"
#endif
//**************************** CODING SPACE ****************************//

void solve() {
    int N, M; cin >> N >> M; vi a(N);
    for (auto& x : a) cin >> x;
    vvi byPop(11);
    FOR(x, 1, M + 1) {
        int pc = __builtin_popcount(x);
        if (pc <= 10) byPop[pc].push_back(x);
    }
    vvi choices(N);
    FOR(i, 0, N) {
        choices[i] = byPop[a[i]];
        if (choices[i].empty()) {
            cout << "-1\n"; return;
        }
    }
    int NEG = -1e9;
    vvi dp(N);
    dp[N - 1].assign(choices[N - 1].size(), 0);
    for (int i = N - 2; i >= 0; i--) {
        int sz = choices[i].size(), szn = choices[i + 1].size();
        dp[i].assign(sz, NEG);
        FOR(j, 0, sz) {
            int v = choices[i][j], best = NEG;
            FOR(k, 0, szn) {
                int w = choices[i + 1][k];
                int add = abs(v - w) == 1;
                best = max(best, add + dp[i + 1][k]);
            }
            dp[i][j] = best;
        }
    }
    int bestTotal = *max_element(all(dp[0]));
    vi ans(N);
    int prefix = 0, prev = -1;
    FOR(i, 0, N) {
        FOR(idx, 0, choices[i].size()) {
            int v = choices[i][idx];
            int total = (i == 0) ? dp[i][idx] : prefix + (abs(prev - v) == 1) + dp[i][idx];
            if (total == bestTotal) {
                ans[i] = v;
                if (i) prefix += (abs(prev - v) == 1);
                prev = v; break;
            }
        }
    }
    cout << bestTotal << "\n";
    FOR(i, 0, N) {
        cout << ans[i] << " ";
    }
}

int32_t main() {
    vangtruong; int tcs = 1;
    while (tcs--) { solve(); } hihihaha; return 0;
}