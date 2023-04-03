#include <vector>
#include <iostream>
// https://leetcode.com/problems/running-sum-of-1d-array/
class Solution {
public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        for (std::size_t index = 1; index < nums.size(); index++ )
            nums[index] += nums[index-1];
        return nums; 
    }
};

int main() {
    std::vector<int> nums {3, 1, 2, 10, 1};
    Solution solution;
    nums = solution.runningSum(nums);
    for (int n : nums)
        std::cout << n << " ";
    return 0;
}