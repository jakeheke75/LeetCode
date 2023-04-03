#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
// performance measure header
#include <iomanip>
#include <chrono>
using namespace std;

// https://leetcode.com/problems/isomorphic-strings/

// sample 4ms solution with maps
/* class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;

        for(int i=0; i<n; i++){
            if(map1[s[i]] != map2[t[i]]){
                return false;
            }
            map1[s[i]] = map2[t[i]] = i+1;
        }
        return true;
    }
}; */

// my proposed solution
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> map_s, map_t;
        string s_unique {s};
        string t_unique {t};
        s_unique.erase(unique(s_unique.begin(), s_unique.end()), s_unique.end());
        t_unique.erase(unique(t_unique.begin(), t_unique.end()), t_unique.end());
        for (char ch : s_unique) {
            int counter {0};
            for (size_t i = 0; (i = s.find(ch, i)) != string::npos; i++) {
                counter++;
            }
            map_s.push_back(counter);
        }
        for (char ch : t_unique) {
            int counter {0};
            for (size_t i = 0; (i = t.find(ch, i)) != string::npos; i++) {
                counter++;
            }
            map_t.push_back(counter);
        }        
        return map_s == map_t ? true : false;
    }
};

int main() {                                                                                
    Solution solution;
    string s, t;
    getline(cin, s);
    getline(cin, t);

    // performance check begin
    auto t1 {chrono::high_resolution_clock::now()};
    bool isIsomorphic {solution.isIsomorphic(s, t)};
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

    cout << isIsomorphic << '\n';
    return 0;   
}