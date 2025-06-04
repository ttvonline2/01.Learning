#pragma once
#include "vstd.h"
using namespace std;
using namespace std::chrono;

//*** debug(x) ***//
#if OFF_DEBUG
#define debug(x) //*** debug ***//
#else
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl
#endif
#define int long long
#define oo 9e18
#define MP make_pair
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORI(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)
using vb = vector<bool>; using vvb = vector<vb>; using vi = vector<int>; using vvi = vector<vi>; using vs = vector<string>;
using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int,int>; int itemp = 0; string stemp = "";


#define vangtruong  freopen("D:/01.Learning/00.Ultility/input.txt", "r", stdin); freopen("D:/01.Learning/00.Ultility/output.txt", "w", stdout); auto start_time = high_resolution_clock::now() ; thread timeThread(timer_limitation); timeThread.detach()
#define hihihaha auto end_time = high_resolution_clock::now();  auto duration_time = duration_cast<milliseconds>(end_time - start_time); cout << "\nRunning time: " << duration_time.count() << " ms\n" ; finished_program = true
template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) {
    os << "{ ";
    for(auto& y : x)os << y << ", ";
    return os << "}";
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

// mutiple args
template<typename... Args>
void DB(string name, Args... args) {
    cout << "[" << name << "] "; ((cout << args << " "), ...); cout << '\n';
}

void DB(const pi& p)  {
    cout << "{" << p.first << "," << p.second << "}\n";
}

// Vector<vector>>
void DB(const vector<vector<int>>& _arr, string name = "", string SPACE = " ") {
    int _maxSize = 0;
    for (const auto& x : _arr) _maxSize = max(_maxSize, static_cast<int>(x.size()));

    cout << name  << " :Size [R][C]: [" << _arr.size() << "][" << (_arr.empty() ? 0 : _arr[0].size()) << "]\n";

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
void DB(const vector<int>& arr, string name = "", string SPACE = " ") {
    cout << name  << " Size: [" << arr.size() << "]\n";
    cout <<  "[Index]" << SPACE << "\t";
    for (int i = 0; i < arr.size(); i++) cout << i << SPACE << "\t";
    cout <<  "\n[Value]" << SPACE << "\t";
    for (const auto& val : arr) cout << val << SPACE << "\t";
    cout << "\n--- END Vector<int> debug ---\n";
}

// Vector<bool>
void DB(const vector<bool>& arr, string name = "", string SPACE = " ") {
    cout << name  << " Size: [" << arr.size() << "]\n";
    cout <<  "[Index]" << SPACE << "\t";
    for (int i = 0; i < arr.size(); i++) cout << i << SPACE << "\t";
    cout <<  "\n[Value]" << SPACE << "\t";
    for (const auto& val : arr) cout << static_cast<int>(val) << SPACE << "\t";
    cout << "\n--- END Vector<bool> debug ---\n";
}

// Vector<pi>
void DB(const vector<pi>& arr, string name = "", string SPACE = " ") {
    cout << name  << " :Size [R][" << arr.size() << "] <pair>\n";
    for (size_t r = 0; r < arr.size(); r++) {
        cout << "" << SPACE << "[" << r << "]" << SPACE << "\t";
        DB(arr[r]);
    }
    cout << "--- END Vector<pi> debug ---\n";
}

// map<K,T>
template<typename K, typename T>
void DB(const map<K,T>& mm, string name = "") {
    cout << name  << " Size: [" << mm.size() << "]\n";
    for(auto& s: mm) cout << s.first << " - " << s.second << "\n";
    cout << "--- END map<int,T> debug ---\n";
}

#endif


void timer_limitation() {
    this_thread::sleep_for(chrono::seconds(2)); // Đợi 1 giây
    if (!finished_program){cout << "\nCode Lỗi rồi fen > 2000ms\n"; exit(0);}
    exit(0);
}