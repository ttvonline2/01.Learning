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
int n, k;
vi arr;

int getP(){
    int res = 0;
    FOR(i,0,n){
        FOR(j,i,n){
            int s = INT_MAX;
            FOR(v,i,j+1){
                s = min(s, arr[v]);
            }
            res += s;
        }
    }
    return res;
}
void find_kth_permutation(int n, int k) {
    vector<int> p(n);
    iota(p.begin(), p.end(), 1); // p = [1, 2, ..., n]

    int count_permutations = (1LL * n * (n + 1)) / 2; // Tổng số hoán vị tối ưu có thể tạo ra

    if (k > count_permutations) {
        cout << -1 << '\n';
        return;
    }

    for (int i = n; i > 0; i--) {
        if (k > i) {
            reverse(p.end() - i, p.end());
            k -= i;
        }
        if (k == 1) break;
    }

    for (int num : p) cout << num << " ";
    cout << '\n';
}

void input() {
    cin >> n >> k; arr.clear(); arr.resize(n);
    // FOR(i,1,n+1)arr[i-1] = i;
    // debug(getP());
    // int cnt = 0;
    // if(getP() == 56) {
    //     cnt++;
    // }
    // while(next_permutation(arr.begin(), arr.end())){
    //     debug(getP());
    //     if(getP() == 56) cnt++;
    // }
    // debug(cnt);
}

void solve() {
    find_kth_permutation(n,k);
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