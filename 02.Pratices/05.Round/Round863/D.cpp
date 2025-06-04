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
bool cutAHaft(int& w, int&h, int& x, int&y){
    DB("w,h,x,y", w,h,x,y);
    // thu cat ben trai
    bool canLeft = x > h;
    bool canRight = x <= (w-h);
    if(canLeft == false && canRight == false) return false;
    if(canLeft) {
        debug("Cat trai");
        x -= h;
        w = w-h;
    } else {
        debug("Cat phai");
        w = w-h;
    }
    DB("w,h,x,y", w,h,x,y);
    int new_x = y; int new_y = w-x+1; x = new_x; y = new_y;
    swap(w,h);
    return true;
} 

void solve() {
    vi F(46,1); 
    for(int i = 2; i <46; i++) F[i] = F[i-1] + F[i-2];
    debug(F);
    int n, x,y; cin >>n >> y >> x;
    int h = F[n], w = F[n+1];
    for(int k=n; k>0; k--){
        bool result = cutAHaft(w,h,x,y);
        if(result == false) {
            cout << "NO\n"; return;
        }
    }
    cout << "YES\n" ;return;
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();} hihihaha; return 0; }