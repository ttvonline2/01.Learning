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
// I need to create a subset by using backtracking and bit representation
int k;
void input() {
    cin >> k;
}
void generatesubsetRecursion(int level, vi& subset) {
    if(level == k) {
        debug(subset);
        return;
    }
    // gensubset have level
    subset.push_back(level);
    generatesubsetRecursion(level+1, subset);
    subset.pop_back();
    generatesubsetRecursion(level+1, subset);
}

void generatingSubsetBitRepresentation() {
    bitset<64> bs(0);
    FOR(i,0,1 << k){
        bs = i;
        cout << "{ ";
        FOR(j,0,k){
            if(bs[j] == 1) cout << j << ", ";
        }
        cout << "}\n";
    }
}

void solve() {
    vi subset;
    generatesubsetRecursion(0,subset);
    generatingSubsetBitRepresentation();
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