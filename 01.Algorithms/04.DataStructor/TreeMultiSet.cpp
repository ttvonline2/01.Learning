#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std; using namespace __gnu_pbds;

//**************************** CODING SPACE ****************************//

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> iMultiSet;
int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("D:/05.Learning/01.Algorithm/00.Ultility/input.txt", "r", stdin);freopen("D:/05.Learning/01.Algorithm/00.Ultility/output.txt", "w", stdout);
#endif
    int n, t; cin >> n; iMultiSet s; 
    for(int i = 0; i < n ; i++) cin >> t, s.insert({i,t});
    for(int i = 0 ; i < n ; i++) {
        cin >> t;
        auto it = s.find_by_order(t-1); cout << it->second << " ";
        s.erase(it);
    }
    return 0;
}