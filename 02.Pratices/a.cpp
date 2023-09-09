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

int N,Pa,Pb;
int Sa,Sb;
vi X,Y;
int getWare(int x){
    //cout << "x: " << x << " , " << abs(Pa - x) << " - " << abs(Pb -x) << "\n";
    if(abs(Pa - x) < abs(Pb - x)){
        return 1;
    } else if (abs(Pa - x) > abs(Pb -x)){
        return 2;
    } else {
        return 0;
    }
}
void solve(){
    Sa = 0; Sb = 0;
    Y.clear();
    for(auto x : X){
        if(getWare(x) == 1){
            //cout << "Sa: " << x << "\n";
            Sa += 2*abs(Pa - x);
        } else if (getWare(x) == 2){
            //cout << "Sb: " << x << "\n";
            Sb += 2*abs(Pb - x);
        } else {
            Y.push_back(x);
        }
        //cout << Sa << " " << Sb << "\n";
    }
    for(auto x: Y){
        if(Sa <= Sb){
            Sa += 2*abs(Pa - x);
        } else {
            Sb += 2*abs(Pb - x);
        }
    }
}

int32_t main() {
#if LOCAL
    freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/input.txt", "r", stdin);
    freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
        int T;
    cin >> T;
    while(T--){
        cin >> N >> Pa >> Pb;
        X.clear(); X.resize(N,0);
        for(auto& x : X) cin >> x;
        sort(X.begin(),X.end());
        //debug(X);
        solve();
        cout << Sa + Sb << " " << abs(Sa - Sb) << "\n";
        //debug(Y);
    }

    return 0;
}