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
int T, N , C, B;
vi D,P,F;
vvi dp;

void input(){
    cin >> N >> B >> C;
    P.clear(); F.clear(); D.clear();
    P.resize(N); F.resize(N); D.resize(N);
    for (auto& x : P) cin >> x;
    for (auto& x : F) cin >> x;
    for (auto& x : D) cin >> x;
}

void tinhTai(int i, int x){
    dp[N-i][x] = dp[N-i+1][min(x+P[N-i], C)] + D[N-i]*F[N-i];

    if(x - D[N-i] >= 0) {
        dp[N-i][x] = min(dp[N-i][x], dp[N-i+1][x-D[N-i]]);
    }
   
}

void preCaculate(){
    // tinh dp truoc
    dp.clear(); dp.resize(N,vi(C+1,10e14));
    //xu ly dp[n-1][x]; x: C --> 0;

    for (int x = 0; x <= C; x++) {
        if(x > B) {
            if(x - D[N-1] >= B){
                dp[N-1][x] = 0;
            } else {
                dp[N-1][x] = D[N-1]*F[N-1];
            }
        } else {
            // Chac chan phai sac.
            if(x + P[N-1] >= B){
                dp[N-1][x] = D[N-1]*F[N-1];
            } else {
                // vo cung
            }
        }
    }

    debug(dp[N-1]);

    for (int i = 2; i <= N; i++) {
        for (int x = 0; x <= C; x++) {
            tinhTai(i,x);
        }
        debug(dp[i]);
    }

    //
    // dp[n - 2][x] = max :                     dp[n-1][max(x+P[n-2], C)] + D[n-2]*F[n-2]
    //                    : only x >= D[n-2] --> dp[n-1][x-D[n-2]];
}



void solve() {
    preCaculate();
    //check am
    for (int i = 0; i < N; i++) {
        for (int x = 0; x <= C; x++) {
            if(dp[i][x] < 0){
                while(1);
            }
        }
    }
    cout << dp[0][B] << "\n";
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../00.Ultility/input.txt", "r", stdin); freopen("../00.Ultility/output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while(T--){
        input();
        solve();
    }
    return 0;
}

//RUN 20% wa