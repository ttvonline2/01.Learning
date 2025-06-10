#pragma once
#include "vstd.h"
using namespace std;
using namespace std::chrono;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
//*** debug(x) ***//
#if OFF_DEBUG
#define debug(...) //*** debug ***//
#else
#define debug(...) cout << "[DEBUG] ";  _debug(#__VA_ARGS__, __VA_ARGS__)
#define DB(...) cout << "[DEBUG] ";_DB(#__VA_ARGS__, __VA_ARGS__)
// #define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl
#endif
#define int long long
#define oo 9e18
#define MP make_pair
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORI(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)
#define all(x) (x).begin(), (x).end()
#define CR(_x,_n) (_x).clear(); (_x).resize((_n))
using vb = vector<bool>; using vvb = vector<vb>; using vi = vector<int>; using vvi = vector<vi>; using vs = vector<string>;
using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int,int>; int itemp = 0; string stemp = "";
using vpi = vector<pi>; using vvpi = vector<vpi>;
template <typename T, typename Comp>
using ordered_set_custom = tree<T, null_type, Comp, rb_tree_tag, tree_order_statistics_node_update>; // Comp = less<int>, less_equal<int>, greater<int>, StructComp

#define vangtruong  freopen("D:/01.Learning/00.Ultility/input.txt", "r", stdin); freopen("D:/01.Learning/00.Ultility/output.txt", "w", stdout); auto start_time = high_resolution_clock::now() ; thread timeThread(timer_limitation); timeThread.detach()
#define hihihaha auto end_time = high_resolution_clock::now();  auto duration_time = duration_cast<milliseconds>(end_time - start_time); cout << "\nRunning time: " << duration_time.count() << " ms\n" ; finished_program = true
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    int i = 0, n = (int) distance(x.begin(), x.end());
    os << "{ ";
    for (const auto& y : x) os << y << (++i < n ? ", " : "");
    return os << " }";
}


template <class X, class Y>
ostream & operator << (ostream & os, pair <X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")" ;
}

bool finished_program = false;

// brd + A.cpp
#if OFF_DEBUG
#define DB(...) //*** debug ***//
#else

template <typename... Args>
void _debug(const char* names, Args&&... args) {
    string_view s(names);
    cout << " {";
    size_t i = 0, cnt = 0, n = sizeof...(args);
    auto next = [&]() {
        while (i < s.size() && (s[i] == ' ' || s[i] == ',')) ++i;
        size_t st = i;
        while (i < s.size() && s[i] != ',') ++i;
        return s.substr(st, i - st);
    };
    ((cout << next() << ": " << args << (++cnt < n ? ", " : "")), ...);
    cout << " }" << '\n';
}


void _DB(const pi& p)  {
    cout << "{" << p.first << "," << p.second << "}\n";
}

// Vector<vector>>
void _DB(const char* names,const vector<vector<int>>& _arr, string SPACE = " ") {
    cout << "[" << names << "]";
    int _maxSize = 0;
    for (const auto& x : _arr) _maxSize = max(_maxSize, static_cast<int>(x.size()));

    cout << " :Size [R][C]: [" << _arr.size() << "][" << (_arr.empty() ? 0 : _arr[0].size()) << "]\n";

    // Print column indices
    cout << SPACE << "[R]" << SPACE << "\t";
    for (int i = 0; i < _maxSize; i++) cout << i << SPACE << "\t";

    for (size_t r = 0; r < _arr.size(); r++) {
        cout << "\n" << SPACE << "[" << r << "]" << SPACE << "\t";
        for (size_t c = 0; c < _arr[r].size(); c++) {
            cout << static_cast<int>(_arr[r][c]) << SPACE << "\t"; // Ép kiểu về int
        }
    }
    cout << "\n--- END Vector<Vector> debug ---\n";
}

// Vector<int>
void _DB(const char* names,const vector<int>& arr, string SPACE = " ") {
    cout << "[" << names << "]" << " Size: [" << arr.size() << "]\n";
    cout <<  "[Index]" << SPACE << "\t";
    for (int i = 0; i < arr.size(); i++) cout << i << SPACE << "\t";
    cout <<  "\n[Value]" << SPACE << "\t";
    for (const auto& val : arr) cout << val << SPACE << "\t";
    cout << "\n--- END Vector<int> debug ---\n";
}

// Vector<bool>
void _DB(const char* names,const vector<bool>& arr, string SPACE = " ") {
    cout << "[" << names << "]" << " Size: [" << arr.size() << "]\n";
    cout <<  "[Index]" << SPACE << "\t";
    for (int i = 0; i < arr.size(); i++) cout << i << SPACE << "\t";
    cout <<  "\n[Value]" << SPACE << "\t";
    for (const auto& val : arr) cout << static_cast<int>(val) << SPACE << "\t";
    cout << "\n--- END Vector<bool> debug ---\n";
}

// Vector<pi>
void _DB(const char* names, const vector<pi>& arr, string SPACE = " ") {
    cout << "[" << names << "]" << " :Size [" << arr.size() << "] <pair>\n";
    for (size_t r = 0; r < arr.size(); r++) {
        cout << "" << SPACE << "[" << r << "]" << SPACE << "\t";
        _DB(arr[r]);
    }
    cout << "--- END Vector<pi> debug ---\n";
}

// Vector<vector<pi>> // adj do thi co trong so
void _DB(const char* names, const vvpi& arr, string SPACE = " ") {
    cout << "[" << names << "]" << " :Vertex count = [" << arr.size() << "]\n";
    for (size_t r = 0; r < arr.size(); r++) {
        cout << "" << SPACE << "\tVertex " << r << " --> size [" << arr[r].size() << "]\n";
        for (size_t v = 0; v < arr[r].size(); v++) {
            cout << "   " << SPACE << "[" << v << "]" << SPACE << "\t";
            _DB(arr[r][v]);
        }
    }
    cout << "--- END vector<vector<pi>> debug ---\n";
}




// map<K,T>
template<typename K, typename T>
void _DB(const char* names,const map<K,T>& mm) {
    cout << "[" << names << "]" << " Size: [" << mm.size() << "]\n";
    for(auto& s: mm) cout << s.first << " - " << s.second << "\n";
    cout << "--- END map<K,T> debug ---\n";
}

#endif

// Queue<T>
template<typename T>
void _DB(const char* names,const queue<T>& _q) {
    queue<T> q = _q;
    cout << "[" << names << "]" << " Size: [" << q.size() << "]\n";
    cout << " << [Front] ";
    while(!q.empty()){
        T t = q.front(); q.pop(); cout << t << (q.empty()? " [Back] <<\n" : ", ");
    }
}

// priority_queue<T>
template<typename T>
void _DB(const char* names,const priority_queue<T>& _q) {
    priority_queue<T> q = _q;
    cout << "[" << names << "]" << " Size: [" << q.size() << "]\n";
    cout << " << [Top] ";
    while(!q.empty()){
        T t = q.top(); q.pop(); cout << t << (q.empty()? " [Back] <<\n" : ", ");
    }
}


// priority_queue<T> revert
template<typename T>
void _DB(const char* names,const priority_queue<T, vector<T>, greater<T>>& _q) {
    priority_queue<T, vector<T>, greater<T>> q = _q;
    cout << "[" << names << "]" << " Size: [" << q.size() << "]\n";
    cout << " << [Top] ";
    while(!q.empty()){
        T t = q.top(); q.pop(); cout << t << (q.empty()? " [Back] <<\n" : ", ");
    }
}



void timer_limitation() {
    this_thread::sleep_for(chrono::milliseconds(500)); // Đợi 1 giây
    if (!finished_program){cout << "\nCode Lỗi TLE > 500ms\n"; exit(0);}
    exit(0);
}