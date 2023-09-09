#include "bits/stdc++.h"
using namespace std;
int n, q, N;
vector<int> A;
void update(int pos, int value){
    pos += N;
    A[pos] = value;
    pos/=2;
    while(pos > 0){
        A[pos] = max(A[2*pos], A[2*pos+1]);
        pos/= 2;
    }
}
int query(int a, int b){  
    a += N; b+= N;
    int res = INT_MIN;
    while(a <= b){
        if(a % 2 == 1) res = max(A[a++],res);
        if(b % 2 == 0) res = max(A[b--],res);
        a/=2; b/=2;
    }
    return res;
}
int main(){
    cin >> n;
    N = 1 << ((int)ceil(log2(n)));
    A.resize(2*N, INT_MIN);
    int temp;
    for(int i = 0 ; i < n ; i ++){
        cin >> temp;
        update(i,temp);
    }
    cin >> q;
    int x,y,z;
    for(int i = 0 ; i  < q ; i ++){
        cin >> x >> y >> z;
        if(x == 1){
            update(y-1,z);
        } else {
            cout << query(y-1,z-1) << "\n";
        }
    }
    return 0;
}