#include <iomanip>
#include <chrono>

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto last{remove(nums.begin(), nums.end(), val)};
        nums.erase(last, nums.end());
        return nums.size();
    }
};

int main() {                                                                                
    Solution solution;
    int val{2};
    vector<int> nums{0,1,2,2,3,0,4,2};
/*     vector<int> nums;
    int n;
    cin >> n;
    int counter{n};    
    while (counter-- > 0) {
        cin >> n;
        nums.push_back(n);
    } */

    auto t1 {chrono::high_resolution_clock::now()};   
    cout << solution.removeElement(nums, val) << '\n';
    auto t2 {chrono::high_resolution_clock::now()};
    chrono::duration<double, milli> ms_double {t2 - t1};
    cout << setprecision(17) << ms_double.count() << " ms\n";

    return 0;   
}