#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

int n;
vector<int> a; 
 
vector<unordered_map<int,int>> memo;
 
int F(int i, int x) {
    if(i > n) return 1; // Đã xét hết các vị trí.
    if(i == n) {
        int res = 0;
        if(a[i] == x) res = 1; 
        res = (res + 1) % MOD;
        return res;
    }
    if(memo[i].find(x) != memo[i].end()) return memo[i][x];
 
    long long res = 0;
    //  (H) 
    if(a[i] == x) {
        res += F(i+1, x);
        res %= MOD;
    }
    //  (L).
    if(i < n && a[i+1] == x+1) {
        res += F(i+2, x+1);
        res %= MOD;
    }
    memo[i][x] = (int) res;
    return memo[i][x];
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 #ifndef ONLINE_JUDGE
    freopen("D:/05.Learning/01.Algorithm/00.Ultility/input.txt", "r", stdin); freopen("D:/05.Learning/01.Algorithm/00.Ultility/output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        // Đọc mảng a từ vị trí 1 đến n.
        a.resize(n+1);
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        // Khởi tạo lại bộ nhớ cho memo
        memo.clear();
        memo.resize(n+3); // Sử dụng các chỉ số từ 1 đến n+2.
 
        int ans = F(1, 0) % MOD;
        cout << ans % MOD << "\n";
    }
    return 0;
}
