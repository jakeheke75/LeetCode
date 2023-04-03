#include <iostream>
using namespace std;

// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
class Solution {
public:
    int numberOfSteps(int num) {
        int steps {0};
        while (num != 0) {
            num = num % 2 == 0 ? num / 2 : num - 1;
            steps++;
        }
        return steps;
    }
};

int main() {                                                                                
    Solution solution;
    //int n {123};
    int n;
    cin >> n;
    cout << solution.numberOfSteps(n);
    return 0;   
}