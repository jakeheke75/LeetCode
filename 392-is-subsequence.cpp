#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// performance measure header
#include <iomanip>
#include <chrono>
using namespace std;

// https://leetcode.com/problems/is-subsequence/
// my proposed solution 
class Solution {
public:
    bool isSubsequence(string s, string t) {
        size_t idx {0};
        vector<size_t> index;
        for (char ch : s)
            for (; idx < t.size(); idx++)
                if (t[idx] == ch) {
                    index.push_back(idx);
                    idx++;
                    break;
                }
        return index.size() == s.size() && is_sorted(begin(index), end(index)) ?
            true : false;        
    }
};

// another solution far better performing than mine
/* class Solution {
public:
    bool isSubsequence(string s, string t) {
        size_t i {0};
        for (char c : t) {
            if (i >= s.size())
                break;
            if (c == s[i])
                i++;
        }
        return i >= s.size();
    }
}; */

int main() {                                                                                
    Solution solution;
    string s, t;
    getline(cin, s);
    getline(cin, t);

    // performance check begin
    auto t1 {chrono::high_resolution_clock::now()};
    bool isSubsequence {solution.isSubsequence(s, t)};
    auto t2 {chrono::high_resolution_clock::now()};
    // milliseconds ms
    chrono::duration<double, milli> ms_double {t2 - t1};
    cout << setprecision(17) << ms_double.count() << " ms\n";
    // microseconds us   
    chrono::duration<double, micro> us_double {t2 - t1};
    cout << setprecision(17) << us_double.count() << " us\n";
    // nanoseconds ns   
    chrono::duration<double, nano> ns_double {t2 - t1};
    cout << setprecision(17) << ns_double.count() << " ns\n";    
    // performance check end

    cout << "isSubsequence " << isSubsequence << '\n';
    return 0;   
}