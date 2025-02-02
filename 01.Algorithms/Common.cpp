#include "bits/stdc++.h"
using namespace std;

class Common {

    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    
    //  A[k + b] <= target is the condition
    void BinarySearch_Largest_k(vector<int> A, int target) {
        int n = A.size();
        int k = 0;
        for (int b = n / 2; b >= 1; b /= 2) {
            while (k + b < n && A[k + b] <= target) k += b;
        }
        if (A[k] == target) {
            // target found at index k
        }
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
};
