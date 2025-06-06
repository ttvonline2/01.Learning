#define ON_DEBUG 1
#if 1
#ifdef ONLINE_JUDGE
#include<bits/stdc++.h>
#else
#include "D:/01.Learning/01.Algorithms/debug2.h"
#endif
using namespace std;

#if ON_DEBUG
//*** debug(x) ***//
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl
#else
#define debug(x) //*** debug ***//
#endif

template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) {
    os << "{ ";
    for(auto& y : x)os << y << ", ";
    return os << "}";
}

template <class X, class Y>
ostream & operator << (ostream & os, pair <X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")" ;
}

//*** define ***//
#define int long long
#define PB push_back
#define MP make_pair
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORI(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)

//*** custom using ***//
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using pi = pair<int,int>;
using vvp = vector<vector<pi> >;

#endif
//**************************** CODING SPACE ****************************//
int n; 
vi arr;
set<int> s;
void input() {
    cin >> n;
    arr.clear(); arr.resize(n); s.clear();
    FOR(i,0,n) cin >> arr[i];
}

void solve() {
    vi ans(n);
    int c = 2e5 + 10;
    FOR(i,0,n){
        int a = arr[i];
        if(s.find(a) == s.end()){
            s.insert(a);
            ans[i] = a; 
        } else {
            ans[i] = -1;
        }
    }
    // scan ;
    vi check(n+1);
    for(auto x: s) check[x] = 1;
    int cnt = 1;
    for(auto& x: ans) {
        if(x == -1) {
            while(cnt <= n && check[cnt] == true){
                cnt++;
            }
            x = cnt++;
        }
    }
    for(auto x: ans) cout << x << " ";
    cout << "\n";
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/input.txt", "r", stdin); freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int tcs; cin >> tcs;
    while (tcs--) {
        input();
        solve();
    }
    return 0;
}