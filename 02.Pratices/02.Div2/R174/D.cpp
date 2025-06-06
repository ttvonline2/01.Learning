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
using vb = vector<bool>; using vvb = vector<vb>; using vi = vi; using vvi = vector<vi>;
using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int,int>; int itemp = 0; string stemp = "";
#endif
//**************************** CODING SPACE ****************************//
string vang = "";
int m, half;
vvi freq_v;
vi F, Fpref;
vvi A_pref, B_pref;

inline int queryAB(const vi& pref, int L, int R) {
    if(L > R) return 0;
    return pref[R+1] - pref[L];
}

bool check(int k){
    for (int L = 0; L <= m - k; L++){
        int R = L + k - 1;
        
        int I1_low = max(L, (int)0), I1_high = min(R, half - 1);
        int S1 = 0;
        if(I1_low <= I1_high)
            S1 = (I1_low==0 ? Fpref[I1_high] : Fpref[I1_high]-Fpref[I1_low-1]);
        // p t
        int I2_low = max(m - 1 - R, (int)0), I2_high = min(m - 1 - L, half - 1);
        int S2 = 0;
        if(I2_low <= I2_high)
            S2 = (I2_low==0 ? Fpref[I2_high] : Fpref[I2_high]-Fpref[I2_low-1]);
        // Giao
        int I_int_low = max(I1_low, I2_low), I_int_high = min(I1_high, I2_high);
        int S_int = 0;
        if(I_int_low <= I_int_high)
            S_int = (I_int_low==0 ? Fpref[I_int_high] : Fpref[I_int_high]-Fpref[I_int_low-1]);
        int S_total = (half > 0 ? Fpref[half-1] : 0);
        int mismatches_fixed = S_total - (S1 + S2 - S_int);
        if(mismatches_fixed != 0) continue; 
        int p1_low = max(m - 1 - R, (int)0);
        int p1_high = min(L - 1, m - 1 - L);
        int demand[26] = {0};
        if(L > 0 && p1_low <= p1_high){
            FOR(x,0,26){
                demand[x] += queryAB(A_pref[x], p1_low, p1_high);
            }
        }
        int p2_low = L;
        int p2_high = min({R, m - 1 - R - 1, half - 1});
        if(p2_low <= p2_high){
            FOR(x,0,26){
                demand[x] += queryAB(B_pref[x], p2_low, p2_high);
            }
        }
        int supply[26] = {0};
        FOR(x,0,26){
            supply[x] = freq_v[x][R+1] - freq_v[x][L];
        }
        bool valid = true;
        FOR(x,0,26){
            if(demand[x] > supply[x]) { valid = false; break; }
        }
        if(valid) return true;
    }
    return false;
}

//  BinarySearch_Small
int BinarySearch_Smallest_k(string& v) {
    int n = v.size();
    int k = n - 1;
    for (int b = n / 2; b >= 1; b /= 2) {
        while (k - b >= 0 && check(k - b) == true) k -= b;
    }
    return k;
}

void solve() {
    string s; 
    cin >> s;
    // Tìm tiền tố, hậu tố đã khớp
    int st = 0, kt = s.size() - 1;
    FOR(i,0,s.size()/2){
        if(s[i] == s[kt-i]) st++;
        else break;
    }
    kt = s.size() - st;
    // Cắt đoạn giữa cần sửa
    string v(s.begin()+st, s.begin()+kt);
    // Nếu v rỗng nghĩa là s đã là palindrome
    if(v.size() == 0) { cout << "0\n"; return; }
    vang = v;
    
    // --- Tiền xử lý trên vang ---
    m = vang.size(); 
    half = m/2;
    // Xây dựng mảng tần số cho vang (0-indexed)
    freq_v.assign(26, vi(m+1, 0));
    FOR(i,0,m){
        int c = vang[i]-'a';
        FOR(x,0,26){
            freq_v[x][i+1] = freq_v[x][i];
        }
        freq_v[c][i+1]++;
    }
    // Xây dựng mảng F cho các cặp (0<=p<half)
    F.resize(half);
    Fpref.resize(half);
    FOR(p,0,half){
        F[p] = (vang[p] != vang[m-1-p]);
        if(p==0) Fpref[p] = F[p];
        else Fpref[p] = Fpref[p-1] + F[p];
    }
    // Xây dựng A_pref và B_pref (1-indexed) cho p từ 0 đến half-1
    A_pref.assign(26, vi(half+1, 0));
    B_pref.assign(26, vi(half+1, 0));
    FOR(p,0,half){
        int a = vang[p]-'a';
        int b = vang[m-1-p]-'a';
        FOR(x,0,26){
            A_pref[x][p+1] = A_pref[x][p];
            B_pref[x][p+1] = B_pref[x][p];
        }
        A_pref[a][p+1]++;
        B_pref[b][p+1]++;
    }
    // --- Kết thúc tiền xử lý ---
    
    cout << BinarySearch_Smallest_k(v) << "\n";
}

int32_t main() {
    vangtruong; 
    int tcs = 1; 
    cin >> tcs;
    while (tcs--) { solve(); }
    return 0; 
}