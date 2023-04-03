#include <iomanip>
#include <chrono>

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        auto pos = s.find_last_not_of(' ');
        s = s.substr(0, pos+1);
        pos = s.rfind(' ');
        s = s.substr(pos+1);
        return s.size();
    }   
};

int main() {                                                                                
    Solution solution;
    string s = "   fly me   to   the moon  ";
    
    auto t1 = chrono::high_resolution_clock::now();   
    cout << solution.lengthOfLastWord(s) << '\n';
    auto t2 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms_double = t2 - t1;
    cout << setprecision(17) << ms_double.count() << " ms\n";

    return 0;   
}