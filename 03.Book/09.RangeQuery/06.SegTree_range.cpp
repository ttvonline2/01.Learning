#define ON_DEBUG 0
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
vi tree;
int n, q;

int sum(int a, int b) {
    a += n; b += n;
    int s = 0;
    while (a <= b) {
        if (a % 2 == 1) s += tree[a++];
        if (b % 2 == 0) s += tree[b--];
        a /= 2; b /= 2;
    }
    return s;
}

void add(int k, int x) {
    k += n;
    tree[k] += x; //Note: this is replace/ add += x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = tree[2 * k] + tree[2 * k + 1];
    }
}
void input() {
    cin >> n >> q;
    n++; // NOTE: this is for the last value update
    tree.resize(4*n);
    int temp = 0;
    FOR(i,0,n-1) {
        int x; cin >> x;
        if(i == 0) add(i,x), temp = x;
        else add(i,x-temp), temp = x;
    }
    add(n-1,0); // NOTE: this is for the last value update
    debug(tree);
}

void solve() {
    // debug(tree);
    FOR(i,0,q){
        int t; cin >> t;
        if(t == 1){
            int a,b,u; cin >> a >> b >> u; a--; b--;
            add(a,u); add(b+1,-u);
            debug(a); debug(b);
            debug(tree);
        } else {
            int k; cin >> k; k--;
            cout << sum(0,k) << "\n";
        }
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