#if 1
#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define debug(x) //*** debug ***//
#define debugVi(x) //*** debug ***//
#define debugVvi(x) //*** debug ***//
#else
#include "D:/05.Learning/01.Algorithm/01.Algorithms/debug.h"
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
    int n,m; cin >> n >> m;
    vector<vector<pi> > adj(n+1);
    vvi dis(n+1,vi(2,INF)); dis[1][0] = 0; dis[1][1] = -1;
    FOR(i,0,m){
        int a,b,w; cin >> a >> b >> w;
        adj[a].push_back(MP(b,w));
        adj[b].push_back(MP(a,w));
    }
    priority_queue<pi> Q; Q.push(MP(0,1));
    vb isVisited(n+1,0);
    while(!Q.empty()){
        int a = Q.top().second; Q.pop();
        if(isVisited[a]) continue; // đã xử lý, khác đỉnh gốc
        isVisited[a] = true;
        for(auto v: adj[a]){
            int b = v.first, w = v.second;
            if (dis[a][0] + w < dis[b][0]) {
                dis[b][0] = dis[a][0] + w;
                dis[b][1] = a; // a là cha của b
                Q.push({-dis[b][0],b});
            }
        }
    }
    // debugVvi(dis);
    if(dis[n][0] == INF) cout << "-1\n";
    else {
        vi ans;
        int cur = n;
        while(cur != -1){
            ans.push_back(cur);
            cur = dis[cur][1];
        }
        reverse(ans.begin(), ans.end());
        for(auto x: ans) cout << x << " ";
    }
}

int32_t main() {
    vangtruong; int tcs = 1; 
    while (tcs--) {solve();}return 0; }