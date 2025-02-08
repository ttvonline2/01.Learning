#if 1
#define ON_DEBUG 0
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std; using namespace __gnu_pbds;
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

int BinarySearch_Smallest_k(vector<int>& A, int target) {
    if(A.size() == 0) return -1;
    int n = A.size();
    int k = n - 1;
    for (int b = n / 2; b >= 1; b /= 2) {
        while (k - b >= 0 && A[k - b] >= target) k -= b;
    }
    if (A[k] == target) {
        return k;
    }
    return -1;
}

void input() {
    int n; cin >> n;
    // vi A,B;
    vi A,B;
    FOR(i,0,n){
        int x,y; cin >> x >> y;
        if(y == 0){
            A.push_back(x);
        } else {
            B.push_back(x);
        }
    }
    sort(A.begin(), A.end()); sort(B.begin(), B.end()); 
    debug(A); debug(B);
    int ans = 0;
    // scan x
    FOR(i,0,A.size()){
        int x = A[i];
        int k = BinarySearch_Smallest_k(B,x);
        if(k != -1){
            ans += B.size() -1;
            ans += A.size() -1;
        }
        if(BinarySearch_Smallest_k(B,x+1) != -1 &&BinarySearch_Smallest_k(B,x-1) != -1) ans++;
    }

    FOR(i,0,B.size()){
        int x = B[i];
        if(BinarySearch_Smallest_k(A,x+1) != -1 &&BinarySearch_Smallest_k(A,x-1) != -1) ans++;
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