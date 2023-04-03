#include <iomanip>
#include <chrono>

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

int main() {                                                                                
    Solution solution;
    string str, sub;
    cin >> str;
    cin >> sub;

    auto t1 {chrono::high_resolution_clock::now()};   
    cout << solution.strStr(str, sub) << '\n';
    auto t2 {chrono::high_resolution_clock::now()};
    chrono::duration<double, milli> ms_double {t2 - t1};
    cout << setprecision(17) << ms_double.count() << " ms\n";

    return 0;   
}