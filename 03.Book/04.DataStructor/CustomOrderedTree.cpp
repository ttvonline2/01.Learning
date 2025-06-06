#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define hihihaha //*** debug ***//
#define debug(x) //*** debug ***//
#define DB(...) //*** debug ***//
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;
#define int long long
#define oo 9e18
#define MP make_pair
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define ROR(_i,_b,_a) for(int _i = (_b); _i >= (_b); _i--)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)
#define all(x) (x).begin(), (x).end()
using vb = vector<bool>; using vvb = vector<vb>; using vi = vector<int>; using vvi = vector<vi>; using vs = vector<string>; using vpi = vector<pair<int,int>>;
using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int,int>; int itemp = 0; string stemp = ""; using vvpi = vector<vector<pair<int,int>>>;
#else
#include "D:/01.Learning/01.Algorithms/debug2.h"
#endif
//**************************** CODING SPACE ****************************//
// Các structor có thể xài:
struct Rank {
    int elo;
    int username;
    int user_id;

    // bool operator<(const Rank& n) const {
    //     if (a == n.a) return b < n.b;
    //     return a < n.a;
    // }

    // bool operator==(const Rank& n) const {
    //     return a == n.a && b == n.b && c == n.c;
    // }

    friend ostream& operator<<(ostream& os, const Rank& n) {
        return os << n.elo << " " << n.user_id << " " << n.username;
    }
};

struct CompareByElo {
    bool operator()(const Rank& a, const Rank& b) const {
        if (a.elo != b.elo) return a.elo < b.elo;
        return a.user_id < b.user_id;
    }
};
template <typename T, typename Comp>
using ordered_set_custom = tree<T, null_type, Comp, rb_tree_tag, tree_order_statistics_node_update>;
void solve() {
    ordered_set_custom<int, greater<int>> oset; // thay vì greater có thể xài less<int>, less_equal<int>
    FOR(i,0,10){oset.insert(2*i); oset.insert(2*i);}
    debug(oset);
    auto x = oset.find_by_order(5); // Tìm vị trí thứ 5 của set
    auto y = oset.order_of_key(12); // số phần tử bên trái của 12 (không tính 12) --> kq: 3
    // debug(oset.)
    debug(*x);
    debug(y);

    Rank r = {123,123,444};
    debug(r);

}

int32_t main() {
    vangtruong; int tcs = 1;
    while (tcs--) {solve();} hihihaha; return 0; }

// Note: 
// 1. order_of_key(X) trả về Số lượng phần tử bên trái của X. Không tính X
// 2. find_by_order(POS) trả về itoritor tại phần tử thứ POS.
// 3. erase(find_by_order(POS))
