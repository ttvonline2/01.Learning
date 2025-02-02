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
int n,sum,v;
vi arr;
void input() {
    cin >> n; arr.clear(); arr.resize(n);
    sum = 0;
    for(auto&x: arr) {
        cin >> x;
        sum += x;
    }
    
}
bool update(int i){
    // if(arr[i] < 0) return false;
    int temp = arr[i] - v;
    arr[i] = v;
    arr[i+2] += temp;
    // if(arr[i+2] < 0) return false;
    return true;
}

void solve() {
    if(sum % n != 0) {
        cout << "NO\n";
        return;
    }
    v = sum / n;
    for(int i = 0 ; i < n-2; i++){
        if(update(i) == false){
            cout << "NO\n";
            return;
        }
    }
    for(auto x: arr) {
        if(v != x){
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
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
        // debug(arr);
    }
    return 0;
}
//https://codeforces.com/problemset/problem/2050/B