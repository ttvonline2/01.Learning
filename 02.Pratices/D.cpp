#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** debug(x) ***//
#define DEBUG 1

#if DEBUG
#define debug(x)             \
    cout << "[" << #x << "]" \
         << " : " << (x) << endl
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    os << "{ ";
    for (auto& y : x) os << y << ", ";
    return os << "}";
}
template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
#else
#define debug(x)
#endif

//*** START CODING ***//

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int nx, ny, nz;
string x, y, z;

const string cs = "RGB";

vvi cnt;

int findIndex(char c) {
    if (c == 'R') return 0;
    if (c == 'G') return 1;
    if (c == 'B') return 2;
    return 0;
}

void cntForString(int pos, string& s, vvi& cnt) {
    int n = s.size();

    for (int i = 0; i <= n - 2; i++) {
        if (s[i] == s[i + 1]) {
            int j = i + 1;
            while (j <= n - 1 and s[j] == s[i]) j++;
            j--;
            cnt[pos][findIndex(s[i])] += j - i;

            i = j - 1;
        }
    }
}

int getF(vvi& cnt) {
    int ans = 0;
    vi pm = {0, 1, 2};
    do {
        ans += cnt[0][pm[0]] * cnt[1][pm[1]] * cnt[2][pm[2]];

    } while (next_permutation(all(pm)));
    return ans;
}

void getSubDelta(string& s, set<vi>& st, char R, char G){
    int n = s.size();
    //D[a][b] --> a = tang G (1 hoac 2). b la giam cua R (0,1,2);
    vvb D(2,vb(3,false));
    //First index
    if(s[0] == R){
        if(s[1] == G) D[0][0] = true;
    }
    //Last
    if(s[n-1] == R){
        if(s[n-2] == G) D[0][0] = true;
    }
    // mid
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == R) {
            int a = 0, b = 0;
            if (s[i - 1] == G) a++;
            if (s[i + 1] == G) a++;
            if (s[i - 1] == R) b++;
            if (s[i + 1] == R) b++;

            if (a > 0) {
                D[a - 1][b] = true;
            }
        }
    }
    //add
    int indexR = findIndex(R), indexG = findIndex(G);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if (D[i][j] == true) {
                vi temp = { 0,0,0 };
                temp[indexR] = -j; // R giam
                temp[indexG] = i+1;// G tang
                st.insert(temp);
            }
        }
    }
}


void getDelta(string& s, set<vi>& st) {
    getSubDelta(s,st, 'R','G');  getSubDelta(s,st, 'R','B');
    getSubDelta(s,st, 'G','R');  getSubDelta(s,st, 'G','B');
    getSubDelta(s,st, 'B','R');  getSubDelta(s,st, 'B','G');
}

void solve() {
    cin >> nx >> ny >> nz;
    cin >> x >> y >> z;

    cnt = vvi(3, vi(3));

    cntForString(0, x, cnt);
    cntForString(1, y, cnt);
    cntForString(2, z, cnt);

    // debug(cnt);

    int ans = getF(cnt);
    // debug(ans);

    set<vi> stx, sty, stz;
    stx.insert({0, 0, 0});
    sty.insert({0, 0, 0});
    stz.insert({0, 0, 0});

    getDelta(x, stx);
    getDelta(y, sty);
    getDelta(z, stz);

    // debug(stx);
    // debug(sty);
    // debug(stz);

    // vvi cnt = cnt;

    for (auto e0 : stx) {
        for (auto e1 : sty) {
            for (auto e2 : stz) {
                cnt[0][0] += e0[0];
                cnt[0][1] += e0[1];
                cnt[0][2] += e0[2];

                cnt[1][0] += e1[0];
                cnt[1][1] += e1[1];
                cnt[1][2] += e1[2];

                cnt[2][0] += e2[0];
                cnt[2][1] += e2[1];
                cnt[2][2] += e2[2];
                int val = getF(cnt);
                // if (ans < val) {
                //     debug(val);
                //     debug(cnt);
                // }
                ans = max(ans, getF(cnt));

                cnt[0][0] -= e0[0];
                cnt[0][1] -= e0[1];
                cnt[0][2] -= e0[2];

                cnt[1][0] -= e1[0];
                cnt[1][1] -= e1[1];
                cnt[1][2] -= e1[2];

                cnt[2][0] -= e2[0];
                cnt[2][1] -= e2[1];
                cnt[2][2] -= e2[2];
            }
        }
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
