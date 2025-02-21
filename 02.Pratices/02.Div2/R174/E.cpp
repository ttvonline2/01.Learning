#include <bits/stdc++.h>
using namespace std;
 
// Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int a, b, ab, ba;
        cin >> a >> b >> ab >> ba;
 
        int n = s.size();
        int cntA = 0, cntB = 0;
        for(char c: s){
            if(c=='A') cntA++;
            else cntB++;
        }
        // Frequency condition:
        if(cntA != a + ab + ba || cntB != b + ab + ba){
            cout << "NO\n";
            continue;
        }
 
        // Split s into maximal segments of alternating letters.
        vector<string> segs;
        for(int i = 0; i < n; ){
            int j = i;
            while(j+1 < n && s[j] != s[j+1]) j++;
            segs.push_back(s.substr(i, j-i+1));
            i = j+1;
        }
 
        // Process segments with length >=2.
        long long fixedAB = 0, fixedBA = 0; // from odd-length segments (no flexibility)
        long long evenAB_default = 0, evenBA_default = 0; // from even segments if using full pairing
        // For even segments, store the flexibility value d = L - 1.
        vector<int> flexA; // segments starting with A (default gives AB blocks)
        vector<int> flexB; // segments starting with B (default gives BA blocks)
 
        long long totPairs = 0; // total pairs if we use full pairing in every alternating segment.
 
        for(auto &seg: segs){
            int L = seg.size();
            if(L < 2) continue;
            if(L % 2 == 1){
                // Odd-length segment: forced partition.
                int pairs = L/2; // floor(L/2)
                totPairs += pairs;
                if(seg[0]=='A'){
                    fixedAB += pairs;
                } else {
                    fixedBA += pairs;
                }
            } else {
                // Even-length segment.
                int pairs = L/2; // full pairing option
                totPairs += pairs;
                if(seg[0]=='A'){
                    evenAB_default += pairs;
                    flexA.push_back(L - 1); // d = L-1 (là số lẻ)
                } else {
                    evenBA_default += pairs;
                    flexB.push_back(L - 1);
                }
            }
        }
 
        // Số cặp (pair) cuối cùng phải bằng (ab + ba).
        int requiredPairs = ab + ba;
        // Ở các đoạn chẵn ta chỉ có thể “giảm” tối đa 1 cặp mỗi đoạn.
        if(requiredPairs > totPairs || requiredPairs < totPairs - (int)(flexA.size() + flexB.size())){
            cout << "NO\n";
            continue;
        }
 
        int r = totPairs - requiredPairs; // số lượng đoạn chẵn cần giảm
 
        // Tính phân bố mặc định của các cặp:
        long long defAB = fixedAB + evenAB_default; // block AB mặc định
        long long defBA = fixedBA + evenBA_default; // block BA mặc định
        long long diffDef = defAB - defBA;        // hiệu số mặc định
        long long targetDiff = ab - ba;             // hiệu số cần đạt
        // Ta cần dùng việc giảm để thay đổi hiệu số theo:
        // diffFinal = diffDef + [(tổng từ các đoạn giảm kiểu B) - (tổng từ các đoạn giảm kiểu A)] = targetDiff.
        // Đặt T = targetDiff - diffDef.
        long long Tval = targetDiff - diffDef;
 
        // Lưu ý về parity:
        // Mỗi giá trị trong flexA, flexB đều là số lẻ, nên hiệu chỉnh thu được có parity = (r mod 2).
        if(((Tval % 2) + 2) % 2 != (r % 2)){
            cout << "NO\n";
            continue;
        }
 
        // Sắp xếp các vector linh hoạt và tính tiền tổng (prefix sums) để “quét” các lựa chọn.
        sort(flexA.begin(), flexA.end());
        sort(flexB.begin(), flexB.end());
        int szA = flexA.size(), szB = flexB.size();
 
        vector<long long> preA(szA+1, 0), preB(szB+1, 0);
        for (int i = 0; i < szA; i++){
            preA[i+1] = preA[i] + flexA[i];
        }
        for (int i = 0; i < szB; i++){
            preB[i+1] = preB[i] + flexB[i];
        }
 
        bool possible = false;
        // Giả sử ta chọn Y đoạn từ flexA (các đoạn bắt đầu bằng A – mỗi khi giảm sẽ làm hiệu chỉnh giảm đi dương d)
        // và X = r - Y từ flexB (mỗi khi giảm từ đây sẽ làm hiệu chỉnh tăng lên d).
        // Khi đó, ta cần:
        //   sum(chọn từ flexB) - sum(chọn từ flexA) = Tval.
        // Vì các số đều dương, ta có thể “biên” được giá trị tối thiểu và tối đa theo từng split.
        int lowY = max(0, r - szB);
        int highY = min(r, szA);
        for (int Y = lowY; Y <= highY; Y++){
            int X = r - Y;
            if(X < 0 || X > szB) continue;
            // Tối đa: chọn X số lớn nhất từ flexB và Y số nhỏ nhất từ flexA.
            long long sumB_max = (X == 0 ? 0LL : preB[szB] - preB[szB - X]);
            long long sumA_min = (Y == 0 ? 0LL : preA[Y]);
            long long maxAdj = sumB_max - sumA_min;
 
            // Tối thiểu: chọn X số nhỏ nhất từ flexB và Y số lớn nhất từ flexA.
            long long sumB_min = (X == 0 ? 0LL : preB[X]);
            long long sumA_max = (Y == 0 ? 0LL : preA[szA] - preA[szA - Y]);
            long long minAdj = sumB_min - sumA_max;
 
            if(Tval >= minAdj && Tval <= maxAdj){
                possible = true;
                break;
            }
        }
 
        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}
