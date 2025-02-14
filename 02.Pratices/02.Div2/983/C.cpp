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
    using vvp = vector<vector<pi> >;

    #endif
    //**************************** CODING SPACE ****************************//
    int n; vi arr;

    int findValue(vector<int>& A, int target) {
        int n = A.size();
        int k = n - 1;
        for (int b = n / 2; b >= 1; b /= 2) {
            while (k - b >= 0 && A[k - b] >= target) k -= b;
        }
        // debug(k);
        return k;
    }
    void input() {
        cin >> n; arr.clear(); arr.resize(n);
        FOR(i,0,n) cin >> arr[i];
        sort(arr.begin(), arr.end());
        // debug(arr);
        vi ans(n,INT_MAX), res(n,INT_MAX);
        int maxValue = arr[n-1];
        int last  = 0;
        FOR(i,0,n-1){
            int value = arr[i] + arr[i+1];
            if(value <= maxValue) {
                i == 0 ? ans[i] = 1 : ans[i] = ans[i-1] + 1; 
                int pos = findValue(arr,value);
                res[i]  = n - pos;
            } else {
                res[i] = 0;
                break;
                
            }
            // debug(i);
        }
        debug(arr);
        debug(ans); debug(res);
        int final = INT_MAX;
        // if(last == 0){
        //     if(ans[0] == res[0])
        //     final = min(res[0], ans[0]);
        // }
        final = res[0];
        FOR(i,1,n){
            final = min(final, res[i] + ans[i-1]);
        }
        if(final == INT_MAX) cout << "0\n";
        else cout << final << "\n";
    }

    void solve() {
        
    }

    int32_t main() {
    #ifndef ONLINE_JUDGE
        freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/input.txt", "r", stdin); freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/output.txt", "w", stdout);
    #endif
        ios_base::sync_with_stdio(false); cin.tie(nullptr);
        
        int tcs; cin >> tcs;
        while (tcs--) {
            input();
            solve();
        }
        return 0;
    }