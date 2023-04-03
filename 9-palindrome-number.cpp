#include <iostream>
#include <string>
#include <algorithm>
// performance measure header
#include <iomanip>
#include <chrono>

using namespace std;

// https://leetcode.com/problems/palindrome-number/

class Solution {
  public:
    // numeric solution without converting to string
    bool isPalindrome(int x) {
        if (x < 0) return false;
        //int reverse{0}, rem, input{x};
        int rem, input{x};
        long long reverse{0};
        while (x != 0) {
            rem = x % 10;
            reverse = reverse * 10 + rem;
            x /= 10;
        }
        return input == reverse;
    }
    // solution with string conversion
    bool isPalindromes(int x) {
        string s{to_string(x)}, r{s};
        reverse(r.begin(), r.end());
        return r.compare(s) == 0 ? true : false;
    }    
};

int main() {
    int x;
    bool isPalindrome;
    Solution sol;
    cout << "Insert a number: ";
    cin >> x;    

    auto t1 {chrono::high_resolution_clock::now()};
    isPalindrome = sol.isPalindrome(x);
    auto t2 {chrono::high_resolution_clock::now()};
    chrono::duration<double, milli> ms_double {t2 - t1};
    cout << setprecision(17) << ms_double.count() << " ms\n";
    cout << isPalindrome << '\n';

    return 0;
}