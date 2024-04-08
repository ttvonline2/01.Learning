#if 1
#define ON_DEBUG 0
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
int T, N;
vi D,R;
string S;
int MAX_VALUE = 10e14;

bool isWin(int X){
    debug(X);
    for(int i = 0 ; i < N ; i ++){
        X = X - D[i];
        if(X <= 0) return false;
        if(S[i] == '+'){
            X = X + R[i];
        } else {
            X = X * R[i];
            if(X < 0){
                X = MAX_VALUE;
            }
        }
    }
    return true;
}

void BinarySearch_Largest_k() {
    int n = MAX_VALUE;
    int k = 0;
    for (int b = n / 2; b >= 1; b /= 2) {
        // debug(b); debug(k);
        while (k + b < n && (isWin(k+b) == false) ) k += b;
    }
    cout << k + 1 << "\n";

}


void solve() {
    cin >> N;
    D.clear(); R.clear(); D.resize(N); R.resize(N); S ="";
    for(auto &x: D) cin >> x;
    cin >> S;
    for(auto &x: R) cin >> x;
    BinarySearch_Largest_k();

}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../00.Ultility/input.txt", "r", stdin); freopen("../00.Ultility/output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}