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
#define all(x) (x).begin(), (x).end()
using vb = vector<bool>; using vvb = vector<vb>; using vi = vector<int>; using vvi = vector<vi>; using vs = vector<string>; using vpi = vector<pi>;
using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int,int>; int itemp = 0; string stemp = ""; using vvpi = vector<vpi>;
#else
#include "D:/01.Learning/01.Algorithms/debug2.h"
#endif
//**************************** CODING SPACE ****************************//
using node = array<int,3>;
vector<node> myVector;
void solve() {
    int intA = 1, intB = 2;
    string strA = "abc", strB = "def";
    pi piA = MP(12,34), piB = MP(45,67);
    vi viA = {1,2,3,4,5}, viB = {4,5,6,7};
    vs vsA = {"abc","def","add"}, vsB = {"das","hgf","qw"};
    vvi vviA; vviA.push_back(viA); vviA.push_back(viB);
    vpi vpiA; vpiA.push_back(piA); vpiA.push_back(piB);
    vvpi vvpiA; vvpiA.push_back(vpiA);vvpiA.push_back(vpiA); vvpiA[1].push_back(piB);
    // map<int,int> mii; mii[1] = 4; mii[5] =123; mii[2] = 654;
    map<int,string> mii; mii[1] = "4"; mii[5] ="dsaf"; mii[2] = "654";
    map<string,vi> mvi; mvi["adafa"] = viA; mvi["2"] = viB;
    map<string,pi> mpi; mpi["adafa"] = piA; mpi["2"] = piB;
    multiset<int> mtsA; mtsA.insert(1); mtsA.insert(2); mtsA.insert(2);
    queue<int> qA; qA.push(1); qA.push(2); qA.push(4); qA.push(1);

    node d = {1, 2, 3};
    myVector.push_back(d);
    // priority_queue<int, vector<int>, greater<int>> qA; qA.push(5); qA.push(2); qA.push(3); qA.push(4);

    // priority_queue<int> qA; qA.push(5); qA.push(2); qA.push(3); qA.push(4);

    // debug(piA,piB, intA,strA);
    // debug(vsA,piA);
    // DB(vpiA);
    DB(qA);
    // DB(mvi); DB(mpi);

    debug(myVector);

    // 
    vvi va; va.push_back({1,2,3}); va.push_back({4,5,6,7});
    sort(all(va),[](vi&a, vi&b) {
        return a.size() >  b.size();
    });
    DB(va);
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();} hihihaha; return 0; }