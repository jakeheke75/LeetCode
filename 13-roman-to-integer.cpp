#include <iostream>
#include <string>
#include <unordered_map>
// performance measure header
#include <iomanip>
#include <chrono>

using namespace std;

// https://leetcode.com/problems/roman-to-integer/

class Solution {
  public:
    // my solution
    int romanToInt(string s) {
        int integer{0};
        unordered_map<char,int> m{
            {'C',100},
            {'D',500},
            {'I',1},
            {'L',50},
            {'M',1000},
            {'V',5},
            {'X',10}};
        for (auto itr = s.end()-1; itr >= s.begin(); --itr) {
            auto curr{m.find(*itr)};
            auto prev{m.find(*(itr+1))};
            if ((*itr == 'I' && (*(itr+1) == 'V' || *(itr+1) == 'X')) ||
                (*itr == 'X' && (*(itr+1) == 'L' || *(itr+1) == 'C')) ||
                (*itr == 'C' && (*(itr+1) == 'D' || *(itr+1) == 'M'))) {
                    integer = integer - curr->second;
            }
            else {
                integer = integer + curr->second;
            }
        }        
        return integer;
    }
    // the LeetCode best performing solution
    int romanToIntb(string s) {
        int res = 0;
        char prev = '\0';
        for( char c : s) {
            switch(c) {
                case 'I':
                    res += 1;
                    break;
                case 'V':
                    res += 5;
                    if(prev == 'I') res -= 2;
                    break;
                case 'X':
                    res += 10;
                    if(prev == 'I') res -= 2;
                    break;
                case 'L':
                    res += 50;
                    if(prev == 'X') res -= 20;
                    break;
                case 'C':
                    res += 100;
                    if(prev == 'X') res -= 20;
                    break;
                case 'D':
                    res += 500;
                    if(prev == 'C') res -= 200;
                    break;
                case 'M':
                    res += 1000;
                    if(prev == 'C') res -= 200;
                    break;
            }
            prev = c;
        }
        return res;
    }
};

int main() {
    string s;
    Solution sol;
    cout << "Insert a Roman number: ";
    cin >> s;    

    auto t1{chrono::high_resolution_clock::now()};
    int i{sol.romanToIntb(s)};
    auto t2{chrono::high_resolution_clock::now()};
    chrono::duration<double, milli> ms_double{t2 - t1};
    cout << setprecision(17) << ms_double.count() << " ms\n";

    cout << i << '\n';
    return 0;
}