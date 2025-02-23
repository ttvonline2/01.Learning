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
    int m; cin >> m;
    //
    int sum = (m+1)*m; sum /= 2; 
    if(sum&1) {
        cout << "NO\n";
        return;
    }
    sum/=2;
    cout << "YES\n";
    int cur = 0;
    vi set1;
    int n = m;
    // 
    while(cur + n <= sum){
        cur += n; n--;
    }
    // debug(n);
    // set 1: m --> n + 1// va them 1 so sum - cur;
    
    int s1 = m-(n+1)+1+1; int s2 = m-s1;
    
    if(sum-cur > 0){
        cout << s1 << "\n";
        cout << sum - cur << " ";
    } else {
        // debug(sum);
        
        s1--; s2++;
        cout << s1 << "\n";
    }
    
    FOR(i,n+1,m+1){
        cout << i << " ";
    }
    cout << "\n";
    //
    cout << s2 << "\n";
    FOR(i,1,n+1){
        if(i == (sum-cur)) continue;
        cout << i <<" ";
    }

}

void solve() {
    
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("D:/05.Learning/01.Algorithm/00.Ultility/input.txt", "r", stdin); freopen("D:/05.Learning/01.Algorithm/00.Ultility/output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int tcs = 1; 
    while (tcs--) {
        input();
        solve();
    }
    return 0;
}