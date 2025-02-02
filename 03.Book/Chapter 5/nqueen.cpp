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

//https://leetcode.com/problems/n-queens/description/
int n;
vector<vector<string>> result;
vector<bool> column(n,false), diag1(n,false), diag2(n,false);
vector<string> res;

void preprocess(){
    res.resize(n, string(n, '.'));
    column.resize(n,false);
    diag2.resize(2*n+1,false);
    diag1.resize(2*n+1,false);
}
void solveQueen(int y){
    if(y == n) {
        result.push_back(res);
        debug(res);
        return;
    }
    for(int x = 0 ; x < n ; x ++){
        if(column[x] || diag1[x+y] || diag2[n-1-x+y]) continue;
        column[x] = diag1[x+y] = diag2[n-1-x+y] = 1;
        res[y][x] = 'Q';
        solveQueen(y+1);
        res[y][x] = '.';
        column[x] = diag1[x+y] = diag2[n-1-x+y] = 0;
    }
}

vector<vector<string>> solveNQueens(int n) {
    preprocess();
    solveQueen(0);
    return result;
}

void input() {
    
    }

    void solve() {
        cin >> n;
        auto x = solveNQueens(n);
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