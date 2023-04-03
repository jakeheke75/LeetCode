#include <iomanip>
#include <chrono>

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto last{unique(nums.begin(), nums.end())};
        nums.erase(last, nums.end());
        return nums.size();
    }
};

int main() {                                                                                
    Solution solution;
    vector<int> nums{0,0,1,1,1,2,2,3,3,4};
/*     vector<int> nums;
    int n;
    cin >> n;
    int counter{n};    
    while (counter-- > 0) {
        cin >> n;
        nums.push_back(n);
    } */

    auto t1 {chrono::high_resolution_clock::now()};   
    cout << solution.removeDuplicates(nums) << '\n';
    auto t2 {chrono::high_resolution_clock::now()};
    chrono::duration<double, milli> ms_double {t2 - t1};
    cout << setprecision(17) << ms_double.count() << " ms\n";

    return 0;   
}