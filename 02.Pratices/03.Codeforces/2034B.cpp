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

int n,k,m, cnt;

int getAns(int a) {
    if(a < k) return 0;
    int b = 2*(k-1) + m;
    int res = a/b; if(a % b!=0) res++;
    return res;
}
void input() {
    string s; cin >> n >> k >> m;
    cnt = k-1;
    int ans = 0;
    cin >> s;
    FOR(i,0,n) {
        // debug(cnt);
        if(s[i] == '1') cnt = max(cnt, i+k);
        if(s[i] == '0') {
            if(i < cnt) continue;
            ans ++;
            cnt += m + k-1;
        }
    }
    cout << ans <<"\n";
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