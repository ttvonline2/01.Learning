#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
inline int query(const vector<int>& pref, int L, int R) {
    if(L > R) return 0;
    return pref[R] - (L ? pref[L-1] : 0);
}
 
inline int queryAB(const vector<int>& pref, int L, int R) {
    if(L > R) return 0;
    return pref[R+1] - pref[L];
}
 
string s;
int n, half;
 
vector<int> F, Fpref;
 
vector<vector<int>> freq;
 
vector<vector<int>> A_pref, B_pref;
 
void precompute() {
    n = s.size();
    half = n/2;
 
    freq.assign(26, vector<int>(n+1, 0));
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        for (int x = 0; x < 26; x++) {
            freq[x][i+1] = freq[x][i];
        }
        freq[c][i+1]++;
    }
 
    F.resize(half);
    for (int p = 0; p < half; p++) {
        F[p] = (s[p] != s[n-1-p]);
    }
    Fpref.resize(half);
    if(half > 0) Fpref[0] = F[0];
    for (int p = 1; p < half; p++) {
        Fpref[p] = Fpref[p-1] + F[p];
    }
 
    A_pref.assign(26, vector<int>(half+1, 0));
    B_pref.assign(26, vector<int>(half+1, 0));
    for (int p = 0; p < half; p++) {
        int a = s[p] - 'a';
        int b = s[n-1-p] - 'a';
        for (int x = 0; x < 26; x++){
            A_pref[x][p+1] = A_pref[x][p];
            B_pref[x][p+1] = B_pref[x][p];
        }
        A_pref[a][p+1]++;
        B_pref[b][p+1]++;
    }
}
 
inline int sumF(int L, int R) {
    if(L > R) return 0;
    return query(Fpref, L, R);
}
 
bool candidateCheck(int L, int R) {
    int supply[26] = {0};
    for (int x = 0; x < 26; x++) {
        supply[x] = freq[x][R+1] - freq[x][L];
    }
    int p1_low = max(n - 1 - R, 0);
    int p1_high = min(L - 1, n - 1 - L);
 
    int p2_low = L;
    int p2_high = min({R, n - 1 - R - 1, half - 1});
 
    int demand[26] = {0};
    if(L > 0 && p1_low <= p1_high){
        for (int x = 0; x < 26; x++){
            demand[x] += queryAB(A_pref[x], p1_low, p1_high);
        }
    }
    if(p2_low <= p2_high){
        for (int x = 0; x < 26; x++){
            demand[x] += queryAB(B_pref[x], p2_low, p2_high);
        }
    }
    for (int x = 0; x < 26; x++){
        if(demand[x] > supply[x]) return false;
    }
 
    int S_total = sumF(0, half - 1);
    int I1_low = max(L, 0), I1_high = min(R, half - 1);
    int S1 = (I1_low <= I1_high ? sumF(I1_low, I1_high) : 0);
    int I2_low = max(n - 1 - R, 0), I2_high = min(n - 1 - L, half - 1);
    int S2 = (I2_low <= I2_high ? sumF(I2_low, I2_high) : 0);
    int I_int_low = max(I1_low, I2_low), I_int_high = min(I1_high, I2_high);
    int S_int = (I_int_low <= I_int_high ? sumF(I_int_low, I_int_high) : 0);
    int fixedMismatch = S_total - (S1 + S2 - S_int);
    if(fixedMismatch != 0) return false;

    return true;
}
 
int solveOne() {
    precompute();
    if(sumF(0, half - 1) == 0) return 0;
    int lo = 1, hi = n, ans = n;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        bool possible = false;
        for (int L = 0; L + mid - 1 < n; L++){
            int R = L + mid - 1;
            if(candidateCheck(L,R)){
                possible = true;
                break;
            }
        }
        if(possible){
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        cin >> s;
        cout << solveOne() << "\n";
    }
    return 0;
}
