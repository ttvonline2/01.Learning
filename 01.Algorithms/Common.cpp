#include "bits/stdc++.h"
using namespace std;

void debugVvi(vector<vector<long long>>& _arr) {
    int _maxSize = 0;
    for (auto x : _arr) _maxSize = _maxSize > x.size() ? _maxSize : x.size();
    cout << "Array size[R][C]: [" << _arr.size() << "][" << _arr[0].size() << "]\n";
    //print the index:
    cout << "   [R]   \t";
    for (int i = 0;i < _maxSize; i++) cout << i << "   \t";
    for (int r = 0; r < _arr.size(); r++) {
        cout << "\n   [" << r << "]   \t";
        for (int c = 0; c < _arr[r].size(); c++) {
            cout << _arr[r][c] << "   \t";
        }
    }
    cout << "\n--- END Array debug ---";
}


bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
// tìm k lớn nhất sao cho A[k] <= target. Nếu muốn nhỏ hơn thì thay  A[k + b] < target
int binarySearch_Largest_k(vector<int>& A, int target, int st = -1, int en = -1) {
    int _n = en == -1ll ? A.size() : en;
    int _k = st == -1ll ? 0 : st;
    for (int b = _n / 2; b >= 1; b /= 2) while (_k + b < _n && A[_k + b] <= target) _k += b;
    // return A[_k] == target ? _k : -1ll; // Nếu muốn return chỉ khi tìm thấy = k
    return A[_k] <= target ? _k : -1ll; // return vị trí k lớn nhất sao cho, k <= target
}
//  A[k - b] >= target is the condition
void BinarySearch_Smallest_k(vector<int> A, int target) {
    int n = A.size();
    int k = n - 1;
    for (int b = n / 2; b >= 1; b /= 2) {
        while (k - b >= 0 && A[k - b] >= target) k -= b;
    }
    if (A[k] == target) {
        // target found at index k
    }
}

// Tìm chỉ số lớn nhất k sao cho A[k] < target
// (Giả sử tồn tại ít nhất một phần tử A[k] < target, tức A[0] < target)
int BinarySearch_Largest_k_less(const vector<int>& A, int target) {
    int n = A.size();
    if (A[0] >= target) {
        return -1;
    }
    int k = 0;
    // Với mỗi bước nhảy b giảm dần, ta thử tăng k nếu vẫn giữ được A[k + b] < target
    for (int b = n / 2; b >= 1; b /= 2) {
        while (k + b < n && A[k + b] < target)
            k += b;
    }
    // Sau vòng lặp, k là chỉ số lớn nhất sao cho A[k] < target
    return k;
}

// Phiên bản dùng binary jump tìm chỉ số L (nhỏ nhất sao cho A[L] > target)
// sau đó kết luận chỉ số lớn nhất với A[k] > target là n-1.
void BinarySearch_Largest_k_greater_v2(const vector<int>& A, int target) {
    int n = A.size();
    if (A[n - 1] <= target) {
        return;
    }
    int L = n - 1;
    for (int b = n / 2; b >= 1; b /= 2) {
        while (L - b >= 0 && A[L - b] > target)
            L -= b;
    }
    // L là chỉ số nhỏ nhất sao cho A[L] > target, nên các chỉ số L, L+1, …, n-1 đều > target.
    // Vậy chỉ số lớn nhất thỏa là n-1.
    cout << "Largest index with A[k] > target: " << (n - 1) << endl;
}