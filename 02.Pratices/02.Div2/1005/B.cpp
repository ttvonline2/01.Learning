#if 1
#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define debug(x) //*** debug ***//
#define debugv(x) //*** debug ***//
#include<bits/stdc++.h>
#else
#include "D:/01.Learning/01.Algorithms/debug2.h"
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

void solve() {
    int n; cin >> n;
    vi A(n); FOR(i,0,n) cin >> A[i];
    // tạo một set chứa các phần tử giống nhau.
    map<int,int> m; set<int> s;
    for(auto x: A) m[x]++;
    for(auto x: m) {
        if(x.second > 1) s.insert(x.first);
    }
    if(n == 1){
        cout << "1 1\n"; return;
    }
    debug(s);
    if(m.size() == 1){
        cout << "0\n"; return;
    }
    
    // tìm đoạn l r size max;
    int l = -1, r = -1, dif = 0;
    vi B(n);
    FOR(i,0,n){
        if(i == 0){
            if(s.find(A[i]) != s.end()) B[i] = -1;
            else B[i] = 1;
        } else {
            if(s.find(A[i]) != s.end())B[i] = -1; 
            else{
                if(B[i-1] == -1) B[i] = 1;
                else B[i] = B[i-1]+1;
            }
        }
    }
    debug(B);
    // tim r;
    FOR(i,0,n) r = max(r,B[i]);
    debug(r);
    if(r == -1){
        cout << "0\n"; return;
    }
    // tim chinh xac r,l
    for(int i = n-1; i >= 0; i--){
        if(B[i] == r){
            l = i-r+2;
            r = i+1;
            cout << l << " " << r << "\n"; return;
        }
    }
    
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();}return 0; }