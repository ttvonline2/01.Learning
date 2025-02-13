#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("D:/05.Learning/01.Algorithm/00.Ultility/input.txt", "r", stdin); freopen("D:/05.Learning/01.Algorithm/00.Ultility/output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> x(n), y(n);
        // Đọc mảng x
        for (int i = 0; i < n; i++){
            cin >> x[i];
        }
        // Đọc mảng y
        for (int i = 0; i < n; i++){
            cin >> y[i];
        }
        // Đọc ký tự ẩn: 'A' hoặc 'B'
        char hidden;
        cin >> hidden;
        
        // In ra đáp án: theo định dạng yêu cầu của bài tương tác: "! A" hoặc "! B"
        cout << "! " << hidden << "\n";
    }
    return 0;
}
