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

void input() {
    int a,b; cin >> a >> b;
    vi A(a,0), B(b,0);
    FOR(i,0,a) cin >> A[i];
    FOR(i,0,b) cin >> B[i];
    if(a <= 1){
        cout << "YES\n"; return;
    }
    int p1 = INT_MAX, p2 = INT_MAX;
    sort(B.begin(), B.end());
    p1 = A[0];
    p2 =  B[0] - A[0];
    int cur = min(p1,p2);
    FOR(i,1,a){
        p1 = INT_MAX; p2 = INT_MAX;
        if(A[i] >= cur){
            p1 = A[i];
        }
        int target = (cur + A[i]);
        // debug(i); debug(target);
        auto it = lower_bound(B.begin(), B.end(), target);
        if(it != B.end()){
            // debug(*it);
            p2 = *it - A[i];
        }
        int temp = min(p1,p2);
        if(temp == INT_MAX){
            cout << "NO\n";
            return;
        }
        cur = temp;
    }
    cout << "YES\n";
    
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