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
string s, t; int n,m; vector<string> A;
vvi Direct = {
    {1,0}, 
    {-1,0}, 
    {0,1},
    {0,-1},
    {1,1},
    {-1,-1},
    {1,-1},
    {-1,1}
};
bool check(vi&D, int x, int y) {
    FOR(i,0,s.size()) {
        if(i == s.size() -1 && A[y][x] == s[i]) return true;
        if( A[y][x] != s[i]) return false;
        y += D[0]; x+= D[1];
        if(y < 0 || y >= n || x < 0 || x >= m) return false;
    }
    return false;
}

void solve() {
    cin >> s;  cin >> n >> m; A.clear(); A.resize(n);
    FOR(i,0,n) {cin >> A[i];}
    FOR(y,0,n){
        FOR(x,0,m){
            FOR(k,0,8) {
                bool res = check(Direct[k],x,y);
                if(res == true) {
                    cout << "1\n"; return;
                }
            }
        }
    }
    cout << "0\n"; return;
}

int32_t main() {
    vangtruong; int tcs = 1;
    while (tcs--) {solve();} hihihaha; return 0; }