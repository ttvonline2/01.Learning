#if 1
#define ON_DEBUG 0
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
int n, m, L, ans, cur_power, cur_pos, cur_m;
vector<pi> H,P;
priority_queue<int> pri;
void input() {
    ans = 0, cur_power = 1,cur_pos = 1, cur_m = 0;
    pri = priority_queue<int>();
    cin >> n >> m >> L;
    H.clear(); H.resize(n);
    P.clear(); P.resize(m);
    pi temp;
    FOR(i,0,n){
        cin >> temp.first >> temp.second;
        H[i] = temp;
    }
    FOR(i, 0, m) {
        cin >> temp.first >> temp.second;
        P[i] = temp;
    }
}
bool jump(int pos, int range) {
    //for(currnt i --> pos) collect all to pri
    for(int i = cur_m; i < m ; i ++){
        if(P[i].first <= pos){
            pri.push(P[i].second);
            cur_m=i;
        } else {
            cur_m = i;
            break;
        }
    }
    // cout << "Collected --> " << pri.size() << "\n";
    while(!pri.empty() && cur_power < range){
        cur_power += pri.top();
        pri.pop();
        ans += 1;
    }
    debug(cur_power);
    if(cur_power >= range){
        // cur_power -= range;
        return true;
    } else {
        return false;
    }
}

void solve() {
    for(auto x: H){
        int pos = x.first-1, range = x.second - pos + 1;
        if (jump(pos, range) == false){
            cout << "-1\n";
            return;
        }
        debug(cur_power);
    }
    cout << ans << "\n";
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