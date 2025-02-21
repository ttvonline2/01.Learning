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
vi dx = { 0, 1, 0, -1};
vi dy = {-1, 0, 1,  0};
void solve() {
    int n, m; cin >> n >> m;
    vvi A(n,vi(m));
    FOR(i,0,n)
        FOR(j,0,m) cin >> A[i][j];
    // debugv(A);
    map<int,int> v;
    FOR(r,0,n){
        FOR(c,0,m){
            FOR(i,0,4){
                if(v.find(A[r][c]) == v.end()){
                    v[A[r][c]] = 1;
                }
                int newR = r + dy[i], newC = c + dx[i];
                if(newR < 0 || newR >= n) continue;
                if(newC < 0 || newC >= m) continue;
                if(A[newR][newC] == A[r][c]) v[A[r][c]]++;
            }
        }
    }
    vi C(2,0);
    for(auto x: v){
        x.second > 1 ? C[1]++ : C[0]++;
        // cout << x.first << ", " << x.second << "\n";
    }
    int ans = 0;
    if(C[1] == 0) {
        ans = C[0] - 1;
    } else {
        ans = 2*(C[1] - 1) + C[0];
    }
    cout << ans << "\n";
        
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();}return 0; }