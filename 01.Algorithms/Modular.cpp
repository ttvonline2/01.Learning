#include "D:/05.Learning/01.Algorithm/01.Algorithms/debug.h"
//**************************** CODING SPACE ****************************//

// Hàm tính (x^y) % m bằng phương pháp luỹ thừa nhị phân
int powerMod(int x, int y, int m) {
    int res = 1;
    x %= m;  // Giảm giá trị x nếu x >= m
    while (y > 0) {
        if (y & 1) res = (res * x) % m;  // Nếu y lẻ, nhân x vào kết quả
        x = (x * x) % m;  // Bình phương x
        y >>= 1;  // Chia y cho 2
    }
    return res;
}

// Hàm tính (a / b) % m khi m là số nguyên tố
int divMod(int a, int b, int m) {
    return (a * powerMod(b, m - 2, m)) % m;  // Fermat's Little Theorem
}











// Hàm mở rộng của thuật toán Euclid để tìm nghịch đảo modulo
long long extendedGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    long long x1, y1;
    long long gcd = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// Hàm tìm nghịch đảo modulo của b theo m (áp dụng Euclid mở rộng)
long long modInverse(long long b, long long m) {
    long long x, y;
    long long g = extendedGCD(b, m, x, y);
    if (g != 1) {
        cout << "Không tồn tại nghịch đảo modulo!\n";
        return -1; // Không tồn tại nếu gcd(b, m) ≠ 1
    } else {
        return (x % m + m) % m; // Đảm bảo giá trị dương
    }
}

// Hàm tính (a / b) % m khi m không cần phải là số nguyên tố
long long divMod_M_not_prime(long long a, long long b, long long m) {
    long long b_inv = modInverse(b, m);
    if (b_inv == -1) return -1; // Nếu không có nghịch đảo, trả về -1
    return (a * b_inv) % m;
}