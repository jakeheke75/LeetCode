#include <iomanip>
#include <chrono>

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // first attempt: converting the vector in an integer is not the right approach because of
    // the constraint 1 <= digits.length <= 100
/*     vector<int> plusOne(vector<int>& digits) {
        long long number{0};
        for (auto& n : digits)
            number = number * 10 +n;
        string s{to_string(number+1)};
        digits.clear();
        for (auto& c : s)
            digits.push_back(c-'0');
        return digits;
    }  */  

    // second attempt: looping the array in reverse order and increment all the digits
    // not accepted in LeetCode because of the clang AddressSanitizer: heap-buffer-overflow on address
/*     vector<int> plusOne(vector<int>& digits) {
        bool increment {true}, newVector {false};
        for (auto itr=digits.rbegin(); itr<=digits.rend() && increment; ++itr) {
            if (*itr == 9 && itr != digits.rend())
                *itr = 0;
            //else if (*itr == 0 && itr == digits.rend())
            else if (itr == digits.rend())
                newVector = true;
            else {
                *itr += 1;
                increment = false;
            }
        }
        if (!newVector)
            return digits;
        else {
            vector<int> plusOne;
            plusOne.push_back(1);
            for (int i : digits)
                plusOne.push_back(i);
            return plusOne;
        }
    } */

    // third approach by using normal iterator and not reverse iterator
/*     vector<int> plusOne(vector<int>& digits) {
        bool increment {true}, newVector {false};
        for (auto itr=digits.end()-1; itr>=digits.begin() && increment; --itr) {
            if (*itr == 9 && itr != digits.begin())
                *itr = 0;
            else if (*itr == 9 && itr == digits.begin()) {
                *itr = 0;
                newVector = true;
            } else {
                *itr += 1;
                increment = false;
            }
        }
        if (!newVector)
            return digits;
        else {
            vector<int> plusOne;
            plusOne.push_back(1);
            for (int i : digits)
                plusOne.push_back(i);
            return plusOne;
        }
    }    */ 

    // fourth approach by using normal iterator and insert instruction
    vector<int> plusOne(vector<int>& digits) {
        bool increment {true};
        for (auto itr=digits.end()-1; itr>=digits.begin() && increment; --itr) {
            if (*itr == 9 && itr != digits.begin())
                *itr = 0;
            else if (*itr == 9 && itr == digits.begin()) {
                *itr = 0;
                digits.insert(itr, 1);
                increment = false;
            } else {
                *itr += 1;
                increment = false;
            }
        }
        return digits;
    }  
};

int main() {                                                                                
    Solution solution;
    //vector<int> digits {7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,6};
    //vector<int> digits {7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,9};
    //vector<int> digits {9,9};
    //vector<int> digits {9};
    //vector<int> digits {1,2,4};
    //vector<int> digits {4,3,2,1};
    vector<int> digits {1,9,9};

    vector<int> plusOne;
    
    auto t1 = chrono::high_resolution_clock::now();   
    plusOne = solution.plusOne(digits);
    auto t2 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms_double = t2 - t1;
    cout << setprecision(17) << ms_double.count() << " ms\n";

    for (auto n : plusOne)
        cout << n << " ";
    return 0;   
}