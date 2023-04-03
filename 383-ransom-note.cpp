#include <vector>
#include <iostream>
#include <string>
using namespace std;

// https://leetcode.com/problems/ransom-note/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (char c : ransomNote) {
            size_t pos {magazine.find(c)};
            if (pos != string::npos)
                magazine.erase(pos, 1);
            else
                return false;
        }
        return true;
    }
};

int main() {                                                                                
    Solution solution;
    string ramsonNote, magazine;
    getline(cin, ramsonNote);
    getline(cin, magazine);
    bool canConstruct {solution.canConstruct(ramsonNote, magazine)};
    cout << canConstruct << '\n';
    return 0;   
}