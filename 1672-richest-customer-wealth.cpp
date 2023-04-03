#include <vector>
#include <iostream>
// https://leetcode.com/problems/richest-customer-wealth/
class Solution {
public:
    int maximumWealth(std::vector<std::vector<int>>& accounts) {
        int maximumWealth {0};
        for (auto account : accounts) {
            int accountSum {0};
            for (int bank : account)
                accountSum += bank;
            maximumWealth = accountSum > maximumWealth ? accountSum : maximumWealth;
        }
        return maximumWealth;
    }
};

int main() {
/*     std::vector<std::vector<int>> accounts {{1, 5},
                                            {7, 3},
                                            {3, 5}}; */
/*     std::vector<std::vector<int>> accounts {{1, 2, 3},
                                            {3, 2, 1}}; */
    std::vector<std::vector<int>> accounts {{2, 8, 7},
                                            {7, 1, 3},
                                            {1, 9, 5}};                                                                                   
    Solution solution;
    int maximumWealth {solution.maximumWealth(accounts)};
    std::cout << maximumWealth;
    return 0;   
}