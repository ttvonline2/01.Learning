#define ON_DEBUG 1
#if 1
#ifdef ONLINE_JUDGE
#include<bits/stdc++.h>
#else
#include "D:/01.Learning/01.Algorithms/debug2.h"
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

void input() {
    int n; cin >> n;
    string s; cin >> s;
    vi A(4,0);
    for(auto c: s){
        if(c == 'N') A[0] ++;
        if(c == 'S') A[1] ++;
        if(c == 'E') A[2] ++;
        if(c == 'W') A[3] ++;
    }
    // debug(A);
    string ans = s;
    int y = A[0] - A[1], x = A[2] - A[3]; 
    if(y %2 ==0 & x%2 == 0) {
        x/=2; y/=2;
        if(x == y && x == 0){
            vi R = A; 
            FOR(i,0,4) R[i] /= 2;
            if(A[0] == 1 && A[2] == 1){
                R[0] = 1; R[1] = 1;
            }
            for (auto& c : ans) {
                if (c == 'N' && R[0] >0) R[0]--, c = 'R';
                if (c == 'S' && R[1] >0) R[1]--, c = 'R';
                if (c == 'E' && R[2] >0) R[2]--, c = 'R';
                if (c == 'W' && R[3] >0) R[3]--, c = 'R';
            }
            for(auto& c: ans) if(c != 'R') c = 'H';
        }  else {
            if(y >0) {
                // mark x diem 'N' cho R
                for(auto& c: ans) {
                    if(c == 'N') {
                        c = 'R'; y--;
                        if(y == 0) break;
                    }
                }
            } else if(y < 0) {
                for(auto& c: ans) {
                    if(c == 'S') {
                        c = 'R'; y++;
                        if(y == 0) break;
                    }
                }
            }
            // x
            if(x >0) {
                // mark x diem 'E' cho R
                for(auto& c: ans) {
                    if(c == 'E') {
                        c = 'R'; x--;
                        if(x == 0) break;
                    }
                }
            } else if (x < 0){
                for(auto& c: ans) {
                    if(c == 'W') {
                        c = 'R'; x++;
                        if(x == 0) break;
                    }
                }
            }
            for(auto& c: ans) if(c != 'R') c = 'H';
        }
        if(ans.find('H') == -1 || ans.find('R') == -1) cout << "NO\n";
        else cout << ans << "\n";
    } else {
        cout << "NO\n";
    }
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