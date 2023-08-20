#if 1
#define LOCAL 1
#include<bits/stdc++.h>
using namespace std;

//*** debug(x) ***//
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl

#if LOCAL
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

template<typename T>
void check_here(T x){
    cout << "------------- " << x << " -------------" << endl;
}
#endif

//*** define ***//
#define int long long
#define pb push_back
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

#endif
//**************************** CODING SPACE ****************************//
int l,r,mi,ma;
void findRight(vi& vt){
    r = -1;
    if(vt[l+1] < vt[l+2]){
        mi = vt[l+1]; ma = vt[l+2];
    } else {
        mi = vt[l+2]; ma = vt[l+1];
    }
    FOR(i,l+3,vt.size()){
        if(vt[i] < mi){
            mi = vt[i];
        } else if(vt[i] > ma){
            ma = vt[i];
        } else {
            r = i;
            while(++r < vt.size() && vt[r] < ma && vt[r] > mi){
            }
            r--;
            return;
        }
    }
}

void findLeft(vi& vt){
    l = -1;
    FOR(i,0,vt.size() - 2){
        if((vt[i] > vt[i+1] && vt[i] < vt[i+2])||(vt[i] < vt[i+1] && vt[i] > vt[i+2])){
            l = i;
            return;
        }
    }
}

void solve(vi& vt){
    findLeft(vt);
    if(l == -1){
        return;
    } else {
        findRight(vt);
    }
}

int32_t main() {
#if LOCAL
    freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/input.txt", "r", stdin);
    freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T, N; cin >> T;
    vi vt;
    while (T--){
        cin >> N;
        vt.clear(); vt.resize(N);
        FOR(i,0,N){
            cin >> vt[i];
        }
        if(N < 4){
            cout << "-1\n";
        } else {
            solve(vt);
            if(l == -1 || r == -1){
                cout << "-1\n";
            } else {
                cout << l+1 << " " << r+1 << "\n";
            }
        }
    }
    

    return 0;
}