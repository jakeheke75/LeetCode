#include <vector>
#include <iostream>
#include <string>
using namespace std;

// https://leetcode.com/problems/fizz-buzz/
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0)
                answer.push_back("FizzBuzz");
            else if (i % 3 == 0)
                answer.push_back("Fizz");
            else if (i % 5 == 0)
                answer.push_back("Buzz");
            else
                answer.push_back(to_string(i));
        }
        return answer;
    }
};

int main() {                                                                                
    Solution solution;
    int n;
    cin >> n;
    vector<string> answer {solution.fizzBuzz(n)};
    for (auto c : answer)
        cout << c;
    return 0;   
}