#include <iomanip>
#include <chrono>

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto itr{lower_bound(nums.begin(), nums.end(), target)};
        return itr - nums.begin();
    }
};

int main() {                                                                                
    Solution solution;
    vector<int> nums{1,3,5,6};
    int target{7};

    auto t1 {chrono::high_resolution_clock::now()};   
    cout << solution.searchInsert(nums, target) << '\n';
    auto t2 {chrono::high_resolution_clock::now()};
    chrono::duration<double, milli> ms_double {t2 - t1};
    cout << setprecision(17) << ms_double.count() << " ms\n";

    return 0;   
}