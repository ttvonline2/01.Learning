#if 1
#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define hihihaha //*** debug ***//
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
const int MOD = 1e9+7;
const int MAX_N = 1000000;
int fact[MAX_N + 1], invFact[MAX_N + 1];

// Hàm tính lũy thừa a^b mod MOD
int power(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

// Tiền xử lý giai thừa và nghịch đảo modular
void precomputeFactorials() {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= MAX_N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invFact[MAX_N] = power(fact[MAX_N], MOD - 2, MOD); // Fermat
    for (int i = MAX_N - 1; i > 0; i--) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }
}

// Hàm tính tổ hợp C(n, k) % MOD
int combMod(int n, int k) {
    if (k > n) return 0;
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

// Hàm tính C(n, k) sử dụng công thức không dùng giai thừa
int comb(int n, int k) {
    if (k > n) return 0;
    if (k > n - k) k = n - k; // Tận dụng tính đối xứng C(n, k) = C(n, n-k)

    int res = 1;
    for (int i = 0; i < k; i++) {
        res = res * (n - i) / (i + 1);
    }
    return res;
}