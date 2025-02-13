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
    int n; cin >> n;
    map<int,int> mp;
    FOR(i,0,n) {
        int x; cin >> x; mp[x]++;
    }
    // quet >= 4;
    vi s;
    for(auto x: mp){
        if(x.second >= 4) {
            FOR(i,0,4) cout << x.first <<" ";
            cout << "\n"; return;
        }
        if(x.second >=2) {
            s.push_back(x.first);
        }
    }
    if(s.size() >= 2){
        cout << s[0] << " " << s[0] << " " << s[1] << " " << s[1] << "\n";
        return;
    }
    // cnt_pair
    if(s.size() == 0) {
        cout << "-1\n"; return;
    }

    // cnt = 1
    mp[s[0]] -= 2; // remove pair
    // make a new array;
    vi A;
    for(auto x: mp){
        if(x.second > 0) A.push_back(x.first);
    }
    // debug(A);
    // 
    FOR(i,0,A.size()-1) {
        int cur = A[i], target = A[i+1];
        // debug(value);
        if(target < 2*s[0] + cur) {
            cout << s[0] << " " << s[0] << " " << cur << " " 
            << target << "\n";
            return;
        }
    }

    // 
    cout << "-1\n";
    
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