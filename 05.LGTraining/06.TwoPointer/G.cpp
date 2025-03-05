#if 1
#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define hihihaha //*** debug ***//
#define debug(x) //*** debug ***//
#define DB(...) //*** debug ***//
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
vector<pi> M; 

void solve() {
    int n, m; cin >> n >> m; M.clear(); M.resize(m); // pos + temp
    FOR(i,0,m) cin >> M[i].first; FOR(i,0,m) cin >> M[i].second; vi Use; 
    sort(M.begin(),M.end()); Use.push_back(0); // use first con
    FOR(i,1,m) { 
        debug(Use);
        // try replace
        while(!Use.empty()){
            pi tp = M[Use.back()];
            bool isReplace = tp.second - M[i].second >= M[i].first - tp.first;
            if(isReplace) Use.pop_back();
            else break;
        }
        // check add
        if(Use.empty()){
            Use.push_back(i); continue;
        }
        pi tp = M[Use.back()];
        bool isAdd = tp.second + (M[i].first - tp.first) >= M[i].second;
        if(isAdd) Use.push_back(i);
    }
    debug(Use);
    int cur = 0; 
    FOR(i,1,n+1){
        int nd1 = M[Use[cur]].second + abs(M[Use[cur]].first - i);
        if(cur == Use.size()-1){
            cout << nd1 << " "; continue;
        }
        int nd2 =  M[Use[cur+1]].second + abs(M[Use[cur+1]].first - i);
        if(nd2 <= nd1) cur++;
        cout << min(nd1,nd2) << " ";
    }
    cout << "\n";
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();} hihihaha; return 0; }