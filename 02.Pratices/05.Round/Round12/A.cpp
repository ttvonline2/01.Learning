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
using vb = vector<bool>; using vvb = vector<vb>; using vi = vector<int>; using vvi = vector<vi>;
using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int,int>; int itemp = 0; string stemp = "";
#else
#include "D:/01.Learning/01.Algorithms/debug.h"
#endif
//**************************** CODING SPACE ****************************//

void solve() {
    int a, ta, b, tb; cin >> a >> ta >> b >> tb;
    string tm = ""; cin >> tm;
    int sm  = ((tm[0]-'0')*10+(tm[1]-'0'))*60 + (tm[3]-'0')*10+(tm[4]-'0');
    debug(sm);
    // luu mang xuat phat va den, B
    vi Bx, Bd;
    for(int i = 300; i < 1440; i+= b) Bx.push_back(i);
    for(auto x: Bx) Bd.push_back(x+tb);
    debug(Bx); debug(Bd); 
    int ans = 0;
    // neu xe di chuyen tu sm+1 cho den sm+ta-1 --> gap
    // Bd > sm
    // Bx < sm + ta
    int aa = sm; int bb = sm+ta; debug(bb);
    for(int i = 0 ; i < Bx.size() ; i++){
        if(max(Bx[i], aa) < min(Bd[i], bb)) ans++;
    }
    cout << ans;


}

int32_t main() {
    vangtruong; int tcs = 1; 
    while (tcs--) {solve();} hihihaha; return 0; }