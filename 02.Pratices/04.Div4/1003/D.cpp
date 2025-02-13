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
bool cmp (pi& a, pi& b){
    if(a.first == b.first){
        return a.second > b.second;
    }
    return a.first > b.first;
}
void input() {
    int n, m; cin >> n >> m;
    vi T(n),P(n);
    vi A(m);
    FOR(k,0,n){
        cin >> A[0];
        FOR(i, 1, m){
            int x; cin >> x; A[i] = A[i-1]+x;
        }
        // tinh T[k], P[k]
        int sum = 0;
        FOR(i,0,m) sum += A[i];
        P[k] = sum;
        T[k] = A[m-1];
    }
    // debug(T); debug(P);
    vector<pi> V(n);
    FOR(i,0,n) V[i] = MP(T[i],P[i]);
    sort(V.begin(), V.end(), cmp);
    // debug(V);
    int x = 0, t = 0;
    FOR(i,0,n){
        // debug(V[i].first);
        x += t*m + V[i].second;
        t += V[i].first;
    }
    cout << x << "\n";
    
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