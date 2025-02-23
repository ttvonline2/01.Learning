#include "D:/05.Learning/01.Algorithm/01.Algorithms/debug.h"
//**************************** CODING SPACE ****************************//

// target = 3 --> { 1, 2, [2], 4, 5 }
// target = 2 --> { 1, 2, [2], 4, 5 }
int bs_k_lon_nhat__NHO_hon_target(vector<int>& A, int target, int st, int en) {
    if(A[st] > target) return -1ll; // tất cả giá trị [st,en] điều LỚN HƠN target;
    int _n = en - st + 1, _k = st;
    for (int b = _n / 2; b >= 1; b /= 2) while (_k + b <= en && A[_k + b] <= target) _k += b;
    return _k;
}

// target = 3 --> { 1, 2, 2, [4], 5}
// target = 2 --> { 1, [2], 2, 4, 5}
int bs_k_nho_nhat__LON_hon_target(vector<int>& A, int target, int st, int en) {
    if(A[en] < target) return -1ll; // tất cả giá trị [st,en] điều NHỎ HƠN target;
    int _n = en - st + 1, _k = en;
    for (int b = _n / 2; b >= 1; b /= 2) while (_k - b >= st && A[_k - b] >= target) _k -= b;
    return _k;
}

