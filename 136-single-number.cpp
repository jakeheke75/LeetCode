#include <iomanip>
#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
    public:
    // my solution
    int singleNumber(std::vector<int>& nums) {
        // corner case vector lenght = 1
        if (nums.size() == 1)
            return nums[0];
        // all other cases
        std::sort(nums.begin(), nums.end());
        for (size_t i=0; i<nums.size(); i=i+2) {
            if (i+1<nums.size() && nums[i]==nums[i+1])
                continue;
            else
                return nums[i];
        }
        return EXIT_FAILURE;
    }
    // LeetCode best performing solution
    // interesting solution with bitwise operator xor
    int singleNumber2(std::vector<int>& nums) {
        int c = 0;
        for (size_t i=0; i<nums.size(); ++i)
            c = c ^ nums[i];
        return c;
    }   
};

int main() {

    //std::vector<int> nums {2,2,1};
    //std::vector<int> nums {4,1,2,1,2};
    std::vector<int> nums {4,1,2,1,4};
    //std::vector<int> nums {1,2,1};

    Solution sol;

    auto t1 = std::chrono::high_resolution_clock::now();   
    int s = sol.singleNumber(nums);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double = t2 - t1;
    std::cout << std::setprecision(17) << ms_double.count() << " ms\n";
    
    std::cout << s << '\n';
    return 0;

}