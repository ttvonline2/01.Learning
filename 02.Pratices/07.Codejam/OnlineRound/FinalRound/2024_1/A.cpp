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
int M,N;
vector<vector<pi>> adj;
vi dx = {0, 0,1,0,-1};
vi dy = {0,-1,0,1,0};
vi dis;
vvi A;
bool isValid(int y, int x) {
    if(y <0 || x < 0 || y >= M || x >= N) return false;
    return true;
}
int getDinh(int y, int x) {
    return (y*N + x);
}
void dijkstra() {
    vb isVisited(N*M+1,0);
    dis.resize(N*M+1, oo);
    dis[0] = 0;
    multiset<pi> q;
    q.insert(MP(0,0));
    while(!q.empty()) {
        // get the last vertice () of the priority queue + remove
        int a = q.rbegin()->second; q.erase(--q.end());
        if(isVisited[a]) continue;
        isVisited[a] = true;
        //scan the adj list of vertice a;
        for(auto x : adj[a]){
            int b = x.first, w = x.second;
            // able to update the paths
            int newDis = dis[a] + w;
            if(newDis < dis[b]) {
                dis[b] = newDis;
            }
            q.insert(MP(-dis[b],b));
        }
    }
    debug(dis);
}
void printdata(){
    FOR(y,0,adj.size()){
        DB("------------ Dinh: --------", y);
        for(auto p: adj[y]){
            DB("v,w", p.first,p.second);
        }
    }
}
void solve() {
    cin >> M >> N; adj.resize(M*N); A.resize(M,vi(N));
    // dinh = y*N + x;
    FOR(y,0,M) {
        FOR(x,0,N) {
            int value; cin >> value; A[y][x] = value;
        }
    }

    FOR(y,0,M) {
        FOR(x,0,N) {
            int value = A[y][x];
            if(value == 0) continue;
            FOR(i,0,5){
                // i = cost
                int dir = (value + i)%5;
                int nx = x + dx[dir]; int ny = y + dy[dir];
               
                if(nx == x && ny == y) continue;
                if(isValid(ny,nx) == false) continue;
                if(getDinh(ny,nx) != N*M-1 && A[ny][nx] == 0) continue;
                // DB("getDinh,i,dir,A[]",getDinh(y,x),getDinh(ny,nx),ny,nx,i,dir,value);
                adj[getDinh(y,x)].push_back(MP(getDinh(ny,nx), i));
            }
        }
    }

    // DB(A);
    printdata();
    dijkstra();
    if(dis[N*M-1] == oo) cout << "-1";
    else cout << dis[N*M-1];
}

int32_t main() {
    vangtruong; int tcs = 1;
    while (tcs--) {solve();} hihihaha; return 0; }