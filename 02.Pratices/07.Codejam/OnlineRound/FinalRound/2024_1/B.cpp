#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define hihihaha //*** debug ***//
#define debug(x) //*** debug ***//
#define DB(...) //*** debug ***//
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define oo 9e18
#define MP make_pair
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define ROR(_i,_b,_a) for(int _i = (_b); _i >= (_b); _i--)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)
using vb = vector<bool>; using vvb = vector<vb>; using vi = vector<int>; using vvi = vector<vi>; using vs = vector<string>;
using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int,int>; int itemp = 0; string stemp = "";
#else
#include "D:/01.Learning/01.Algorithms/debug.h"
#endif
//**************************** CODING SPACE ****************************//
struct Factory {
    int power, dia, pos, res;
};
int N,K; vi D, M;
vector<Factory> A;
bool cmp(Factory& a, Factory& b) {
    if(a.dia == b.dia) {
        return a.power < b.power;
    } else {
        return a.dia < b.dia;
    }
}

bool vvv(Factory& a, Factory& b) {
    return a.pos < b.pos;
}
void solve() {
    cin >> N; D.resize(N); M.resize(N); A.resize(N);
    Factory F; F.res = 0;
    for(auto& x: M) cin >> x;
    for(auto& x: D) cin >> x;
    cin >> K;
    debug(D);
    FOR(i,0,N) {
        F.pos = i; F.dia = D[i]; F.power = M[i];
        A[i] = F;
    }
    sort(A.begin(), A.end(), cmp);
    multiset<int> Q; int curQ = 0; int maxQ = A[0].dia;
    FOR(i,0,N){
        if(A[i].dia > maxQ) {
            A[i].res = curQ;
            maxQ = A[i].dia;
        } else {
            if(i >0) A[i].res = A[i-1].res;
        }
        if(Q.size() < K) {
            curQ += A[i].power;
            Q.insert(-A[i].power);
            int m = *Q.rbegin(); debug(m);
        } else {
            // remove nho nhat, them cai lon hon
            int m = *Q.rbegin(); debug(m);
            if(A[i].power > (-m)) {
                Q.erase(prev(Q.end()));
                Q.insert(-A[i].power);
                curQ += A[i].power +m;
            }
        }
    }
    sort(A.begin(), A.end(), vvv);
    FOR(i,0,N) {
        cout << A[i].res;
        if(i != N-1) cout << ",";
    }
}

int32_t main() {
    vangtruong; int tcs = 1;
    while (tcs--) {solve();} hihihaha; return 0; }