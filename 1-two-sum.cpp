#include <iostream>
#include <vector>
#include <unordered_map>
// performance measure header
#include <iomanip>
#include <chrono>

using namespace std;

// https://leetcode.com/problems/two-sum/

// very nice solution, but it does work only for positive numbers
/* class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> twosum;
        bool found{false};
        for (size_t a=0; a<nums.size() && !found; a++) {
            if (nums[a]>target && target>=0) continue;
            if (nums[a]<target && target<=0) continue;
            for (size_t b=a+1; b<nums.size() && !found; b++) {
                if (nums[b]==target-nums[a]) {
                twosum.push_back(a);
                twosum.push_back(b);
                found = true;
                }
            }
        }
        return twosum;
    }
}; */
// second solution with brute force approach - accepted
/* class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> twosum;
        bool found{false};
        for (size_t a=0; a<nums.size() && !found; a++) {
            for (size_t b=a+1; b<nums.size() && !found; b++) {
                if (nums[b]==target-nums[a]) {
                twosum.push_back(a);
                twosum.push_back(b);
                found = true;
                }
            }
        }
        return twosum;
    }
}; */

// the most performing solution
class Solution {
  public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int, int> map;
        for(int i=0;i<n;i++){
            int comp = target - arr[i];
            if(map.find(comp) != map.end()){
                return {map[comp], i};
            }
            map[arr[i]] = i;
        }
        return {};
    }
};

int main() {
    int numbers, n, target;
    Solution sol;
    vector<int> nums, twosum;
    //nums = {11,7,15,14,13,1,10,9,2};
    //nums = {0,4,3,0};
    //nums = {-1,-2,-3,-4,-5};
    nums = {-3,4,3,90};

/*     cout << "Insert the number of numbers of the vector: ";
    cin >> numbers;
    cout << "Specify each number of the vector: ";
    while (numbers-- > 0) {
        cin >> n;
        nums.push_back(n);
    } */
    cout << "Insert the target number: ";
    cin >> target;    
    // performance measure
    auto t1 {chrono::high_resolution_clock::now()};
    twosum = sol.twoSum(nums, target);
    auto t2 {chrono::high_resolution_clock::now()};
    chrono::duration<double, milli> ms_double {t2 - t1};
    cout << setprecision(17) << ms_double.count() << " ms\n";
    for (int n : twosum)
        cout << n << " ";
    cout << '\n';
    return 0;
}