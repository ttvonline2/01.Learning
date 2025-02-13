#if 1
#define ON_DEBUG 1
#include<bits/stdc++.h>
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
void makePrefix(vi& A){
    for(int i = 1; i < A.size(); i++){
        A[i] += A[i-1];
    }
}
void input() {
    int n,l,r; cin>> n >> l >> r; vi arr(n,0); l--; r--;
    vi A(1,0),B(1,0),C(1,0);
    FOR(i,0,n) {
        int a; cin >> a;
        if(i < l) {A.push_back(a); continue; };
        if(i <= r) {B.push_back(a); continue; };
        if(i < n) {C.push_back(a); continue; };
    }
    sort(A.begin(), A.end()); sort(B.begin(), B.end()); sort(C.begin(), C.end());
   
    makePrefix(A);  makePrefix(B);makePrefix(C);
    // debug(A); debug(B); debug(C);
    int ans = B.back();
    FORI(k, 1, min(A.size()-1,B.size()-1)){
        int sum = B[B.size()-1-k] + A[k];
        // debug(sum);
        ans = min(ans, sum);
    }
    FORI(k, 1, min(B.size()-1,C.size()-1)){
        int sum = B[B.size()-1-k] + C[k];
        ans = min(ans, sum);
    }
    cout << ans << "\n";
}

void solve() {
    
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("D:/05.Learning/01.Algorithm/00.Ultility/input.txt", "r", stdin); freopen("D:/05.Learning/01.Algorithm/00.Ultility/output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int tcs = 1; cin >> tcs;
    while (tcs--) {
        input();
        solve();
    }
    return 0;
}