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
int n,k;
vi arr;
void input() {
    cin >> n >> k; arr.clear(); arr.resize(n+1);
    FOR(i,1,n+1) cin >> arr[i];
} 

void solve() {
    int v = 1;
    FOR(i,1,k+1){
        // range from i --> i + (n-k+i)
        //  debug(i); debug(v);
        if(i % 2 == 1) {
            int m = v;
            while( m < n && (k -i) <= (n-m) ){
                // debug(m);
                if(arr[m+1] != (i+1)/2){
                    cout << (i+1)/2 << "\n";
                    return;
                }
                m++;
            }
            v++; // chi lay 1 phan tu tai vi tri k le
        } else {
            int l = v;
            if(arr[l] != i/2) {
                cout << (i / 2)  << "\n";
                return;
            }
            l++;
            // debug(l);
            while(l < n && (k-i) <= (n-l)){
                if(arr[l] != arr[l-1] + 1){
                    cout << arr[l-1]+1 << "\n";
                    return;
                }
                l++;
            }
            v++;
        }
    }
    cout << (k/2 + 1) << "\n";
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