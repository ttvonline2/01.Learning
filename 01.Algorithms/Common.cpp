#include "D:/05.Learning/01.Algorithm/01.Algorithms/debug.h"
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
    return true;
}