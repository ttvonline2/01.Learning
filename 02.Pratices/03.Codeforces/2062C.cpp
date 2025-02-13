#include <iostream>
#include <vector>
#include <cstdlib>  // abs, llabs
#include <algorithm>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
 
        // Nếu n == 1 thì chỉ có dãy ban đầu.
        if(n == 1){
            cout << arr[0] << "\n";
            continue;
        }
 
        // Candidate 0: không làm gì, tổng của dãy ban đầu.
        long long sum0 = 0;
        for(auto x : arr)
            sum0 += x;
        long long ans = sum0;
 
        // Mô phỏng từ 1 đến n-1 phép sai phân.
        // Với mỗi bước, tổng của dãy kết quả (sau sai phân) là:
        // nếu không đảo ngược, tổng = (phần tử cuối - phần tử đầu)
        // Nhưng do được phép đảo ngược, ta có thể đạt giá trị tuyệt đối của tổng.
        vector<long long> current = arr;
        for (int k = 1; k < n; k++){
            vector<long long> next;
            for (int i = 0; i < (int)current.size() - 1; i++){
                next.push_back(current[i+1] - current[i]);
            }
            current = next;
 
            // Tính tổng của dãy hiện tại.
            long long s = 0;
            for(auto x : current)
                s += x;
 
            long long candidate = llabs(s);
            ans = max(ans, candidate);
        }
 
        cout << ans << "\n";
    }
 
    return 0;
}
