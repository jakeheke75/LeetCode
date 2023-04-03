#include <iostream>
#include <string>
#include <stack>
// performance measure header
#include <iomanip>
#include <chrono>

using namespace std;

// https://leetcode.com/problems/longest-common-prefix/

class Solution {
  public:
    bool isValid(string s) {
        if (s.size() == 1) return false;
        stack<char> st;
        for (char c : s) {
            switch (c) {
                case '{':
                case '(':
                case '[':
                    st.push(c);
                    break;
                case '}':
                    if (!st.empty() && st.top() == '{') {
                        st.pop();
                        break;
                    }
                    else
                        return false; 
                case ')':
                    if (!st.empty() && st.top() == '(') {
                        st.pop();
                        break;
                    }
                    else
                        return false;  
                case ']':
                    if (!st.empty() && st.top() == '[') {
                        st.pop();
                        break;
                    }
                    else
                        return false;
                default:
                    break;
            }
        }
        return st.empty();
    }
};

int main() {
    string s;
    Solution sol;

    cout << "Insert a string: ";
    cin >> s;

    auto t1{chrono::high_resolution_clock::now()};
    bool valid{sol.isValid(s)};
    auto t2{chrono::high_resolution_clock::now()};
    chrono::duration<double, milli> ms_double{t2 - t1};
    cout << setprecision(17) << ms_double.count() << " ms\n";

    cout << valid << '\n';
    return 0;
}