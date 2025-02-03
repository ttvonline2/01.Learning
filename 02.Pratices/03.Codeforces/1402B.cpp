    #define ON_DEBUG 0
    #if 1
    #ifdef ONLINE_JUDGE
    #include<bits/stdc++.h>
    #else
    #include "/Users/vangtruong/Documents/01.Learning/bits/stdc++.h"
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
    vvi dp;
    int convertVitamin(string st) {
        int res = 0;
        for(auto x: st) {
            res |= (1 << (x - 'A'));
        }
        return res;
    }
    void input() {
        int n; cin >> n;
        dp.clear(); dp.resize(8,vi(n+1,INT_MAX));
        for(int i = 0; i <n+1; i++) dp[0][i] = 0;
        for(int i = 0 ; i < n ; i ++){
            int prices; cin >> prices;
            string vitamin; cin >> vitamin;
            //convert vitamin to value
            int vtm = convertVitamin(vitamin);
            FOR(j,0,8){
                debug(j|vtm);
                dp[j|vtm][i+1] = min(dp[j|vtm][i+1], dp[j][i] + prices);
                dp[j][i+1] = min(dp[j][i+1], dp[j][i]);
            }
            
        }
        if(dp[7][n] == INT_MAX) cout << "-1\n";
        else cout << dp[7][n] << "\n";
        
    }

    void solve() {
        
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