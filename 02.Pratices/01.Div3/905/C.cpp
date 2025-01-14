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
int n, k;
vi arr;
void input() {
    cin >> n >> k;
    arr.clear(); arr.resize(n);
    for(auto&x: arr) {
        cin >> x;
        x = x%k;
    }
}

void solve() {
    if(k == 2){
        for(auto x: arr){
            if(x == 0) {
                cout << 0 << "\n";
                return;
            }
        }
        cout << "1\n";
    }
    else if(k == 4){
        int cnt = 0;
        int diff = 0;
        // tinh so chan trong day
        for(auto x: arr){
            if(x == 0) {
                cout << 0 << "\n";
                return;
            }
            if(x == 2) cnt++;
            diff = max(diff, x);
        }
        if(cnt >= 2){
            cout << "0\n";
            return;
        }
        if(cnt == 1) {
            cout << "1\n";
            return;
        }
        if(4 - diff < 2){
            cout << (4 - diff) << "\n";
            return;
        }
        cout << "2\n";
        return;
    } else {
        int diff = 0;
        for(auto x: arr){
            if(x ==0) {
                cout << 0 << "\n";
                return;
            }
            diff = max(diff, x);
        }
        cout << k - diff << "\n";

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