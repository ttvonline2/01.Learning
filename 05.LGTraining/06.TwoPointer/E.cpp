#if 1
#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define hihihaha //*** debug ***//
#define debug(x) //*** debug ***//
#define debugVvi(x) //*** debug ***//
#else
#include "D:/01.Learning/01.Algorithms/debug.h"
#endif
#include<bits/stdc++.h>
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
    int n,m,L; cin >> n>>m>>L; map<int,vi> Power; vector<pi> Hur(n); // start + need
    FOR(i,0,n){
        int a, b; cin >> a >> b; Hur[i] = MP(a-1,b-a+2); // diem nhay + need
    }
    FOR(i,0,m) {
        int a, b; cin >> a >> b; Power[a].push_back(b);
    }
    int curPower = 1; auto it_power = Power.begin();
    priority_queue<int> qStorge; int ans = 0;
    FOR(i,0,n){
        // add power to storage
        while(it_power != Power.end() && it_power->first <= Hur[i].first){
            for(auto p: it_power->second) qStorge.push(p);
            it_power++;
        }
        int need = Hur[i].second;
        while(curPower < need && !qStorge.empty()){
            // take power from storage
            curPower += qStorge.top(); qStorge.pop(); ans++;
        }
        if(curPower < need) {cout << "-1\n";return; }
    }
    cout << ans << "\n";

}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();} hihihaha; return 0; }