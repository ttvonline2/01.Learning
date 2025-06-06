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

#endif
//**************************** CODING SPACE ****************************//
int n,m;
vi res;
vvi arr;
void input() {
    cin >> n >> m;
    arr.resize(n+1,vi(m+1));
    res.resize(n+1,1);
    FOR(r,1,n+1){
        FOR(c,1,m+1){
            cin >> arr[r][c];
        }
    }
}

void solve() {
    int ans = 0;
    FOR(r,1,n+1){
        ans ^= arr[r][res[r]];
    }
    if(ans == 0) {
        // chang one indicator of a row.
        FOR(r,1,n+1){
            int firstElement = arr[r][1];
            FOR(c,2,m+1){
                if(arr[r][c] != firstElement){
                    res[r] = c;
                    cout << "TAK\n";
                    FOR(i,1,n+1) {
                        cout << res[i] << " ";
                    }
                    return;
                }
            }
        }
    }
    if(ans > 0){
        cout << "TAK\n";
        FOR(i, 1, n + 1) {
            cout << res[i] << " ";
        }
        return;
    }
    cout << "NIE\n";
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