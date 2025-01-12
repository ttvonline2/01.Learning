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
int n,m;
string S = "";
vvi A;
vvi R,C;
void input() {
    cin >> n >> m;
    A.clear(); A.resize(n,vi(m,0));
    cin >> S;
    R.clear(); C.clear(); 
    R.resize(2,vi(n,0));
    C.resize(2,vi(m,0));
    for(int r = 0 ; r < n ; r++){
        for(int c = 0 ; c < m; c ++){
            cin >> A[r][c];
            R[0][r] += A[r][c];
            C[0][c] += A[r][c];
        }
    }


}
void processRC(int r, int c) {
    // cout << "r,c " << r << ", " << c << "\n";
    if(R[1][r] == 1) {
        A[r][c] = 0 - R[0][r];
        R[0][r] += A[r][c];
        C[0][c] += A[r][c];
        C[1][c]--;  R[1][r] = 0;
    }
    if(C[1][c] == 1& R[1][r] > 1) {
        A[r][c] = 0 - C[0][c];
        R[0][r] += A[r][c];
        C[0][c] += A[r][c];
        C[1][c] = 0;  R[1][r]--;
    }
}
void solve() {
    //preprocess/ upte R-C[1]
    int r = 0, c = 0;
    R[1][r]++; C[1][c]++;
    for(auto x: S){
        if(x == 'R') c++;
        if(x == 'D') r++;
        R[1][r]++; C[1][c]++;
    }

    //
    r = 0, c = 0;
    processRC(r,c);
    for(auto x: S){
        if(x == 'R') c++;
        if(x == 'D') r++;
        processRC(r,c);
    }
    // debug(A);
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cout << A[r][c] << " ";
        }
        cout << "\n";
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("D:/05.Learning/01.Algorithm/00.Ultility/input.txt", "r", stdin); freopen("D:/05.Learning/01.Algorithm/00.Ultility/output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int tcs = 0; cin >> tcs;
    while (tcs--) {
        input();
        solve();
    }
    return 0;
}
