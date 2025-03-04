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

#define vangtruong  freopen("D:/01.Learning/00.Ultility/input.txt", "r", stdin); freopen("D:/01.Learning/00.Ultility/output.txt", "w", stdout); auto start_time = high_resolution_clock::now() ; thread timeThread(timer_limitation); timeThread.detach()
#define hihihaha auto end_time = high_resolution_clock::now();  auto duration_time = duration_cast<milliseconds>(end_time - start_time); cout << "Running time: " << duration_time.count() << " ms\n" ; finished_program = true
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


#if OFF_DEBUG
#define DB(...) //*** debug ***//
#else
// Vector<vector>>
template <typename T>
void DB(const vector<vector<T>>& _arr, string name = "", string SPACE = " ") {
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

// Vector 
template <typename T>
void DB(const vector<T>& arr, string name = "", string SPACE = " ") {
    // Print index header
    cout << name  << " Size: [" << arr.size() << "]\n";
    // Print column indices
    cout <<  "[Index]" << SPACE << "\t";
    for (int i = 0; i < arr.size(); i++) cout << i << SPACE << "\t";
    cout << "\n";

    // Print values
    cout <<  "[Value]" << SPACE << "\t";
    for (const auto& val : arr) {
        cout << val << SPACE << "\t";
    }
    cout << "\n--- END Vector debug ---\n";
}


// mutiple args
void DB(string name, auto... args) {
    cout << name << ": ";
    ((std::cout << args << ","), ...);
    std::cout << '\n';
}

#endif



void timer_limitation() {
    this_thread::sleep_for(chrono::seconds(2)); // Đợi 1 giây
    if (!finished_program){cout << "Code Lỗi rồi fen > 2000ms\n"; exit(0);}
    exit(0);
}