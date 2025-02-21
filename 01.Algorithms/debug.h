#pragma once
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;

//*** debug(x) ***//
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl

#define vangtruong  freopen("D:/05.Learning/01.Algorithm/00.Ultility/input.txt", "r", stdin); freopen("D:/05.Learning/01.Algorithm/00.Ultility/output.txt", "w", stdout)
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

template <typename T>
void debugv(const vector<vector<T>>& _arr) {
    int _maxSize = 0;
    for (const auto& x : _arr) _maxSize = max(_maxSize, static_cast<int>(x.size()));

    cout << "Array size [R][C]: [" << _arr.size() << "][" << (_arr.empty() ? 0 : _arr[0].size()) << "]\n";

    // Print column indices
    cout << "   [R]   \t";
    for (int i = 0; i < _maxSize; i++) cout << i << "   \t";

    for (size_t r = 0; r < _arr.size(); r++) {
        cout << "\n   [" << r << "]   \t";
        for (size_t c = 0; c < _arr[r].size(); c++) {
            cout << static_cast<int>(_arr[r][c]) << "   \t"; // Ép kiểu về int
        }
    }
    cout << "\n--- END Array debug ---\n";
}

template <typename T>
void debugv(const vector<T>& arr) {
    // Print index header
    cout << "[" << arr.size() << "] i:  \t";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << i << "    \t";
    }
    cout << "\n";

    // Print values
    cout << "Value:  \t";
    for (const auto& val : arr) {
        cout << val << "    \t";
    }
    cout << "\n--- END Array debug ---\n";
}

// Template specialization cho vector<bool>
template <>
void debugv(const vector<bool>& arr) {
    cout << "Array size: " << arr.size() << "\n";

    cout << "Index:   ";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << i << "   ";
    }
    cout << "\n";

    cout << "Values:  ";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << (arr[i] ? "1" : "0") << "   ";  // Chuyển bool thành số
    }
    cout << "\n--- END Array debug ---\n";
}