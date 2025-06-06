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
#define gapWithNextPowerOf2(x) (x&-x) // 12 --> 4; 16 --> 16
#define _2mu(x) (1LL << (x))

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
int lowPowerOf2(int x) {
    if(x == 0) return 1;
    return 1 << (63 - __builtin_clzll(x));
}
//**************************** CODING SPACE ****************************//
vvi spt; // sparse table
vi arr;
int n, q;
void input() {
    cin >> n >> q;
    spt.resize((log2(n))+1);
    arr.resize(n);
    spt[0].resize(n); 
    FOR(i,0,n) cin >> arr[i], spt[0][i] = arr[i];
    int h = (int)(log2(n))+1;
    int l = log2(n)+1;
    FOR(j,1,(int)(log2(n))+1) {
        spt[j].resize(n-_2mu(j)+1);
        for(int i = 0; i < spt[j].size(); i ++) { 
            spt[j][i] = min(spt[j-1][i],spt[j-1][i+_2mu((j-1))]);
        }
    }
    debug(spt);
}

void solve() {
    FOR(i,0,q){
        int a, b; cin >> a >> b; a--; b--; // dem tu 0
        int k = lowPowerOf2(b-a+1);
        k = (log2(k)); // k is the size 0/1/2/3 tuong ung 1/2/4/8
        int v = b - _2mu(k) + 1 ; // size _2mu(k), end tai b --> b - 2mu(k) + 1
        int res = min(spt[k][a], spt[k][v]);
        cout << res << "\n";
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/input.txt", "r", stdin); freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int tcs = 1;
    while (tcs--) {
        input();
        solve();
    }
    return 0;
}