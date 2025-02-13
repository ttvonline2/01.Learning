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
vi D = {9, 99,999,9999,99999,999999,9999999,99999999,999999999};

bool isHaveSeven(int a){
    while(a > 0){
        if(a %10 == 7) return true;
        a /= 10;
    }
    return false;
}
int check(int a){
    int res = 0;
    if(isHaveSeven(a)) return 0;
    queue<pi> A; A.push(MP(a,0));
    int x = 0; pi p;
    while (!A.empty()){
        p = A.front(); A.pop();
        for(int i = 0 ; i < 10 ; i++){
            x = p.first + D[i];
            if(x > 1e13+1) continue;
            if(isHaveSeven(x)){
                // debug(x);
                return p.second+1;
            }

            A.push(MP(x, p.second+1));
            // debug(p.first);
        }
    }
    return -1;
}
void input() {
    int n; cin >> n;
    cout << check(n) << "\n";
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