#if 1
#define LOCAL 1
#include <bits/stdc++.h>
using namespace std;

//*** debug(x) ***//
#define debug(x)             \
    cout << "[" << #x << "]" \
         << " : " << (x) << endl

#if LOCAL
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr> &operator<<(basic_ostream<Ch, Tr> &os,
                                  Container const &x) {
    os << "{ ";
    for (auto &y : x) os << y << ", ";
    return os << "}";
}

template <class X, class Y>
ostream &operator<<(ostream &os, pair<X, Y> const &p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T>
void check_here(T x) {
    cout << "------------- " << x << " -------------" << endl;
}
#endif

//*** define ***//
#define int long long
#define pb push_back
#define FOR(_i, _a, _b) for (int _i = (_a); _i < (_b); _i++)
#define FORI(_i, _a, _b) for (int _i = (_a); _i <= (_b); _i++)
#define FORE(it, x) for (auto it = x.begin(); it != x.end(); ++it)

//*** custom using ***//
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

#endif
//**************************** CODING SPACE ****************************//

bool isValid(vi vt) {
    if (vt[0] == vt[1] + vt[2]) {
        return true;
    }
    return false;
}

int32_t main() {
#if LOCAL
    freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/input.txt",
            "r", stdin);
    freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/output.txt",
            "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    vi vt(3);
    while (T--) {
        cin >> vt[0] >> vt[1] >> vt[2];
        bool isoke = false;
        sort(vt.begin(), vt.end());
        do {
            // debug(vt);
            if (isValid(vt)) {
                isoke = true;
                break;
            }
        } while (next_permutation(vt.begin(), vt.end()));
        if (isoke) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}