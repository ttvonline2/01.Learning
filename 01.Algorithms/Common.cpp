#include "bits/stdc++.h"
using namespace std;

class Common {
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
