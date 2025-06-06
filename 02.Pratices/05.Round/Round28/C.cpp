#if 1
#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define debug(x) //*** debug ***//
#define debugv(x) //*** debug ***//
#include<bits/stdc++.h>
#else
#include "D:/01.Learning/01.Algorithms/debug2.h"
#endif
using namespace std;
//*** define ***//
#define int long long
#define INF LONG_LONG_MAX
#define MP make_pair
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORI(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)
using vb = vector<bool>; using vvb = vector<vb>; using vi = vector<int>; using vvi = vector<vi>;
using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int,int>; int itemp = 0; string stemp = "";
#endif
//**************************** CODING SPACE ****************************//
string getSub(const string& ori, const string& sub){
    string res(ori.size(),'0');
    FOR(i,0,ori.size()){
        if(ori[i] == sub[i]) res[i] = '0';
        else res[i] = '1';
    }
    return res;
}
void solve() {
    string s; cin >> s;
    // tim ky tu 0 dau tien, tu trai qua
    bool isOnly1 = true;
    for(auto c: s) if(c == '0') isOnly1 = false;
    if(isOnly1) {
        cout << "1 " << s.size() << " 1 1\n";  return;
    }
    int v = s.size();
    FOR(i,0,s.size()) if(s[i] == '0'){v = i+1; break;}
    // -> size subs string  = 
    int sz = s.size() - v + 1;
    int ans = 0; 
    string cur = "";
    string ori = s.substr(s.size() - sz,sz);
    debug(sz);
    FOR(i,0,s.size()){
        if(i + sz > s.size() -1 ) break;
        string sub = s.substr(i,sz); // can uptimal
        if(cur == "") {
            cur = getSub(ori,sub); ans = 0; continue;
        }
        stemp = getSub(ori,sub);
        if(stemp > cur) {
        cur = stemp; ans = i;}
    }
    cout << "1 " << s.size() << " " << ans + 1 << " " << sz + ans << "\n";
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();}return 0; }