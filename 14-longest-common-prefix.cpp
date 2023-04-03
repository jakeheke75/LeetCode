#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
// performance measure header
#include <iomanip>
#include <chrono>

using namespace std;

// https://leetcode.com/problems/longest-common-prefix/

class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs) {
        map<string, int> m;
        for (size_t x = 0; x < strs.size(); ++x)
            for (size_t y = 0; y < strs[x].size(); ++y)
                ++m[strs[x].substr(0, y+1)];
        for (auto itr = m.rbegin(); itr != m.rend(); ++itr)
            if (itr->second == int(strs.size()))
                return itr->first;                
        return {};
    }
};

int main() {
    string s;
    int n;
    vector<string> strs;
    Solution sol;

    cout << "Insert the number of strings: ";
    cin >> n;
    cout << "Insert " << n << " strings: ";
    while (n-- > 0) {
        cin >> s;
        strs.push_back(s);
    }

    auto t1{chrono::high_resolution_clock::now()};
    string ls{sol.longestCommonPrefix(strs)};
    auto t2{chrono::high_resolution_clock::now()};
    chrono::duration<double, milli> ms_double{t2 - t1};
    cout << setprecision(17) << ms_double.count() << " ms\n";

    cout << ls << '\n';
    return 0;
}